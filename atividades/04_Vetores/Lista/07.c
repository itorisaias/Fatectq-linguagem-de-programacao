#include <stdio.h>

int main()
{
  int vetor[7];
  int x, y;

  // Recebendo os elementos do vetor
  printf("Digite os elementos do vetor (7 numeros):\n");
  for (int i = 0; i < 7; i++)
  {
    scanf("%d", &vetor[i]);
  }

  // Recebendo os numeros a serem substituidos
  printf("Digite o numero a ser substituido:\n");
  scanf("%d", &x);
  printf("Digite o novo numero:\n");
  scanf("%d", &y);

  // Substituindo todos os elementos iguais a x por y
  for (int i = 0; i < 7; i++)
  {
    if (vetor[i] == x)
    {
      vetor[i] = y;
    }
  }

  // Imprimindo o vetor resultante
  printf("Vetor resultante:\n");
  for (int i = 0; i < 7; i++)
  {
    printf("%d ", vetor[i]);
  }
  printf("\n");

  return 0;
}
