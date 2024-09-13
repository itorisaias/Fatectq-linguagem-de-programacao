#include <stdio.h>

int main()
{
  int vetor[8];
  int numero;

  // Recebendo os elementos do vetor
  printf("Digite os elementos do vetor (8 numeros):\n");
  for (int i = 0; i < 8; i++)
  {
    scanf("%d", &vetor[i]);
  }

  // Recebendo o número a ser verificado
  printf("Digite um numero para verificar se esta presente no vetor:\n");
  scanf("%d", &numero);

  // Verificando se o número está presente no vetor
  int encontrado = 0;
  for (int i = 0; i < 8; i++)
  {
    if (vetor[i] == numero)
    {
      encontrado = 1;
      break;
    }
  }

  // Imprimindo o resultado
  if (encontrado)
  {
    printf("SIM\n");
  }
  else
  {
    printf("NÃO\n");
  }

  return 0;
}
