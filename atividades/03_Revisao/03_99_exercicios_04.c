// Faça um programa em C (com a estrutura do...while) que leia 5 valores inteiros e:
//    1. Encontre e mostre o maior valor;
//    2. Encontre e mostre o menor valor;
//    3. Calcule e mostre a média dos números lidos;

#include <stdio.h>

int main() {
    int valor, contador = 0, maior, menor, soma = 0;
    float media;

    // Lê o primeiro valor
    printf("Digite o valor %d: ", contador + 1);
    scanf("%d", &valor);

    // Define o primeiro valor como maior e menor inicialmente
    maior = valor;
    menor = valor;

    // Soma o primeiro valor para calcular a média
    soma += valor;

    // Incrementa o contador
    contador++;

    // Continua a leitura dos valores usando a estrutura do-while
    do {
        printf("Digite o valor %d: ", contador + 1);
        scanf("%d", &valor);

        // Atualiza o maior valor, se necessário
        if (valor > maior) {
            maior = valor;
        }

        // Atualiza o menor valor, se necessário
        if (valor < menor) {
            menor = valor;
        }

        // Soma o valor para calcular a média
        soma += valor;

        // Incrementa o contador
        contador++;
    } while (contador < 5);

    // Calcula a média
    media = (float) soma / 5;

    // Mostra os resultados
    printf("\nMaior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);
    printf("Média dos valores: %.2f\n", media);

    return 0;
}
