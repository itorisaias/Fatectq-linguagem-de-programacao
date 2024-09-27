#include <stdio.h>
#define MAX_PEDIDOS 100
//Função para calcular o valor total de um pedido.
float calcularValorTotal(int tipoPacote, int adicional, int frequencia, int clienteRecorrente) {
    float valorBase;
    float acrescimo;
    float desconto = 0.0;

    switch (tipoPacote) {
        case 1:
            valorBase = 100.0;
            break;
        case 2:
            valorBase = 180.0;
            break;
        case 3:
            valorBase = 250.0;
            break;
        default:
            printf("Tipo de pacote invalido!\n");
            return 0;
    }

    switch (adicional) {
        case 1:
            acrescimo = valorBase * 0.15;
            break;
        case 2:
            acrescimo = valorBase * 0.10;
            break;
        case 3:
            acrescimo = valorBase * 0.20;
            break;
        case 0:
            acrescimo = 0.0;
            break;
        default:
            printf("Adicional invalido!\n");
            return 0;
    }

    if (frequencia == 12)
        desconto += valorBase * 0.15;
    if (clienteRecorrente == 1)
        desconto += valorBase * 0.10;

    return (valorBase + acrescimo - desconto) * frequencia;
}
//Função para inserir pedidos.
void inserirPedido(int numeros[], int tipos[], int adicionais[], int frequencias[], int recorrentes[], float totais[], int *totalPedidos) {
    if (*totalPedidos >= 100) {
        printf("Limite de pedidos atingido.\n");
        return;
    }

    int tipo, adicional, frequencia, recorrente;

    printf("Tipo de pacote (1 - Basico, 2 - Completo, 3 - Premium): ");
    scanf("%d", &tipo);

    printf("Adicional (0 - Nenhum, 1 - Janelas, 2 - Tapetes, 3 - Áreas Externas): ");
    scanf("%d", &adicional);

    printf("Frequência (1 - Unica, 4 - 4x por mes, 12 - Anual): ");
    scanf("%d", &frequencia);

    printf("Cliente recorrente? (1 - Sim, 0 - Nao): ");
    scanf("%d", &recorrente);

    float valorTotal = calcularValorTotal(tipo, adicional, frequencia, recorrente);

    numeros[*totalPedidos] = *totalPedidos + 1;
    tipos[*totalPedidos] = tipo;
    adicionais[*totalPedidos] = adicional;
    frequencias[*totalPedidos] = frequencia;
    recorrentes[*totalPedidos] = recorrente;
    totais[*totalPedidos] = valorTotal;

    (*totalPedidos)++;
}

//Função para imprimir todos os pedidos.
void imprimirPedidos(int numeros[], int tipos[], int adicionais[], int frequencias[], int recorrentes[], float totais[], int totalPedidos) {
        printf("\nRegistros de Pedidos:\n");
    for (int i = 0; i < totalPedidos; i++) {
        printf("Pedido #%d | Pacote: %d | Adicional: %d | Frequencia: %d | Recorrente: %d | Valor Total: R$ %.2f\n", numeros[i], tipos[i], adicionais[i], frequencias[i], recorrentes[i], totais[i]);
    }
}
//Função para calcular a média dos valores dos pedidos.
void calcularMedia(float totais[], int totalPedidos) {
    float soma = 0.0;
    for (int i = 0; i < totalPedidos; i++) {
        soma += totais[i];
    }

    printf("Media do valor dos pedidos: R$ %.2f\n", soma / totalPedidos);
}
int main() {
    int numeros[MAX_PEDIDOS], tipos[MAX_PEDIDOS], adicionais[MAX_PEDIDOS], frequencias[MAX_PEDIDOS], recorrentes[MAX_PEDIDOS];
    float totais[MAX_PEDIDOS];
    int totalPedidos = 0;
    int opcao;

    do {
        printf("\nMenu de Opcoes:\n");
        printf("1. Inserir novo pedido\n");
        printf("2. Imprimir pedidos\n");
        printf("3. Calcular media dos pedidos\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirPedido(numeros, tipos, adicionais, frequencias, recorrentes, totais, &totalPedidos);
                break;
            case 2:
                imprimirPedidos(numeros, tipos, adicionais, frequencias, recorrentes, totais, totalPedidos);
                break;
            case 3:
                calcularMedia(totais, totalPedidos);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
