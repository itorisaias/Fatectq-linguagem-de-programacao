// Escreva um programa em C que receba 5 números inteiros do usuário e os armazene em um vetor. O programa deve remover os elementos do vetor que sejam par e imprimir o vetor resultante.

// Entrada:
// 9 2 4 7 1

// Saida:
// 9 7 1





























#include <stdio.h>

int main()
{
  int numeros[5], vetor_resultante[5];
  int novo_tamanho = 0, indice = 0;

  printf("Digite 5 numeros inteiros:\n");
  for (int i = 0; i < 5; i++)
  {
    scanf("%d", &numeros[i]);
    if (numeros[i] % 2 != 0)
      novo_tamanho++;
  }

  for (int i = 0; i < 5; i++)
    if (numeros[i] % 2 != 0)
    {
      vetor_resultante[indice] = numeros[i];
      indice++;
    }

  printf("Vetor resultante:\n");
  for (int i = 0; i < novo_tamanho; i++)
    printf("%d ", vetor_resultante[i]);

  printf("\n");

  return 0;
}
