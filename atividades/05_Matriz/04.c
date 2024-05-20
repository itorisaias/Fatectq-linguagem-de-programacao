#include <stdio.h>

#define ROWS 3
#define COLS 3

int main()
{
  int matriz[ROWS][COLS];
  int i, j;
  int minimo, maximo;

  for (i = 0; i < ROWS; i++)
    for (j = 0; j < COLS; j++)
      scanf("%d", &matriz[i][j]);

  minimo = matriz[0][0];
  maximo = matriz[0][0];

  for (i = 0; i < ROWS; i++)
  {
    for (j = 0; j < COLS; j++)
    {
      if (matriz[i][j] < minimo)
        minimo = matriz[i][j];
      if (matriz[i][j] > maximo)
        maximo = matriz[i][j];
    }
  }

  printf("%d\n", minimo);
  printf("%d\n", maximo);

  return 0;
}
