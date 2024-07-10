#include <stdio.h>
typedef struct
{
    char nome[100];
    int notas[4];
} Aluno;
int main()
{
    FILE *file = fopen("alunos.csv", "r");
    if (file == NULL)
        return 1;

    int count = 0;
    Aluno aluno;

    while (
        fscanf(
            file,
            "%[^,],%d,%d,%d,%d\n",
            aluno.nome,
            &aluno.notas[0],
            &aluno.notas[1],
            &aluno.notas[2],
            &aluno.notas[3]) == 5)
    {
        printf("Nome: %s\n", aluno.nome);
    }

    fclose(file);
    return 0;
}