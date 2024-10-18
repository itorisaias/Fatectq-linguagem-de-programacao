#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_TABULEIRO 5
#define NUM_NAVIOS 2


int main()
{
  char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
  char resposta[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
  int naviosRestantes = NUM_NAVIOS;
  int i, j;
  int palpiteLinha, palpiteColuna;

  printf("Bem-vindo ao jogo de Batalha Naval!\n");
  printf("Encontre os %d navios inimigos.\n", NUM_NAVIOS);

  for (i = 0; i < TAMANHO_TABULEIRO; i++)
    for (j = 0; j < TAMANHO_TABULEIRO; j++) {
      tabuleiro[i][j] = '-';
      resposta[i][j] = '-';
    }

  for (i = 0; i < NUM_NAVIOS; i++)
  {
    int linha, coluna;
    printf("Jogador informe a linha (1-5) e a coluna (1-5) do %d navio\n", i + 1);
    scanf("%d %d", &linha, &coluna);
    if (resposta[linha - 1][coluna - 1] == '-')
      resposta[linha - 1][coluna - 1] = 'N';
    else
      i--;
  }

  system("clear");

  while (naviosRestantes > 0)
  {
    printf("\nTabuleiro:\n");
    printf("  ");
    for (i = 0; i < TAMANHO_TABULEIRO; i++)
      printf("%d ", i + 1);
    printf("\n");
    for (i = 0; i < TAMANHO_TABULEIRO; i++)
    {
      printf("%d ", i + 1);
      for (j = 0; j < TAMANHO_TABULEIRO; j++)
        printf("%c ", tabuleiro[i][j]);
      printf("\n");
    }

    printf("Digite seu palpite (linha coluna): ");
    scanf("%d %d", &palpiteLinha, &palpiteColuna);

    system("clear");

    if (palpiteLinha < 0 || palpiteLinha >= TAMANHO_TABULEIRO || palpiteColuna < 0 || palpiteColuna >= TAMANHO_TABULEIRO)
    {
      printf("Palpite fora do tabuleiro.\n");
      continue;
    }

    if (resposta[palpiteLinha][palpiteColuna] == 'N')
    {
      printf("Parabéns! Você acertou um navio inimigo!\n");
      tabuleiro[palpiteLinha][palpiteColuna] = 'X';
      naviosRestantes--;
    }
    else if (tabuleiro[palpiteLinha][palpiteColuna] == 'O' || tabuleiro[palpiteLinha][palpiteColuna] == 'X')
    {
      printf("Você já tentou esta posição.\n");
    }
    else
    {
      printf("Água! Tente novamente.\n");
      tabuleiro[palpiteLinha][palpiteColuna] = 'O';
    }
  }

  printf("\nParabéns! Você destruiu todos os navios inimigos!\n");
  printf("\nTabuleiro final:\n");
  for (i = 0; i < TAMANHO_TABULEIRO; i++)
  {
    printf("  ");
    for (j = 0; j < TAMANHO_TABULEIRO; j++)
      printf("%c ", tabuleiro[i][j]);
    printf("\n");
  }

  return 0;
}
