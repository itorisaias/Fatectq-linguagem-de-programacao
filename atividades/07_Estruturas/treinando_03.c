#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
  int ano, mes, dia;
} Data;

typedef struct
{
  Data data_nascimento;
  int idade;
  char sexo;
  char nome[100];
} Pessoa;


int main() {
  Pessoa pessoa1;

  printf("Digite o nome da pessoa: ");
  scanf("%[^\n]", pessoa1.nome);

  printf("Digite a idade: ");
  scanf("%d", &pessoa1.idade);

  getchar(); // Consome o caractere de nova linha que ficou no buffer

  printf("Digite o f ou m para o sexo: ");
  scanf("%c", &pessoa1.sexo);

  printf("Digite a data de nascimento (dd/mm/yyyy): ");
  scanf("%d/%d/%d", &pessoa1.data_nascimento.dia, &pessoa1.data_nascimento.mes, &pessoa1.data_nascimento.ano);

  printf("Nome: %s\n", pessoa1.nome);
  printf("Sexo: %c\n", pessoa1.sexo);
  printf("Idade: %d\n", pessoa1.idade);
  printf("Nascimento: %d/%d/%d\n", pessoa1.data_nascimento.dia, pessoa1.data_nascimento.mes, pessoa1.data_nascimento.ano);

  return 0;
}
