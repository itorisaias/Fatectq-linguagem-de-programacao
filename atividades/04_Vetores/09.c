#include <stdio.h>

int main()
{
  int vetor[5];

  // Recebendo os elementos do vetor
  printf("Digite os elementos do vetor (5 numeros):\n");
  for (int i = 0; i < 5; i++)
  {
    scanf("%d", &vetor[i]);
  }

  // Ordenando o vetor em ordem crescente com Insertion Sort
  // for (int i = 1; i < 5; i++)
  // {
  //   int atual = vetor[i];
  //   int j = i - 1;
  //   while (j >= 0 && vetor[j] > atual)
  //   {
  //     vetor[j + 1] = vetor[j];
  //     j--;
  //   }
  //   vetor[j + 1] = atual;
  // }

  // Ordenando o vetor em ordem crescente com Bubble Sort
  for (int i = 0; i < 5 - 1; i++)
  {
    for (int j = 0; j < 5 - i - 1; j++)
    {
      if (vetor[j] > vetor[j + 1])
      {
        // Trocando os elementos de posição se estiverem fora de ordem
        int temp = vetor[j];
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = temp;
      }
    }
  }

  // Imprimindo o vetor resultante
  printf("Vetor resultante (ordenado em ordem crescente):\n");
  for (int i = 0; i < 5; i++)
  {
    printf("%d ", vetor[i]);
  }
  printf("\n");

  return 0;
}
