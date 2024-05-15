#include <stdio.h>

// Funções para preencher e imprimir uma matriz de tamanho linha x coluna
// Os parâmetros linha e coluna são passados por valor, enquanto a matriz é passada por referência
void preencherMatriz(int linha, int coluna, int matriz[linha][coluna]);
void imprimirMatriz(int linha, int coluna, int matriz[linha][coluna]);

int main()
{
  int linha, coluna;
  printf("Digite o tamanho da matriz (Linhas Colunas): ");
  scanf("%d %d", &linha, &coluna); // entrada de exemplo: 10 5

  // Verificando se as dimensões fornecidas são válidas
  if (linha <= 0 || coluna <= 0)
  {
    printf("Dimensões inválidas! Certifique-se de que ambas as dimensões sejam maiores que zero.\n");
    return 1; // Saindo do programa com código de erro
  }

  // Criação de matriz de tamanho dinâmico
  int mat[linha][coluna];
  preencherMatriz(linha, coluna, mat);
  imprimirMatriz(linha, coluna, mat);

  return 0;
}

void preencherMatriz(int linha, int coluna, int matriz[linha][coluna])
{
  printf("Preencha a matriz:\n");
  for (int l = 0; l < linha; l++)
  {
    for (int c = 0; c < coluna; c++)
    {
      scanf("%d", &matriz[l][c]);
    }
  }
}

void imprimirMatriz(int linha, int coluna, int matriz[linha][coluna])
{
  printf("Imprimindo matriz:\n");
  for (int l = 0; l < linha; l++)
  {
    for (int c = 0; c < coluna; c++)
    {
      printf("%d ", matriz[l][c]);
    }
    printf("\n");
  }
}
