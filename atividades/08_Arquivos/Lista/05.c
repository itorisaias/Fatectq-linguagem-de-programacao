#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[50];
    float notas[4];
    float media;
} Aluno;

int pegarQuantidade();
void carregarAlunos(int quantidade, Aluno alunos[quantidade]);
void ordenarAlunos(int quantidade, Aluno alunos[quantidade]);
void salvarAlunosOrdenado(int quantidade, Aluno alunos[quantidade]);

int main()
{
    int quantidade = pegarQuantidade();
    if (quantidade <= 0)
    {
        printf("Erro ao obter a quantidade de alunos\n");
        return 1;
    }
    Aluno alunos[quantidade];
    carregarAlunos(quantidade, alunos);
    ordenarAlunos(quantidade, alunos);
    salvarAlunosOrdenado(quantidade, alunos);
    return 0;
}

int pegarQuantidade()
{
    int quantidade;
    FILE *file = fopen("alunos.csv", "r");
    if (file == NULL)
    {
        perror("Erro ao abrir o arquivo alunos.csv");
        return -1;
    }
    fscanf(file, "%d", &quantidade);
    fclose(file);
    return quantidade;
}

void carregarAlunos(int quantidade, Aluno alunos[quantidade])
{
    FILE *file = fopen("alunos.csv", "r");
    if (file == NULL)
    {
        perror("Erro ao abrir o arquivo alunos.csv");
        return;
    }
    fscanf(file, "%*d"); // Ignora a primeira linha que contém a quantidade de registros
    for (int i = 0; i < quantidade; i++)
    {
        Aluno aluno;
        fscanf(file, " %[^,],%f,%f,%f,%f", aluno.nome, &aluno.notas[0], &aluno.notas[1], &aluno.notas[2], &aluno.notas[3]);
        aluno.media = (aluno.notas[0] + aluno.notas[1] + aluno.notas[2] + aluno.notas[3]) / 4;
        alunos[i] = aluno;
    }
    fclose(file);
}

void ordenarAlunos(int quantidade, Aluno alunos[quantidade])
{
    for (int i = 0; i < quantidade - 1; i++)
    {
        for (int j = 0; j < quantidade - i - 1; j++)
        {
            if (alunos[j].media < alunos[j + 1].media)
            { // Ordem decrescente
                Aluno temp = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = temp;
            }
        }
    }
}

void salvarAlunosOrdenado(int quantidade, Aluno alunos[quantidade])
{
    FILE *file = fopen("alunos_ordenados.csv", "w");
    if (file == NULL)
    {
        perror("Erro ao criar o arquivo alunos_ordenados.csv");
        return;
    }
    fprintf(file, "%d\n", quantidade);
    for (int i = 0; i < quantidade; i++)
    {
        Aluno aluno = alunos[i];
        fprintf(file, "%s,%.2f,%.2f,%.2f,%.2f,%.2f\n", aluno.nome, aluno.notas[0], aluno.notas[1], aluno.notas[2], aluno.notas[3], aluno.media);
    }
    fclose(file);
}
