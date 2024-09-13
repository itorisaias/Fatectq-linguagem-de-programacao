#include <stdio.h>

int main()
{
  int vetor[6];
  int vetor_invertido[6];

  printf("Digite os elementos do vetor (6 numeros):\n");
  for (int i = 0; i < 6; i++)
  {
    scanf("%d", &vetor[i]);
  }

  for (int i = 0; i < 6; i++)
  {
    vetor_invertido[i] = vetor[5 - i];
  }

  printf("Vetor resultante (invertido):\n");
  for (int i = 0; i < 6; i++)
  {
    printf("%d ", vetor_invertido[i]);
  }
  printf("\n");

  return 0;
}
