#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10
#define FILENAME "films.bin"

typedef struct
{
    int id;
    char title[200];
} Content;

Content films[TAM];
int quant = 0;

void newFilm();
void listFilm();
void updateFilm();
void deleteFilm();
void saveFile();
void readFile();
void clearScreen();

int main()
{
    readFile();

    int opc;
    do
    {
        printf("\nOptions: \n");
        printf("\t0 - EXIT\n\t1 - CREATE\n\t2 - READ\n\t3 - UPDATE\n\t4 - DELETE\n\n\t");
        if (scanf("%d%*c", &opc) != 1)
        {
            printf("Entrada inválida. Por favor, insira um número.\n");
            while (getchar() != '\n')
                ; // Limpa o buffer de entrada
            continue;
        }
        clearScreen();

        switch (opc)
        {
        case 0:
            printf("Bye!\n");
            saveFile();
            break;
        case 1:
            newFilm();
            break;
        case 2:
            listFilm();
            break;
        case 3:
            updateFilm();
            break;
        case 4:
            deleteFilm();
            break;
        default:
            printf("Opção inválida\n");
            break;
        }
    } while (opc != 0);

    return 0;
}

void newFilm()
{
    if (quant >= TAM)
    {
        printf("Limite de filmes atingido!\n");
        return;
    }
    Content newFilm;
    newFilm.id = quant;
    printf("Título do filme: ");
    if (scanf("%199[^\n]%*c", newFilm.title) != 1)
    {
        printf("Erro na leitura do título.\n");
        return;
    }
    films[quant] = newFilm;
    printf("Novo filme adicionado!\n");
    quant++;
}

void listFilm()
{
    printf("Lista de filmes: \n\n");
    printf("Filme [id]\n");
    for (int i = 0; i < quant; i++)
        printf("Filme [%d]: %s\n", films[i].id, films[i].title);
}

void updateFilm()
{
    listFilm();
    int filmId;
    printf("\nDigite o ID do filme: ");
    if (scanf("%d%*c", &filmId) != 1)
    {
        printf("Entrada inválida.\n");
        return;
    }
    if (filmId >= 0 && filmId < quant)
    {
        printf("Título do filme: ");
        if (scanf("%199[^\n]%*c", films[filmId].title) != 1)
        {
            printf("Erro na leitura do título.\n");
            return;
        }
        printf("Filme atualizado!\n");
    }
    else
    {
        printf("ID inválido!\n");
    }
}

void deleteFilm()
{
    listFilm();
    int filmId;
    printf("\nDigite o ID do filme: ");
    if (scanf("%d%*c", &filmId) != 1)
    {
        printf("Entrada inválida.\n");
        return;
    }
    if (filmId >= 0 && filmId < quant)
    {
        for (int i = filmId; i < quant - 1; i++)
        {
            films[i] = films[i + 1];
            films[i].id = i;
        }
        quant--;
        printf("Filme removido!\n");
    }
    else
    {
        printf("ID inválido!\n");
    }
}

void saveFile()
{
    FILE *file = fopen(FILENAME, "wb");
    if (file == NULL)
    {
        printf("Falha ao abrir o arquivo!\n");
        return;
    }
    fwrite(&quant, sizeof(int), 1, file);
    fwrite(films, sizeof(Content), quant, file);
    fclose(file);
    printf("Arquivo salvo!\n");
}

void readFile()
{
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL)
    {
        printf("Falha ao abrir o arquivo!\n");
        return;
    }
    fread(&quant, sizeof(int), 1, file);
    fread(films, sizeof(Content), quant, file);
    fclose(file);
    printf("Arquivo carregado!\n");
}

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
