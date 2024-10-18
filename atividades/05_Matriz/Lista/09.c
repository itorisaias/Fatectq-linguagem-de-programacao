#include <stdio.h>

#define N 3

int main()
{
  int matriz[N][N];
  int i, j, k, temp;

  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      scanf("%d", &matriz[i][j]);

  int vetor[N * N];
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      vetor[i * N + j] = matriz[i][j];

  for (i = 0; i < N * N - 1; i++)
    for (j = 0; j < N * N - i - 1; j++)
      if (vetor[j] > vetor[j + 1])
      {
        temp = vetor[j];
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = temp;
      }

  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      matriz[i][j] = vetor[i * N + j];

  for (i = 0; i < N; i++)
  {
    for (j = 0; j < N; j++)
      printf("%d ", matriz[i][j]);
    printf("\n");
  }

  return 0;
}
