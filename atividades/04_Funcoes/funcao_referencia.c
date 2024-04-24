// %p prints the address in hexadecimal format
#include <stdio.h>
// Função que recebe um ponteiro para int (referência) e modifica o valor da variável apontada por esse ponteiro
void modificar(int *ptr) {
  printf("MEMORIA recebida na função: %p\n", ptr);
  *ptr = 100; // Modifica o valor da variável apontada por ptr para 100
}
int main() {
  int numero = 10;
  printf("MEMORIA: %p\n", &numero);
  printf("Valor guardado: %d\n", numero);
  printf("---\n");
  modificar(&numero); // Chama a função modificar passando o endereço de memória da variável numero
  printf("Valor modificado: %d\n", numero);
  return 0;
}
