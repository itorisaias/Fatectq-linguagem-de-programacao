#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include <conio.h>

typedef struct
{
  int ra;
  char nome[20];
  float altura;
} Pessoa;

int main() {
  Pessoa pessoa1;

  printf("Digite o RA da pessoa: ");
  scanf("%d", &pessoa1.ra);

  printf("Digite o Nome da pessoa: ");
  // scanf(" %[^\n]", pessoa1.nome); // para ler qualquer tipo de dados, até o final da linha ou \n
  // fgets(pessoa1.nome, sizeof(pessoa1.nome), stdin);
  // scanf(" %[^\n]%*c", pessoa1.nome);
  // scanf("%s", pessoa1.nome);

  printf("Digite a Altura da pessoa: ");
  scanf("%f", &pessoa1.altura);

  printf("\n\n=== Dados da pessoa ===\n");
  printf("Nome: %s\n", pessoa1.nome);
  printf("RA: %d\n", pessoa1.ra);
  printf("Altura: %.2f\n", pessoa1.altura);

  return 0;
}
