#include <stdio.h>

#define ROWS 3
#define COLS 3

int main()
{
  int matrix[ROWS][COLS];
  int sum = 0;

  for (int i = 0; i < ROWS; i++)
    for (int j = 0; j < COLS; j++)
      scanf("%d", &matrix[i][j]);

  for (int i = 0; i < ROWS; i++)
    for (int j = 0; j < COLS; j++)
      sum += matrix[i][j];

  printf("%d\n", sum);

  return 0;
}
