#include <stdio.h>
int main() {
  int numero;
  scanf("%d", &numero);
  printf("Numero %d e par? %s\n", numero, numero % 2 == 0 ? "Sim" : "Nao");
  for (int i = 1; i <= 10; i++)
    printf("%d x %d = %d\n", numero, i, numero * i);
  return 0;
}
