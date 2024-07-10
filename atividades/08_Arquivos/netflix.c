/*
CRUD de Sistema de filmes.

- CREATE
- READ
- UPDATE
- DELETE
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_R 100
#define FILENAME "netflix.bin"

void create();
void read();
void update();
void delete();
void export();
void save();
void restore();
void clear();

typedef struct
{
    char titulo[100];
} Filme;

Filme catalogo[MAX_R];
int count = 0;

int main()
{
    int opc;
    restore();
    do
    {
        printf("\nOpções:\n");
        printf("0 - Sair\n");
        printf("1 - CREATE\n");
        printf("2 - READ\n");
        printf("3 - UPDATE\n");
        printf("4 - DELETE\n");
        printf("5 - EXPORT CSV\n");
        printf("Escolha uma opção: ");
        if (scanf("%d", &opc) != 1)
        {
            while (getchar() != '\n')
                ;
            printf("Entrada inválida!\n");
            continue;
        }
        getchar();

        clear();

        switch (opc)
        {
        case 0:
            printf("Bye!\n");
            save();
            break;
        case 1:
            create();
            break;
        case 2:
            read();
            break;
        case 3:
            update();
            break;
        case 4:
            delete();
            break;
        case 5:
            export();
            break;
        default:
            printf("Opção Inválida!\n");
            break;
        }
    } while (opc != 0);

    return 0;
}

void create()
{
    if (count >= MAX_R)
    {
        printf("Capacidade máxima atingida. Não é possível adicionar mais filmes.\n");
        return;
    }

    Filme novoFilme;
    printf("Título: ");
    fgets(novoFilme.titulo, sizeof(novoFilme.titulo), stdin);
    novoFilme.titulo[strcspn(novoFilme.titulo, "\n")] = 0;
    catalogo[count] = novoFilme;
    count++;
    printf("Filme adicionado!\n");
}

void read()
{
    if (count == 0)
    {
        printf("Nenhum filme no catálogo.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        printf("[%d] Título: %s\n", i, catalogo[i].titulo);
    }
}

void update()
{
    if (count == 0)
    {
        printf("Nenhum filme para atualizar.\n");
        return;
    }

    read();
    int posicao;
    printf("Digite a posição do filme a ser atualizado: ");
    if (scanf("%d", &posicao) != 1 || posicao < 0 || posicao >= count)
    {
        while (getchar() != '\n')
            ;
        printf("Posição inválida!\n");
        return;
    }
    getchar();

    printf("Digite o novo título: ");
    fgets(catalogo[posicao].titulo, sizeof(catalogo[posicao].titulo), stdin);
    catalogo[posicao].titulo[strcspn(catalogo[posicao].titulo, "\n")] = 0; // Remove o newline
    printf("Registro atualizado!\n");
}

void delete()
{
    if (count == 0)
    {
        printf("Nenhum filme para deletar.\n");
        return;
    }

    read();
    int posicao;
    printf("Digite a posição do filme a ser removido: ");
    if (scanf("%d", &posicao) != 1 || posicao < 0 || posicao >= count)
    {
        while (getchar() != '\n')
            ;
        printf("Posição inválida!\n");
        return;
    }
    getchar();

    for (int i = posicao; i < count - 1; i++)
    {
        catalogo[i] = catalogo[i + 1];
    }
    count--;
    printf("Filme removido!\n");
}

void export() {
    FILE *file = fopen("filmes.csv", "w");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo para exportar");
        return;
    }
    fprintf(file, "id,title\n");
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s\n", i, catalogo[i].titulo);
    }
    fclose(file);
    printf("Catálogo exportado para 'filmes.csv'!\n");
}

void save()
{
    FILE *file = fopen(FILENAME, "wb");
    if (file == NULL)
    {
        perror("Erro ao abrir o arquivo para salvar");
        return;
    }
    fwrite(catalogo, sizeof(Filme), count, file);
    fclose(file);
    printf("Arquivo salvo!\n");
}

void restore()
{
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL)
    {
        perror("Erro ao abrir o arquivo para restaurar");
        return;
    }
    Filme filmeTemp;
    while (fread(&filmeTemp, sizeof(Filme), 1, file)) // enquanto tem registro carrega
    {
        catalogo[count] = filmeTemp;
        count++;
    }
    fclose(file);
    printf("Sistema carregado com %d filme(s).\n", count);
}

void clear()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}