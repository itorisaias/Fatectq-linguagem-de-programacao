// Faça um programa em C que exiba na tela os número primos entre 0 até o numero informado pelo usuário.*

#include <stdio.h>

int main() {
  int numero;

  // Solicita ao usuário que insira o número
  printf("Digite um número inteiro: ");
  scanf("%d", &numero);

  printf("Números primos entre 0 e %d:\n", numero);

  // Exibe os números primos entre 0 e o número informado pelo usuário
  for (int i = 2; i <= numero; i++) {
    int eh_primo = 1; // Assumindo que o número é primo

    // Verifica se i é primo
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        eh_primo = 0; // Se divisível, não é primo
        break;
      }
    }

    // Se i for primo, exibe-o
    if (eh_primo) {
      printf("%d ", i);
    }
  }

  return 0;
}
