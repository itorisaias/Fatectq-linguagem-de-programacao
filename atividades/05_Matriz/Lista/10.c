#include <stdio.h>
#include <stdlib.h>

#define MAX_ANDARES 100
#define MAX_APARTAMENTOS 4

int main() {
  int portas[MAX_ANDARES][MAX_APARTAMENTOS];
  int andares, numeros;

  scanf("%d %d", &andares, &numeros);

  for (int i = 0; i < andares; i++)
    for (int j = 0; j < MAX_APARTAMENTOS; j++)
      portas[i][j] = 0;

  for (int i = 0; i < numeros; i++)
  {
    int numero;
    scanf("%d", &numero);

    for (int andar = 1; andar <= andares; andar++)
      for (int ap = 1; ap <= MAX_APARTAMENTOS; ap++)
      {
        int apto = andar * 10 + ap;
        if (apto % numero == 0)
        {
          if (portas[andar - 1][ap - 1] == 0)
            portas[andar - 1][ap - 1] = 1;
          else
            portas[andar - 1][ap - 1] = 0;
        }
      }
  }

  for (int i = 0; i < andares; i++)
  {
    printf("Andar %d: ", i + 1);
    for (int j = 0; j < MAX_APARTAMENTOS; j++)
    {
      if (portas[i][j] == 0)
        printf("C ");
      else
        printf("O ");
    }
    printf("\n");
  }

  return 0;
}
