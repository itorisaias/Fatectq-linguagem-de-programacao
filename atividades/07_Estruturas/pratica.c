#include <string.h>
#include <stdio.h>

typedef struct {
  char sexo;
  char nome[100];
  int idade;
  float peso;
} Pessoa1;

int main() {
  // Pessoa1 pessoa1 = {'m', "Itor Isaias", 27, 110};

  // Pessoa1 pessoa1;
  // pessoa1.sexo = 'm';
  // strcpy(pessoa1.nome, "Itor Isaias");
  // pessoa1.idade = 27;
  // pessoa1.peso = 110;

  Pessoa1 pessoa1;
  printf("Digite seu nome: ");
  // scanf("%s", pessoa1.nome);
  // scanf("%[^\n]", pessoa1.nome);
  // getchar();
  fgets(pessoa1.nome, 100, stdin);
  printf("Digite f ou m para sexo: ");
  scanf("%c", &pessoa1.sexo);
  printf("Digite idade: ");
  scanf("%d", &pessoa1.idade);
  printf("Digite peso: ");
  scanf("%f", &pessoa1.peso);

  printf("\nPessoa: \n");
  printf("Nome: %s\n", pessoa1.nome);
  printf("Idade: %d\n", pessoa1.idade);
  printf("Sexo: %c\n", pessoa1.sexo);
  printf("Peso: %f\n", pessoa1.peso);

  return 0;
}
