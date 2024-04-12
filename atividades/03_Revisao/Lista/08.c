// Faça um programa em C que receba a idade de 5 pessoas e mostre quantas são maiores que 18 anos.

#include <stdio.h>

int main() {
  int idade, maiores_que_18 = 0;

  // Loop para receber a idade de 5 pessoas
  for (int i = 1; i <= 5; i++) {
    printf("Digite a idade da pessoa %d: ", i);
    scanf("%d", &idade);

    // Verifica se a idade é maior que 18
    if (idade > 18) {
      maiores_que_18++;
    }
  }

  // Mostra o número de pessoas com idade maior que 18
  printf("O número de pessoas com idade maior que 18 é: %d\n", maiores_que_18);

  return 0;
}
