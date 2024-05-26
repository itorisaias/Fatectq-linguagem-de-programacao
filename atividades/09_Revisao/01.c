#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[50];
    int idade;
    float notas[4];
} Aluno;

void cadastrarAluno(Aluno *aluno);
void imprimirAluno(Aluno aluno);
void lerNotas(float notas[4]);
float calcularMedia(float notas[4]);
void verificarSituacao(float media);
float encontrarMaiorNota(float notas[4]);

int main()
{
    float media, maior;

    for (int aluno = 0; aluno < 2; aluno++)
    {
        Aluno novoAluno;
        printf("Aluno %d\n", aluno + 1);
        cadastrarAluno(&novoAluno);

        imprimirAluno(novoAluno);

        media = calcularMedia(novoAluno.notas);
        printf("Media: %.2f\n", media);

        verificarSituacao(media);
        maior = encontrarMaiorNota(novoAluno.notas);
        printf("Maior nota: %.2f\n", maior);
    }

    return 0;
}

void cadastrarAluno(Aluno *aluno)
{
    setbuf(stdin, NULL);
    printf("Nome: ");
    fgets(aluno->nome, 50, stdin);
    aluno->nome[strcspn(aluno->nome, "\n")] = '\0';

    printf("Idade: ");
    scanf("%d", &aluno->idade);

    lerNotas(aluno->notas);
}
void imprimirAluno(Aluno aluno)
{
    printf("Nome: %s\n", aluno.nome);
    printf("Idade: %d\n", aluno.idade);
}
void lerNotas(float notas[4])
{
    // entrada
    for (int nota = 0; nota < 4; nota++)
    {
        printf("Nota %d: ", nota + 1);
        scanf("%f", &notas[nota]);
    }
}
float calcularMedia(float notas[4])
{
    // processamento - medias
    float media, soma = 0;
    for (int nota = 0; nota < 4; nota++)
    {
        soma += notas[nota];
    }
    media = soma / 4;
    return media;
}
void verificarSituacao(float media)
{
    // processamento - resultado
    if (media < 6)
    {
        printf("Precisa estudar mais\n");
    }
    else if (media < 8)
    {
        printf("Está na média\n");
    }
    else
    {
        printf("Parabéns\n");
    }
}
float encontrarMaiorNota(float notas[4])
{
    // processamento - maior nota
    float maior = notas[0];
    for (int nota = 0; nota < 4; nota++)
    {
        if (notas[nota] > maior)
        {
            maior = notas[nota];
        }
    }
    return maior;
}
