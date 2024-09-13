#include <stdio.h>

int main()
{
  int vetor[10];
  int pares = 0, impares = 0;

  // Recebendo os elementos do vetor
  printf("Digite os elementos do vetor (10 numeros):\n");
  for (int i = 0; i < 10; i++)
  {
    scanf("%d", &vetor[i]);
  }

  // Contando a quantidade de números pares e ímpares
  for (int i = 0; i < 10; i++)
  {
    if (vetor[i] % 2 == 0)
    {
      pares++;
    }
    else
    {
      impares++;
    }
  }

  // Imprimindo a quantidade de números pares e ímpares
  printf("Quantidade de numeros pares: %d\n", pares);
  printf("Quantidade de numeros impares: %d\n", impares);

  return 0;
}
