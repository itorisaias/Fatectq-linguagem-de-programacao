#include <stdio.h>

int main()
{
  int vetor[8];
  int m;
  int soma = 0;

  // Recebendo os elementos do vetor
  printf("Digite os elementos do vetor (8 numeros):\n");
  for (int i = 0; i < 8; i++)
  {
    scanf("%d", &vetor[i]);
    soma += vetor[i];
  }

  // Imprimindo a soma dos elementos do vetor
  printf("Soma dos elementos do vetor: %d\n", soma);

  return 0;
}
