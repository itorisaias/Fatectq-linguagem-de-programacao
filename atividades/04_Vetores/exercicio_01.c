// Enunciado: Escreva um programa em C que receba 5 números inteiros do usuário e os armazene em um vetor. Em seguida, o programa deve calcular e imprimir a soma, maior e o menor desses números e inverter a ordem dos elementos do vetor e imprimir o vetor resultante.

// Entrada:
// 2
// 5
// 3
// 1
// 4

// Saida:
// soma: 15
// maior: 5
// menor: 1
// invertido: 4 1 3 5 2

#include <stdio.h>

int main()
{
  int numeros[5];
  int soma = 0;

  printf("Digite 5 numeros inteiros:\n");

  // soma
  for (int i = 0; i < 5; i++)
  {
    scanf("%d", &numeros[i]);
    soma += numeros[i];
  }
  printf("soma: %d\n", soma);

  // maior e menor
  int maior, menor;
  maior = menor = numeros[0];
  for (int i = 1; i < 5; i++)
  {
    if (numeros[i] > maior)
      maior = numeros[i];

    if (numeros[i] < menor)
      menor = numeros[i];
  }
  printf("maior: %d\n", maior);
  printf("menor: %d\n", menor);

  // invertido
  int vetor_invertido[5];
  printf("invertido: ");
  for (int i = 0; i < 6; i++)
    vetor_invertido[i] = numeros[5 - i];
  for (int i = 0; i < 6; i++)
    printf("%d ", vetor_invertido[i]);

  return 0;
}
