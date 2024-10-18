#include <stdio.h>

#define ROWS 2
#define COLS 3

int main()
{
  int matriz[ROWS][COLS];
  int transpose[COLS][ROWS];

  for (int i = 0; i < ROWS; i++)
    for (int j = 0; j < COLS; j++)
      scanf("%d", &matriz[i][j]);

  for (int i = 0; i < ROWS; i++)
    for (int j = 0; j < COLS; j++)
      transpose[j][i] = matriz[i][j];

  for (int i = 0; i < COLS; i++)
  {
    for (int j = 0; j < ROWS; j++)
      printf("%d ", transpose[i][j]);
    printf("\n");
  }

  return 0;
}
