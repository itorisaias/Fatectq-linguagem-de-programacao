/*
# Revisão de Lógica

Crie um programa em C que leia duas notas de um aluno e exiba:

- Nota final menor que 6: imprima "Precisa estudar mais"
- Nota final maior ou igual a 6 e menor que 8: imprima "Está na média"
- Nota final maior que 8 e menor que 10: imprima "Parabéns"
- Maior nota entre elas

---

A partir do programa anterior, modifique-o para ler quatro notas, e agora exiba a maior nota também.
*/
#include <stdio.h>

int main() {
    float notas[4], media, maior;

    // entrada
    for (int nota = 0; nota < 4; nota++) {
        printf("Nota %d: ", nota + 1);
        scanf("%f", &notas[nota]);
    }

    // processamento - medias
    media = (notas[0] + notas[1] + notas[2] + notas[4]) / 4;
    printf("Media: %.2f\n", media);
    // processamento - resultado
    if (media < 6) {
        printf("Precisa estudar mais\n");
    } else if (media < 8) {
        printf("Está na média\n");
    } else {
        printf("Parabéns");
    }
    // processamento - maior nota
    maior = notas[0];
    for (int nota = 0; nota < 4; nota++)
    {
        if (notas[nota] > maior) {
            maior = notas[nota];
        }
    }
    

    return 0;
}
