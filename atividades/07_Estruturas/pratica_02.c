// #include <string.h>
// #include <stdio.h>

// typedef struct {
//   int ano, mes, dia;
// } Data;
// typedef struct
// {
//   char sexo;
//   char nome[100];
//   int idade;
//   float peso;
//   Data data_nascimento;
// } Pessoa;

// void lerPessoa(Pessoa *pessoa);
// void imprimirPessoa(Pessoa pessoa);

// int main() {
//   Pessoa pessoa;

//   printf("Tamanho: %ld", sizeof(Pessoa));

//   // lerPessoa(&pessoa);
//   // imprimirPessoa(pessoa);

//   return 0;
// }

// void lerPessoa(Pessoa *pessoa) {
//   printf("Digite seu nome: ");
//   scanf("%[^\n]", pessoa->nome);
//   getchar();
//   printf("Digite f ou m para sexo: ");
//   scanf("%c", &pessoa->sexo);
//   printf("Digite idade: ");
//   scanf("%d", &pessoa->idade);
//   printf("Digite peso: ");
//   scanf("%f", &pessoa->peso);

//   &pessoa->data_nascimento.
// }

// void imprimirPessoa(Pessoa pessoa) {
//   printf("\nPessoa: \n");
//   printf("Nome: %s\n", pessoa.nome);
//   printf("Idade: %d\n", pessoa.idade);
//   printf("Sexo: %c\n", pessoa.sexo);
//   printf("Peso: %f\n", pessoa.peso);
// }

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct
{
  char sexo;
  char nome;
  int idade;
  float peso;
} Pessoa1;

int main()
{
  // Pessoa1 pessoa1 = ('m','Ricardo Ferreira',27,1.72);
  Pessoa1 pessoa1;
  printf("Digite seu Nome: \n");
  scanf("%[^\n]", pessoa1.nome);
  getchar();
  printf("Digite seu sexo: m ou f: \n");
  scanf("%s", &pessoa1.sexo);
  printf("Digite sua idade: \n");
  scanf("%d", &pessoa1.idade);
  printf("Digite sua peso: \n");
  scanf("%f", &pessoa1.peso);

  return 0;
}
