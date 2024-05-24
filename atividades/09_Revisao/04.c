/*
# Revisão de Função

A partir do programa anterior, utilize funções para ler as notas, verificar se o aluno foi aprovado e apresentar a maior nota de cada aluno.

- Ler notas
- Calcular media
- Verificar situacao
- Encontrar maior nota
*/

#include <stdio.h>

void lerNotas(float notas[4]);
float calcularMedia(float notas[4]);
void verificarSituacao(float media);
float encontrarMaiorNota(float notas[4]);

int main() {
    float notas[2][4], maior, media;

    for (int aluno = 0; aluno < 2; aluno++)
    {
        printf("Aluno %d\n", aluno + 1);
        lerNotas(notas[aluno]);

        media = calcularMedia(notas[aluno]);
        printf("Media: %.2f\n", media);
        verificarSituacao(media);

        maior = encontrarMaiorNota(notas[aluno]);
        printf("Maior nota é: %.2f\n\n", maior);
    }
    
    return 0;
}


void lerNotas(float notas[4]) {
    for (int nota = 0; nota < 4; nota++)
    {
        printf("Nota %d: ", nota + 1);
        scanf("%f", &notas[nota]);
    }
}

float calcularMedia(float notas[4]) {
    float media = 0;
    for (int nota = 0; nota < 4; nota++)
    {
        media += notas[nota];
    }
    return media / 4;
}

void verificarSituacao(float media) {
    if (media < 6) {
        printf("Precisa estudar mais\n");
    } else if (media < 8) {
        printf("Está na média\n");
    } else {
        printf("Parabéns\n");
    }
}

float encontrarMaiorNota(float notas[4]) {
    float maior = notas[0];
    for (int nota = 0; nota < 4; nota++)
    {
        if (notas[nota] > maior) {
            maior = notas[nota];
        }
    }
    return maior;
}

