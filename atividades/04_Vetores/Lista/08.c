#include <stdio.h>

int main()
{
  int vetor[6];
  int tamanho = 6;
  int x, i, j;

  printf("Digite os elementos do vetor (6 numeros):\n");
  for (i = 0; i < tamanho; i++)
    scanf("%d", &vetor[i]);

  printf("Digite o numero inteiro a ser removido:\n");
  scanf("%d", &x);

  // Removendo todas as ocorrências de x do vetor
  for (i = 0; i < tamanho; i++)
    if (vetor[i] == x)
    {
      // Deslocando os elementos à direita do x removido
      for (j = i; j < tamanho - 1; j++)
      {
        vetor[j] = vetor[j + 1];
      }
      tamanho--; // Reduzindo o tamanho do vetor
      i--;       // Ajustando o índice para verificar o próximo elemento
    }

  // Imprimindo o vetor resultante
  printf("Vetor resultante:\n");
  for (i = 0; i < tamanho; i++)
    printf("%d ", vetor[i]);

  printf("\n");

  return 0;
}
