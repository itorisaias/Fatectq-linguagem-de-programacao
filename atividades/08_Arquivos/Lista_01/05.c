/*
Ordenação de Dados em Arquivo CSV
Crie um programa que leia um arquivo CSV chamado alunos.csv contendo nomes e notas de alunos (utilize estrutura para simplificar). Ordene os dados por média (em ordem decrescente) e salve o resultado em um novo arquivo chamado alunos_ordenados.csv.
*/
#include <stdio.h>

typedef struct {
    char nome[100];
    int notas[4], media;
} Aluno;

int pegarCount();
void carregarAlunos(int count, Aluno alunos[count]);
void imprimirAlunos(int count, Aluno alunos[count]);
void ordenarAluno(int count, Aluno alunos[count]);

int main() {
    int count = pegarCount();
    Aluno alunos[count];

    carregarAlunos(count, alunos);
    imprimirAlunos(count, alunos);
    ordenarAluno(count, alunos);
    imprimirAlunos(count, alunos);

    return 0;
}

int pegarCount() {
    int count;
    FILE *file = fopen("alunos.csv", "r");
    if (file == NULL) {
        return 0;
    }
    fscanf(file, "%d\n", &count);
    fclose(file);
    return count;
}
void carregarAlunos(int count, Aluno alunos[count]) {
    FILE *file = fopen("alunos.csv", "r");
    if (file == NULL) {
        return;
    }

    fscanf(file, "%*d\n");

    for (int i = 0; i < count; i++)
    {
        Aluno aluno;
        // Itor Isaias,6,4,9,8
        fscanf(
            file,
            "%[^,],%d,%d,%d,%d\n",
            aluno.nome,
            &aluno.notas[0],
            &aluno.notas[1],
            &aluno.notas[2],
            &aluno.notas[3]
        );
        aluno.media = (aluno.notas[0] + aluno.notas[1] + aluno.notas[2] + aluno.notas[3]) / 4; 
        alunos[i] = aluno;
    }
    
    fclose(file);
}
void imprimirAlunos(int count, Aluno alunos[count]) {
    FILE *file = fopen("alunos.csv", "r");
    if (file == NULL) {
        return;
    }

    for (int i = 0; i < count; i++)
    {
        printf("Aluno %d\n", i + 1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Media: %d\n", alunos[i].media);;
    }

    fclose(file);
}
void ordenarAluno(int count, Aluno alunos[count]) {
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (alunos[j].media < alunos[j + 1].media) {
                Aluno aux = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = aux;
            }
        }
    }
}