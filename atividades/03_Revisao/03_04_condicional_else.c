#include <stdio.h>

int main() {
  int idade = 30; // Declarando e inicializando a variável idade

  if (idade < 18) { // Testando a condição se é maior de idade
    printf("Você é menor de idade.\n");
  } else { // Senão não é um adulto
    printf("Você é maior de idade.\n");
  }

  return 0;
}
