// Desenvolva um programa em C que registre as notas de 40 alunos em 4 avaliações (tipo inteiro), calcule a média de cada aluno e determine quantos foram aprovados e quantos foram reprovados. Considere que a média de aprovação é igual ou superior a 6.












#include <stdio.h>

#define ALUNOS 40
#define NOTAS 4
#define MEDIA 6

int main() {
  int notas[ALUNOS][NOTAS];
  int aprovados = 0, reprovados = 0, soma = 0;
  float media;

  for (int i = 0; i < ALUNOS; i++)
    for (int j = 0; j < NOTAS; j++)
      scanf("%d", &notas[i][j]);

  for (int aluno = 0; aluno < ALUNOS; aluno++)
  {
    soma = 0;

    for (int nota = 0; nota < NOTAS; nota++)
    {
      soma += notas[aluno][nota];
    }

    media = soma / NOTAS;

    if (media >= MEDIA) {
      aprovados++;
    } else {
      reprovados++;
    }
  }

  printf("Aprovados: %d\n", aprovados);
  printf("Reprovados: %d\n", reprovados);

  return 0;
}
