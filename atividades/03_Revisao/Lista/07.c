// Faça um programa em C que receba um número inteiro e positivo, e diga se esse número é primo ou não. Obs: Um número é primo somente quando for divisível por 1 e por ele mesmo.

// Uma forma simples e clara para descobrir se um número é primo em C é verificar se ele é divisível por algum número além de 1 e dele mesmo.
// Aqui está um exemplo de código que realiza essa verificação:

#include <stdio.h>

int main() {
  int numero, i, divisores = 0;

  // Solicita ao usuário que insira o número
  printf("Digite um número inteiro e positivo: ");
  scanf("%d", &numero);

  // Verifica se o número é menor ou igual a 1
  if (numero <= 1) {
    printf("%d não é primo.\n", numero);
    return 0;
  }

  // Loop para verificar os divisores do número
  for (i = 1; i <= numero; i++) {
    if (numero % i == 0) {
      divisores++;
    }
  }

  // Se tiver apenas dois divisores (1 e o próprio número), é primo
  if (divisores == 2) {
    printf("%d é primo.\n", numero);
  } else {
    printf("%d não é primo.\n", numero);
  }

  return 0;
}
