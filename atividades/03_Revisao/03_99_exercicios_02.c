// Faça um programa em C que leia o salário de um funcioário e calcule o desconto de INSS dada a tabela a seguir:

//     |Salário de contribuição|Alíquota|
//     |---|---|
//     |até R$ 1.212,00|7,5%|
//     |R$ 1.212,01 até R$2.427,35|9%|
//     |R$ 2.427,36 até R$3.641,03|12%|
//     |R$ 3.641,04 até R$7.087,22|14%|
//     |acima R$7.087,22|R$828,39|

#include <stdio.h>

int main() {
    float salario, desconto_inss;

    // Solicita ao usuário o salário do funcionário
    printf("Digite o salário do funcionário: ");
    scanf("%f", &salario);

    // Calcula o desconto de INSS de acordo com a tabela
    if (salario <= 1212.00) {
        desconto_inss = salario * 0.075;
    } else if (salario <= 2427.35) {
        desconto_inss = salario * 0.09;
    } else if (salario <= 3641.03) {
        desconto_inss = salario * 0.12;
    } else if (salario <= 7087.22) {
        desconto_inss = salario * 0.14;
    } else {
        desconto_inss = 828.39;
    }

    // Exibe o desconto de INSS
    printf("O desconto de INSS é de R$%.2f\n", desconto_inss);

    return 0;
}
