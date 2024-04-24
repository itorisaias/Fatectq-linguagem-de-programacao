#include <stdio.h>
void main() {
  int vet[10] = {0, 8, 7, 6, 5, 4, 3, 2, 1, 9};
  char nome[5] = "itor";

  vet[0] = 9; // Atribui o valor `9` à primeira posição do vetor.
  vet[9] = 0; // Atribui o valor `0` à sétima posição do vetor.
  nome[3] = 'b'; // Atribui a letra `b` à quarta posição do vetor.

  for (int i = 0; i < 10; i++)
    printf("%d ",vet[i]);
}
