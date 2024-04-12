#include <stdio.h>

int main() {
  int idade = 30; // Declarando e inicializando a variável idade

  if (idade < 18) { // Testando a condição se é maior de idade
    printf("Você é menor de idade.\n");
  } else if (idade >= 18 && idade <= 30) { // Testando a condição se é maior ou igual à 18 E menor ou igual à 30
    printf("Você é jovem adulto.\n");
  } else { // Senão não é um adulto
    printf("Você é adulto.\n");
  }

  return 0;
}
