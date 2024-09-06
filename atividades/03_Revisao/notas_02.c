// Leia N  notas e apresente
// a media
// a menor nota,
// a maior nota

#include <stdio.h>

int main() {
    float n, media;
    float menor, maior;

    printf("Digite a quantidade de notas: ");
    scanf("%f", &n);

    for (int i = 0; i < n; i++) {
        float nota;
        printf("Digite a nota %d: ", i + 1);
        scanf("%f", &nota);

        media += nota;

        if (i == 0) {
            menor = nota;
            maior = nota;
        } else {
            if (nota < menor) {
                menor = nota;
            }
            if (nota > maior) {
                maior = nota;
            }
        }
    }

    return 0;
}