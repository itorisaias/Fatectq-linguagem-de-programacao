// typedef struct {
//   char nome[50];
//   int ano_nascimento;
// } Pessoa1;
// Pessoa1 pessoa1 = {"Itor Isaias da Silva", 1996};

// struct Pessoa2 {
//   char nome[50];
//   int ano_nascimento;
// };
// struct Pessoa2 pessoa2 = {"Itor Isaias da Silva", 1996};

// typedef struct Pessoa3 {
//   char nome[50];
//   int ano_nascimento;
// } P3;

#include <stdio.h>
typedef struct {
  char nome[50];
  int ano_nascimento;
} Pessoa;
Pessoa p1;
void main() {
  scanf("%[^\n]", p1.nome);
  scanf("%d", &p1.ano_nascimento);
  printf("Pessoa \nNome: %s \nAno: %d", p1.nome, p1.ano_nascimento);
}
