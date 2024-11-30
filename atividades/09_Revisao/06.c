
/*
A partir do programa anterior, crie uma estrutura para representar um aluno com nome, idade e nota. Leia os dados de dois alunos, armazene-os em um array de estruturas e exiba as informações.

Cadastrar aluno
Imprimir aluno
Ler notas
Verificar situacao
Encontrar maior nota
*/
#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    float notas[4];
    float media;
} Aluno;

Aluno cadastrarAluno();
void imprimirAluno(Aluno aluno);
void lerNotas(float notas[4]);
void verificaSituacao(float notas[4]);
void encontrarMaiorNota(float notas[4]);

Aluno alunos[2];

int main () {
    FILE *arq = fopen("dados.csv", "w");

    fprintf(arq, "idade,nome,media\n");

    for (int i = 0; i < 2; i++)
    {
        Aluno aluno = cadastrarAluno();
        alunos[i] = aluno;
        imprimirAluno(aluno);
        verificaSituacao(aluno.notas);
        encontrarMaiorNota(aluno.notas);

        fprintf(arq, "%d,%s,%f\n", aluno.idade, aluno.nome, aluno.media);
    }

    fclose(arq);
    
    return 0;
}

Aluno cadastrarAluno() {
    Aluno novoAluno;
    setbuf(stdin, NULL);
    printf("Digite o nome do aluno: ");
    fgets(novoAluno.nome, sizeof(novoAluno.nome), stdin);
    novoAluno.nome[strlen(novoAluno.nome) - 1] = '\0';

    printf("Digite sua idade: ");
    scanf("%d", &novoAluno.idade);

    lerNotas(novoAluno.notas);

    return novoAluno;
}
void imprimirAluno(Aluno aluno) {
    printf("Nome do aluno: %s\n", aluno.nome);
    printf("Idade %d\n", aluno.idade);
    for (int i = 0; i < 4; i++)
    {
        printf("Nota %d: %f \n", i + 1, aluno.notas[i]);
    }
}
void lerNotas(float notas[4]) {
    for (int i = 0; i < 4; i++)
    {
        printf("Digite a nota: ");
        scanf("%f", &notas[i]);
    }
}
void verificaSituacao(float notas[4]) {
    float media = 0;
    
    for (int i = 0; i < 4; i++)
    {
        media += notas[i];
    }
    
    media = media / 2;

    if (media < 6) {
        printf("Precisa estudar mais\n");
    } else if (media < 8) {
        printf("Está na média\n");
    } else {
        printf("Parabéns\n");
    }
}
void encontrarMaiorNota(float notas[4]) {
    float maior = notas[0];
    for (int nota = 1; nota < 4; nota++)
    {
        if (notas[nota] > maior) {
            maior = notas[nota];
        }
    }

    printf("Maior nota: %f\n", maior);
}