#include <stdio.h>

int main() {

  int soma = 0, n;

  // o scanf ele retorna um inteiro que é quantidade de números que consegui converter conforme voce solicitou no primeiro parâmetro, então verificamos enquanto o retorno for igual á 1, continue lendo.
  while (scanf("%d", &n) == 1)
  {
    soma += n;
  }

  // Leia duas variáveis do tipo inteiro de uma vez só
  // scanf("%d %d", &n1, &n2); // 9 8

  // Ignorando dados de entrada, o * ignora os valores mapeados
  // scanf("%*s %d", &soma); // banana 1

  // Lendo padrões
  // scanf("%d:%d:%d", &h, &m: &s); // 23:35:18

  printf("soma de todos numeros é: %d", soma);

  return 0;
}
