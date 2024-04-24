// Enunciado: Escreva um programa em C que receba 10 números inteiros do usuário e os armazene em um vetor. Em seguida, o programa deve encontrar e imprimir o maior e o menor número digitado.

// Entrada:
// 2
// 7
// 5
// 19
// 1
// 16
// 22
// 9
// 10
// 4

// Saida:
// O maior numero digitado e: 22
// O menor numero digitado e: 1

#include <stdio.h>

int main()
{
  int numeros[10];
  int maior, menor;

  printf("Digite 10 numeros inteiros:\n");

  for (int i = 0; i < 10; i++)
  {
    scanf("%d", &numeros[i]);
  }

  maior = menor = numeros[0];

  for (int i = 1; i < 10; i++)
  {
    if (numeros[i] > maior)
    {
      maior = numeros[i];
    }
    if (numeros[i] < menor)
    {
      menor = numeros[i];
    }
  }

  printf("O maior numero digitado e: %d\n", maior);
  printf("O menor numero digitado e: %d\n", menor);

  return 0;
}
