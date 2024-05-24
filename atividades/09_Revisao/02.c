/*
# Revisão de Vetor

A partir do programa anterior, modifique-o para ler quatro notas, e agora exiba a maior nota também.
*/

#include <stdio.h>

int main() {
    float notas[4], maior, media;

    for (int nota = 0; nota < 4; nota++)
    {
        printf("Nota %d: ", nota + 1);
        scanf("%f", &notas[nota]);
    }

    media = (notas[0] + notas[1] + notas[2] + notas[3]) / 4;
    printf("Media: %.2f\n", media);
    if (media < 6) {
        printf("Precisa estudar mais\n");
    } else if (media < 8) {
        printf("Está na média\n");
    } else {
        printf("Parabéns\n");
    }

    maior = notas[0];
    for (int nota = 0; nota < 4; nota++)
    {
        if (notas[nota] > maior) {
            maior = notas[nota];
        }
    }
    printf("Maior nota é: %.2f\n", maior);

    return 0;
}