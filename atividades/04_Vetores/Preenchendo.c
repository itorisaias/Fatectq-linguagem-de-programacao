#include <stdio.h>
#define NOTAS 4
int notas[NOTAS];

int main() {
  for (int i = 0; i < NOTAS; i++)
  {
    scanf("%d", &notas[i]);
  }

  for (int i = 0; i < NOTAS; i++)
  {
    printf("%d", notas[i]);
  }
}
