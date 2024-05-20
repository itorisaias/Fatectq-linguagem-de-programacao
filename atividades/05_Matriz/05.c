// #include <stdio.h>

// #define N 3

// int main() {
//   int matriz1[N][N], matriz2[N][N], resultado[N][N];
//   int i, j, k;

//   printf("Primeira matriz %dx%d:\n", N, N);
//   for (i = 0; i < N; i++)
//     for (j = 0; j < N; j++)
//       scanf("%d", &matriz1[i][j]);

//   printf("Segunda matriz %dx%d:\n", N, N);
//   for (i = 0; i < N; i++)
//     for (j = 0; j < N; j++)
//       scanf("%d", &matriz2[i][j]);

//   for (i = 0; i < N; i++)
//     for (j = 0; j < N; j++)
//     {
//       resultado[i][j] = 0;
//       for (k = 0; k < N; k++)
//         resultado[i][j] += matriz1[i][k] * matriz2[k][j];
//     }

//   printf("Resultado:\n");
//   for (i = 0; i < N; i++)
//   {
//     for (j = 0; j < N; j++)
//       printf("%d ", resultado[i][j]);
//     printf("\n");
//   }

//   return 0;
// }


#include <stdio.h>

#define N 2

int main() {
  int matriz1[N][N] = {
    {1, 2},
    {3, 4}
  };
  int matriz2[N][N] = {
    {2, 0},
    {1, 2}
  };
  int resultado[N][N];
  int i, j, k;

  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
    {
      resultado[i][j] = 0;
      for (k = 0; k < N; k++)
        resultado[i][j] += matriz1[i][k] * matriz2[k][j];
    }

  for (i = 0; i < N; i++)
  {
    for (j = 0; j < N; j++)
      printf("%d ", resultado[i][j]);
    printf("\n");
  }

  return 0;
}
