// Enunciado: Escreva um programa em C que receba 5 números inteiros do usuário e os armazene em um vetor. Em seguida, o programa deve calcular e imprimir a soma desses números.

// Entrada:
// 1
// 2
// 3
// 4
// 5

// Saida:
// 15





















#include <stdio.h>

int main()
{
  int numeros[5];
  int soma = 0;

  printf("Digite 5 numeros inteiros:\n");

  for (int i = 0; i < 5; i++)
  {
    scanf("%d", &numeros[i]);
    soma += numeros[i];
  }

  printf("A soma dos numeros digitados e: %d\n", soma);

  return 0;
}
