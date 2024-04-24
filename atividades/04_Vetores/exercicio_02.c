// Escreva um programa em C que receba uma sequência de números inteiros do usuário e determine se a sequência está em ordem crescente, decrescente ou não ordenada

// Entrada 1:
// 5
// 1 2 3 4 5

// Saida 1:
// A sequencia esta em ordem crescente.

// ----------------------------------------

// Entrada 2:
// 4
// 5 4 3 2

// Saida 2:
// A sequencia esta em ordem decrescente.

// ----------------------------------------

// Entrada 3:
// 6
// 3 7 1 9 4 2

// Saida 3:
// A sequencia nao esta ordenada.

// ----------------------------------------
















#include <stdio.h>

int main()
{
  int numeros[100];
  int tamanho, ordem = 0;

  printf("Digite o tamanho da sequencia (maximo 100):\n");
  scanf("%d", &tamanho);

  printf("Digite %d numeros inteiros:\n", tamanho);

  for (int i = 0; i < tamanho; i++)
    scanf("%d", &numeros[i]);

  // Verifica se a sequencia esta em ordem crescente
  for (int i = 0; i < tamanho - 1; i++)
  {
    if (numeros[i] > numeros[i + 1])
    {
      ordem = -1;
      break;
    }
    else if (numeros[i] < numeros[i + 1])
    {
      ordem = 1;
      break;
    }
  }

  if (ordem == 1)
    printf("A sequencia esta em ordem crescente.\n");
  else if (ordem == -1)
    printf("A sequencia esta em ordem decrescente.\n");
  else
    printf("A sequencia nao esta ordenada.\n");

  return 0;
}
