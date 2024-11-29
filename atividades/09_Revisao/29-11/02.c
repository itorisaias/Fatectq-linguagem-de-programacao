#include <stdio.h>

#define QTD_NOTAS 4

void main() {
    float notas[QTD_NOTAS], total_notas;

    for (int i = 0; i < QTD_NOTAS; i++) {
        printf("Digite a nota %d: ", i + 1);
        scanf("%f", &notas[i]);
    }

    total_notas = 0;
    for (int i = 0; i < QTD_NOTAS; i++)
    {
        total_notas += notas[i];
    }
    float media = total_notas / QTD_NOTAS;
    printf("Media %.3f\n", media);
    
    if (media < 6) {
        printf("Precisa estudar mais\n");
    } else if (media >= 6 && media <= 8) {
        printf("Esta na media\n");
    } else if (media > 8 && media <= 10) {
        printf("Parabens\n");
    } else {
        printf("Voce e o bixao\n");
    }

    float maior = notas[0];
    for (int i = 1; i < QTD_NOTAS; i++)
    {
        if (notas[i] > maior) {
            maior = notas[i];
        }
    }
    
    printf("Maior nota %f", maior);
}