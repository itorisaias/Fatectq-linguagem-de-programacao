#include <stdio.h>
#define TAMANHO 3

int main() {
  int matriz[TAMANHO][TAMANHO];

  for (int i = 0; i < TAMANHO; i++)
    for (int j = 0; j < TAMANHO; j++) {
      printf("matriz[%d][%d]: \n", i, j);
      scanf("%d", &matriz[i][j]);
    }

  for (int i = 0; i < TAMANHO; i++) {
    for (int j = 0; j < TAMANHO; j++) {
      printf("matriz[%d][%d] => %d | ", i, j, matriz[i][j]);
    }
    printf("\n");
  }

  return 0;
}
