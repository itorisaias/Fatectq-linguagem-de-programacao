// Faça um programa em C que exiba na tela os números ímpares entre 100 e 300.

#include <stdio.h>

int main() {
    printf("Números ímpares entre 100 e 300:\n");

    // Loop de 100 a 300
    for (int i = 101; i <= 299; i += 2) {
        printf("%d\n", i);
    }

    return 0;
}
