#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_JOGO 10

// CELULA
typedef struct
{
  int eBomba;
  int estaAberta;
  int vizinho;
} Celula;

Celula jogo[TAMANHO_JOGO][TAMANHO_JOGO];

void inicializarJogo();
void sortearBombas(int n);
void contarBombas();
void apresentarJogo();
void limparTela();
void comecarJogo();
void coletarPalpite(int *x, int *z);
int atualizarJogo(int x, int y);

int main()
{
  inicializarJogo();
  sortearBombas(2);
  apresentarJogo();
  comecarJogo();
  return 0;
}

void inicializarJogo()
{
  for (int i = 0; i < TAMANHO_JOGO; i++)
  {
    for (int j = 0; j < TAMANHO_JOGO; j++)
    {
      Celula celula = {0, 0, 0};
      jogo[i][j] = celula;
    }
  }
}

void sortearBombas(int n)
{
  srand(time(NULL));
  for (int i = 0; i < n; i++)
  {
    int x = rand() % TAMANHO_JOGO;
    int y = rand() % TAMANHO_JOGO;

    if (jogo[x][y].eBomba == 0)
      jogo[x][y].eBomba = 1;
    else
      i--;
  }
}

void contarBombas() {
  for (int i = 0; i < TAMANHO_JOGO; i++)
  {
    for (int j = 0; j < TAMANHO_JOGO; j++) {
      Celula celula = jogo[i][j];

      int cima = jogo[i - 1][j].eBomba

    }
  }
}

void apresentarJogo()
{
  printf("\n\tJogo \n\n");
  printf("  ");

  for (int i = 0; i < TAMANHO_JOGO; i++)
  {
    printf("%d ", i);
  }
  printf("\n");

  for (int i = 0; i < TAMANHO_JOGO; i++)
  {
    printf("%d ", i);
    for (int j = 0; j < TAMANHO_JOGO; j++)
    {
      Celula celula = jogo[i][j];
      if (celula.estaAberta)
      {
        printf("%c ", celula.eBomba ? 'X' : '0');
      }
      else
      {
        printf(". ");
      }
    }
    printf("\n");
  }
}

void limparTela()
{
  system("clear");
}

void coletarPalpite(int *x, int *y)
{
  do
  {
    printf("Digite seu palpite (X Y): \n");
    scanf("%d %d", x, y);

    if (*x >= 0 && *x < TAMANHO_JOGO && *y >= 0 && *y < TAMANHO_JOGO)
      return;

    limparTela();
    apresentarJogo();
    printf("> Palpite invalido! \n");
  } while (1);
}

int atualizarJogo(int x, int y)
{
  Celula palpite = jogo[x][y];

  if (palpite.eBomba == 0 && palpite.estaAberta == 0)
  {
    jogo[x][y].estaAberta = 1;
    limparTela();
    apresentarJogo();
    return 0;
  }

  if (palpite.eBomba == 1)
  {
    limparTela();
    apresentarJogo();
    printf("Fim do jogo!");
    return 1;
  }

  if (palpite.estaAberta == 1)
  {
    limparTela();
    apresentarJogo();
    printf("> O campo já está aberto!\n");
    return 0;
  }
}

void comecarJogo()
{
  int x, y;

  limparTela();
  apresentarJogo();

  do
  {
    coletarPalpite(&x, &y);
  } while (atualizarJogo(x, y) == 0);
}
