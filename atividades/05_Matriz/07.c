#include <stdio.h>

#define ROWS 3
#define COLS 3

int main()
{
  int matrix[ROWS][COLS];
  int i, j;
  int symmetric = 1;

  for (i = 0; i < ROWS; i++)
    for (j = 0; j < COLS; j++)
      scanf("%d", &matrix[i][j]);

  for (i = 0; i < ROWS; i++)
  {
    for (j = 0; j < COLS; j++)
    {
      if (matrix[i][j] != matrix[j][i])
      {
        symmetric = 0;
        break;
      }
    }
    if (!symmetric)
      break;
  }

  if (symmetric)
    printf("A matriz é simétrica.\n");
  else
    printf("A matriz não é simétrica.\n");

  return 0;
}
