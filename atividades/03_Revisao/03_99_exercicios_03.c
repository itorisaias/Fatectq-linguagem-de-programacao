// Faça um programa em C que mostre a tabuada de qualquer número escolhido pelo usuário (considerar tabuada do número 1 ao 10)

#include <stdio.h>

int main() {
    int numero, i;

    // Solicita ao usuário o número para o qual deseja ver a tabuada
    printf("Digite um número para ver sua tabuada: ");
    scanf("%d", &numero);

    // Mostra a tabuada do número de 1 a 10
    printf("Tabuada do %d:\n", numero);
    for (i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", numero, i, numero * i);
    }

    return 0;
}
