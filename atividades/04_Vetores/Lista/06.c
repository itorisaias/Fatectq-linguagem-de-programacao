#include <stdio.h>

int main()
{
  int vetor[9];
  int soma = 0;

  // Recebendo os elementos do vetor
  printf("Digite os elementos do vetor (9 numeros):\n");
  for (int i = 0; i < 9; i++)
  {
    scanf("%d", &vetor[i]);
    soma += vetor[i]; // Calculando a soma dos elementos durante a leitura
  }

  // Calculando a média aritmética dos elementos do vetor
  float media = (float)soma / 9;
3
  // Imprimindo a média aritmética
  printf("Media aritmetica dos elementos do vetor: %.2f\n", media);

  return 0;
}
