// Faça um programa em C (utilize a estrutura for) que leia 5 valores inteiros e:
//    1. Encontre e mostre o maior valor
//    2. Encontre e mostre o menor valor
//    3. Calcule e mostre a média dos números lidos

#include <stdio.h>

int main() {
    int valor, maior, menor, soma = 0;

    // Lê o primeiro valor
    printf("Digite o valor 1: ");
    scanf("%d", &valor);

    // Define o primeiro valor como maior e menor inicialmente
    maior = valor;
    menor = valor;

    // Soma o primeiro valor para calcular a média
    soma += valor;

    // Loop para ler os próximos 4 valores
    for (int i = 2; i <= 5; i++) {
        printf("Digite o valor %d: ", i);
        scanf("%d", &valor);

        // Atualiza o maior valor, se necessário
        if (valor > maior) {
            maior = valor;
        }

        // Atualiza o menor valor, se necessário
        if (valor < menor) {
            menor = valor;
        }

        // Soma o valor para calcular a média
        soma += valor;
    }

    // Calcula a média
    float media = (float) soma / 5;

    // Mostra os resultados
    printf("\nMaior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);
    printf("Média dos valores: %.2f\n", media);

    return 0;
}
