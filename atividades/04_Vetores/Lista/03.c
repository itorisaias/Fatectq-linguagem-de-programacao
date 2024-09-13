#include <stdio.h>

int main()
{
  int vetor[7];
  int maior, menor;

  // Recebendo os elementos do vetor
  printf("Digite os elementos do vetor (7 numeros):\n");
  for (int i = 0; i < 7; i++)
  {
    scanf("%d", &vetor[i]);
  }

  // Inicializando o maior e o menor com o primeiro elemento do vetor
  maior = vetor[0];
  menor = vetor[0];

  // Determinando o maior e o menor elemento do vetor
  for (int i = 1; i < 7; i++)
  {
    if (vetor[i] > maior)
    {
      maior = vetor[i];
    }
    if (vetor[i] < menor)
    {
      menor = vetor[i];
    }
  }

  // Imprimindo o maior e o menor elemento
  printf("O maior elemento do vetor: %d\n", maior);
  printf("O menor elemento do vetor: %d\n", menor);

  return 0;
}
