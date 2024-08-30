// Criar um programa em C que converta um valor em reais (BRL) para dólares (USD), usando a cotação do dólar informada pelo usuário.
#include <stdio.h>

int main() {
    float valor_em_reais, cotacao_dolar, valor_em_dolares;

    // Solicita ao usuário o valor em reais e a cotação do dólar
    printf("Digite o valor em reais (BRL): ");
    scanf("%f", &valor_em_reais);

    printf("Digite a cotação do dólar (USD): ");
    scanf("%f", &cotacao_dolar);

    // Calcula o valor em dólares
    valor_em_dolares = valor_em_reais / cotacao_dolar;

    // Exibe o resultado
    printf("%.2f BRL equivalem a %.2f USD\n", valor_em_reais, valor_em_dolares);

    return 0;
}
