#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    int dia, mes, ano;
} Contato;

void imprimir(Contato **c, int quant)
{
    printf("\n\tLista de Contatos:\n");
    printf("\t----------------------\n");
    for (int i = 0; i < quant; i++)
    {
        printf("\t%d = %2d/%2d/%4d\t %s\n", i + 1, c[i]->dia, c[i]->mes, c[i]->ano, c[i]->nome);
    }
    printf("\t----------------------\n");
}

int cadastrarContato(Contato **c, int quant, int tam)
{
    if (quant < tam)
    {
        Contato *contato = malloc(sizeof(Contato));
        setbuf(stdin, NULL);
        printf("\nDigite o nome: ");
        scanf("%50[^\n]%*c", contato->nome);
        printf("Digite a data nascimento (dd/mm/aaaa): ");
        scanf("%d/%d/%d", &contato->dia, &contato->mes, &contato->ano);
        c[quant] = contato;
        return 1;
    }
    else
    {
        printf("\n\tAgenda cheia!\n");
        return 0;
    }
}

void alterarContato(Contato **c, int quant)
{
    int id;
    imprimir(c, quant);
    printf("\n\tDigite o codigo do contato que deseja alterar: ");
    scanf("%d", &id);
    id--;
    if (id >= 0 && id < quant)
    {
        Contato *contato = malloc(sizeof(Contato));
        setbuf(stdin, NULL);
        printf("\nDigite o nome: ");
        scanf("%50[^\n]%*c", contato->nome);
        printf("Digite a data nascimento (dd/mm/aaaa): ");
        scanf("%d/%d/%d", &contato->dia, &contato->mes, &contato->ano);
        c[id] = contato;
    }
    else
    {
        printf("\n\tCodigo invalido!\n");
    }
}

void salvar(Contato **c, int quant, char arq[]) {
    FILE *file = fopen(arq, "w");
    if (file == NULL) {
        printf("\n\tNão foi possivel criar o arquivo!");
        return;
    }
    fprintf(file, "%d\n", quant);
    for (int i = 0; i < quant; i++)
    {
        fputs(c[i]->nome, file);
        fputc('\n', file);
        fprintf(file, "%d %d %d\n", c[i]->dia, c[i]->mes, c[i]->ano);
    }
    fclose(file);
}
int ler(Contato **c, char arq[]) {
    int quant;
    Contato *contato = malloc(sizeof(Contato));
    FILE *file = fopen(arq, "r");
    if (file == NULL) {
        printf("Erro ao abrir arquivo!");
        return 0;
    }
    fscanf(file, "%d\n", &quant);
    for (int i = 0; i < quant; i++)
    {
        fgets(contato->nome, 50, file);
        fscanf(file, "%d %d %d\n", &contato->dia, &contato->mes, &contato->ano);
        c[i] = contato;
        contato = malloc(sizeof(Contato));
    }
    fclose(file);
    return quant;
}

int main()
{
    Contato *agenda[50];
    char arquivo[] = "agenda.txt";
    int opc, tam = 50, quant = 0;

    do
    {
        printf("\n\t0 - Sair");
        printf("\n\t1 - Cadastrar");
        printf("\n\t2 - Alterar");
        printf("\n\t3 - Imprimir");
        printf("\n\t4 - Salvar");
        printf("\n\t5 - Ler");
        printf("\n\t");
        scanf("%d%*c", &opc);
        switch (opc)
        {
        case 0:
            printf("\n\tBye!");
            break;
        case 1:
            quant += cadastrarContato(agenda, quant, tam);
            break;
        case 2:
            alterarContato(agenda, quant);
            break;
        case 3:
            imprimir(agenda, quant);
            break;
        case 4:
            salvar(agenda, quant, arquivo);
            break;
        case 5:
            quant = ler(agenda, arquivo);
            break;
        default:
            printf("\n\tOpcao Invalida!");
            break;
        }
    } while (opc != 0);

    imprimir(agenda, quant);
    quant += cadastrarContato(agenda, quant, tam);

    return 0;
}