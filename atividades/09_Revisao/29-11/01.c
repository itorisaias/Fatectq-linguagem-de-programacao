#include <stdio.h>

void main() {
    float nota1, nota2;
    printf("Digite a nota 1 e nota 2 separadas por espaco: ");
    scanf("%f %f", &nota1, &nota2);

    float media = (nota1 + nota2) / 2;

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

    if (nota1 > nota2) {
        printf("Nota 1 e maior\n");
    } else if (nota2 > nota1) {
        printf("Nota 2 e maior\n");
    } else {
        printf("As notas sao iguais\n");
    }
}