#include <stdio.h>

int main()
{
  int vetor[8];
  int soma_cumulativa[8] = {0}; // Inicializando o vetor de soma cumulativa com zeros

  // Recebendo os elementos do vetor
  printf("Digite os elementos do vetor (8 numeros):\n");
  for (int i = 0; i < 8; i++)
  {
    scanf("%d", &vetor[i]);
  }

  // Calculando a soma cumulativa dos elementos do vetor
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      soma_cumulativa[i] += vetor[j];
    }
  }

  // Imprimindo a soma cumulativa dos elementos do vetor
  printf("Soma cumulativa dos elementos do vetor:\n");
  for (int i = 0; i < 8; i++)
  {
    printf("%d ", soma_cumulativa[i]);
  }
  printf("\n");

  return 0;
}
