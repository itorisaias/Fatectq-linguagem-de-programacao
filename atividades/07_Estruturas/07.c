#include <stdio.h>

// Definindo a estrutura para armazenar os dados de um aluno
typedef struct
{
  char nome[50];
  float notas[3];
  float media;
} Aluno;

// Função para ler os dados de um aluno
void lerAluno(Aluno *aluno)
{
  printf("Nome do aluno: ");
  scanf(" %[^\n]%*c", aluno->nome); // Lê uma linha inteira
  printf("Digite as 3 notas do aluno:\n");
  for (int i = 0; i < 3; ++i)
  {
    printf("Nota %d: ", i + 1);
    scanf("%f", &aluno->notas[i]);
  }
}

// Função para calcular a média das notas de um aluno
void calcularMedia(Aluno *aluno)
{
  float soma = 0.0;
  for (int i = 0; i < 3; ++i)
  {
    soma += aluno->notas[i];
  }
  aluno->media = soma / 3;
}

// Função para imprimir os dados de um aluno
void imprimirAluno(Aluno aluno)
{
  printf("Nome: %s\n", aluno.nome);
  printf("Notas: %.2f, %.2f, %.2f\n", aluno.notas[0], aluno.notas[1], aluno.notas[2]);
  printf("Média: %.2f\n", aluno.media);
}

int main()
{
  // Definindo um array de 3 alunos
  Aluno alunos[3];

  // Lendo os dados dos alunos
  for (int i = 0; i < 3; ++i)
  {
    printf("Aluno %d:\n", i + 1);
    lerAluno(&alunos[i]);
    calcularMedia(&alunos[i]);
    printf("\n");
  }

  // Imprimindo os dados dos alunos e suas médias
  for (int i = 0; i < 3; ++i)
  {
    printf("Aluno %d:\n", i + 1);
    imprimirAluno(alunos[i]);
    printf("\n");
  }

  return 0;
}
