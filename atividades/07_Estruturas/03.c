#include <stdio.h>

// Definindo a estrutura Aluno
typedef struct
{
  int ra;
  char nome[50];
} Aluno;

// Função para ler os dados de um único aluno
void lerAluno(Aluno *aluno)
{
  printf("Digite o RA do aluno: ");
  scanf("%d", &aluno->ra);

  printf("Digite o nome do aluno: ");
  scanf(" %[^\n]", aluno->nome);
}

// Função para ler os dados de vários alunos
void lerAlunos(Aluno *alunos, int N)
{
  printf("\n--- Cadastro de Alunos ---\n");
  for (int i = 0; i < N; i++)
  {
    printf("\nAluno %d\n", i + 1);
    lerAluno(&alunos[i]);
  }
}

// Função para exibir os dados de todos os alunos
void mostrarAlunos(Aluno *alunos, int N)
{
  printf("\n--- Dados dos Alunos ---\n");
  for (int i = 0; i < N; i++)
  {
    printf("Aluno %d - RA: %d, Nome: %s\n", i + 1, alunos[i].ra, alunos[i].nome);
  }
}

int main()
{
  int N;
  printf("Digite a quantidade de alunos: ");
  scanf("%d", &N);

  // Declaração de um array de alunos com tamanho N
  Aluno alunos[N];

  // Chamada da função para ler os dados de vários alunos
  lerAlunos(alunos, N);

  // Chamada da função para exibir os dados de todos os alunos
  mostrarAlunos(alunos, N);

  return 0;
}
