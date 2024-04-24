// A prefeitura de uma cidade fez uma pesquisa com 5 pessoas, coletando dados sobre o salário e o número de filhos. A prefeitura deseja saber:
//    1.  A média do salário dessas pessoas
//    2.  A média do número de filhos
//    3.  O maior salário
//    4.  A percentagem de pessoas com salários até R$ 150,00

#include <stdio.h>

int main() {
  int total_pessoas = 5;
  float salario, total_salarios = 0, media_salario, maior_salario = 0;
  int filhos, total_filhos = 0;
  int pessoas_ate_150 = 0;

  // Loop para coletar os dados de cada pessoa
  for (int i = 1; i <= total_pessoas; i++) {
    printf("Digite o salário da pessoa %d: R$", i);
    scanf("%f", &salario);

    printf("Digite o número de filhos da pessoa %d: ", i);
    scanf("%d", &filhos);

    // Calcula a soma dos salários
    total_salarios += salario;

    // Calcula o total de filhos
    total_filhos += filhos;

    // Verifica se o salário é o maior até agora
    if (salario > maior_salario) {
      maior_salario = salario;
    }

    // Verifica se o salário é até R$ 150,00
    if (salario <= 150.00) {
      pessoas_ate_150++;
    }
  }

  // Calcula a média do salário
  media_salario = total_salarios / total_pessoas;

  // Calcula a média do número de filhos
  float media_filhos = (float) total_filhos / total_pessoas;

  // Calcula a percentagem de pessoas com salários até R$ 150,00
  float percentagem_ate_150 = (float) pessoas_ate_150 / total_pessoas * 100;

  // Exibe os resultados
  printf("\nEstatísticas da pesquisa:\n");
  printf("1. Média do salário: R$%.2f\n", media_salario);
  printf("2. Média do número de filhos: %.2f\n", media_filhos);
  printf("3. Maior salário: R$%.2f\n", maior_salario);
  printf("4. Percentagem de pessoas com salários até R$ 150,00: %.2f%%\n", percentagem_ate_150);

  return 0;
}
