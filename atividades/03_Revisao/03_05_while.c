#include <stdio.h>

int main() {
  int contador = 0; // Declarando e inicializando a variável de controle

  while (contador <= 10) { // Testando a condição
    printf("%d ", contador); // Executando um comando dentro do laço
    contador++; // Atualizando a variável de controle
  }

  return 0;
}
