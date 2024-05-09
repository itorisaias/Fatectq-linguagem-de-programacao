#include <stdio.h>

typedef struct
{
  int ra;
  char nome[50];
} Aluno;

void lerAluno(Aluno *aluno)
{
  printf("Digite o RA do aluno: ");
  scanf("%d", &aluno->ra);

  printf("Digite o nome do aluno: ");
  scanf("%50[^\n]", aluno->nome);
}

void lerAlunos(Aluno *alunos, int N)
{
  printf("\n--- Cadastro de Alunos ---\n");
  for (int i = 0; i < N; i++)
  {
    printf("\nAluno %d\n", i + 1);
    lerAluno(&alunos[i]);
  }
}

void mostrarAlunos(Aluno *alunos, int N)
{
  printf("\n--- Dados dos Alunos ---\n");
  for (int i = 0; i < N; i++)
    printf("Aluno %d - RA: %d, Nome: %s\n", i + 1, alunos[i].ra, alunos[i].nome);
}

int main()
{
  int N;
  printf("Digite a quantidade de alunos: ");
  scanf("%d", &N);

  Aluno alunos[N];

  lerAlunos(alunos, N);

  mostrarAlunos(alunos, N);

  return 0;
}
