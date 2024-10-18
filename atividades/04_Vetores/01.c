// Enunciado: Escreva um programa em C que receba 5 números inteiros 
// do usuário e os armazene em um vetor. Em seguida, o programa deve
// calcular e imprimir a soma, maior e o menor desses números e 
// inverter 
// a ordem dos elementos do vetor e imprimir o vetor resultante.

// Entrada:
// 2
// 5
// 3
// 1
// 4

// Saida:
// soma: 15
// maior: 5
// menor: 1
// invertido: 4 1 3 5 2

#include <stdio.h>
#define MAXIMO 5

int main () {
    int numeros[MAXIMO];
    int soma = 0;
    int maior, menor;

    // Entrada dos dados
    for (int i = 0; i < MAXIMO; i++)
    {
        scanf("%d", &numeros[i]);
    }

    // Soma - numeros = [1, 2, 3, 4, 5]
    for (int i = 0; i < MAXIMO; i++)
    {
        soma = soma + numeros[i];
    }
    
    // Buscar maior e menor - numeros = [7, 2, 9, 4, 1]
    maior = numeros[0];
    menor = numeros[0];
    for (int i = 0; i < MAXIMO; i++)
    {
        if (numeros[i] > maior) {
            maior = numeros[i];
        }
        if (numeros[i] < menor) {
            menor = numeros[i];
        }
    }
    
    printf("Soma: %d\n", soma);
    printf("Maior: %d\n", maior);
    printf("Menor: %d\n", menor);

    // inverter vetor
    printf("Invertido: ");
    for (int i = MAXIMO - 1; i >=0 ; i--)
    {
        printf("%d ", numeros[i]);
    }
    return 0;
}