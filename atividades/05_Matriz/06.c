#include <stdio.h>

#define ROWS 3
#define COLS 3

int main()
{
  int matriz1[ROWS][COLS];
  int matriz2[ROWS][COLS];
  int i, j;
  int identicas = 1;

  for (i = 0; i < ROWS; i++)
    for (j = 0; j < COLS; j++)
      scanf("%d", &matriz1[i][j]);

  for (i = 0; i < ROWS; i++)
    for (j = 0; j < COLS; j++)
      scanf("%d", &matriz2[i][j]);

  for (i = 0; i < ROWS; i++)
  {
    for (j = 0; j < COLS; j++)
    {
      if (matriz1[i][j] != matriz2[i][j])
      {
        identicas = 0;
        break;
      }
    }
    if (!identicas)
      break;
  }

  if (identicas)
    printf("As matrizes são idênticas.\n");
  else
    printf("As matrizes não são idênticas.\n");

  return 0;
}
