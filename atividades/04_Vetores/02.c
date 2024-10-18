// Escreva um programa em C que receba 5 
// números inteiros do usuário e os armazene em um vetor. 
// O programa deve ordenar os elementos do vetor em 
// ordem crescente e imprimir o vetor resultante.

// Entrada:
// 3 7 2 1

// Saida:
// 1 2 3 7
#include <stdio.h>

void imprimiVetor(int vet[4]) {
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

#include <stdio.h>
int main() {
    int vetor[4] = {3, 7, 2, 1};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4 - 1; j++)
        {
            if (vetor[j] > vetor[j + 1]) {
                int aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
    

    // imprimir
    for (int i = 0; i < 5; i++)
    {
        printf("%d", vetor[i]);
    }
    
    
    return 0;
}