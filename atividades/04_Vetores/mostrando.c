#include <stdio.h>
void main() {
  int vetor[10];
  for (int i=0; i < 10; i++)
    scanf("%d%*c", &vetor[i]);
  for (int i=0; i < 10; i++)
    printf("%d ", vetor[i]);
}
