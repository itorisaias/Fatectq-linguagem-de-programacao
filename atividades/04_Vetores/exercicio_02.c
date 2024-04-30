// Escreva um programa em C que receba 5 números inteiros do usuário e os armazene em um vetor. O programa deve ordenar os elementos do vetor em ordem crescente e imprimir o vetor resultante.

// Entrada:
// 8 2 4 9 1

// Saida:
// 1 2 4 8 9

#include <stdio.h>
#define TAM 5

int main()
{
  int vetor[TAM], aux;
  for (int i = 0; i < TAM; i++)
    scanf("%d", &vetor[i]);

  for (int i = 0; i < TAM; i++)
    for (int j = 0; j < TAM - 1; j++)
      if (vetor[j] > vetor[j + 1])
      {
        aux = vetor[j];
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = aux;
      }

  for (int i = 0; i < TAM; i++)
    printf("%d ", vetor[i]);
  printf("\n");

  return 0;
}
