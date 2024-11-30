#include <stdio.h>

typedef struct {
    char nome[50];
    int idade;
    float notas[4];
    float media;
} Aluno;

int main() {
    FILE *arq = fopen("dados.csv", "r");

    // idade,nome,nota
    // 
    fscanf(arq, "%s,%s,%s\n");

    Aluno aluno1, aluno2;
    fscanf(arq, "%d,%[^,],%f\n", aluno1.idade, aluno1.nome, aluno1.media);
    fscanf(arq, "%d,%[^,],%f\n", aluno2.idade, aluno2.nome, aluno2.media);
    fclose(arq);

    return 0;
}