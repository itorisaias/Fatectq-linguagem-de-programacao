#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
  int idade;
  char sexo;
  char nome[100];
} Pessoa;

void imprimirPessoa(Pessoa pessoa);

int main() {
  Pessoa pessoa1;

  printf("Digite o f ou m para o sexo: ");
  scanf("%c", &pessoa1.sexo);
  // getchar(); // Consome o caractere de nova linha que ficou no buffer
  printf("Digite o nome da pessoa: ");
  scanf(" %[^\n]", pessoa1.nome);
  printf("Digite a idade: ");
  scanf("%d", &pessoa1.idade);

  imprimirPessoa(pessoa1);

  return 0;
}

void imprimirPessoa(Pessoa pessoa) {
  printf("Nome: %s\n", pessoa.nome);
  printf("Sexo: %c\n", pessoa.sexo);
  printf("Idade: %d\n", pessoa.idade);
}
