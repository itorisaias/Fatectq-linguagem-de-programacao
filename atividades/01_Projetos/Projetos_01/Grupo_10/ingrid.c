#include <stdio.h>

#define MAX_RESERVAS 100

// criando variaveis para armazenar os valores de entrada
int numeroReserva[MAX_RESERVAS];
int tipoQuarto[MAX_RESERVAS];
int numeroNoites[MAX_RESERVAS];
int numeroPessoasCafe[MAX_RESERVAS];
int estacionamento[MAX_RESERVAS];
float valorTotal[MAX_RESERVAS];
int totalReservas = 0;

// calculando o valor total das reservas
float calcularValorTotal(int tipo, int noites, int pessoasCafe, int estacionamento) {
    float valorBase = 0, custoAdicional = 0;

// definindo valor do quarto
    if (tipo == 1) valorBase = 100 * noites;
    else if (tipo == 2) valorBase = 150 * noites;
    else if (tipo == 3) valorBase = 250 * noites;

// custos adicionais
    custoAdicional = pessoasCafe * 20 * noites;
    if (estacionamento == 1) custoAdicional += 30 * noites;

    return valorBase + custoAdicional;
}

// inserindo uma nova reserva
void inserirReserva() {
    if (totalReservas >= MAX_RESERVAS) {
        printf("Limite de reservas atingido.\n");
        return;
    }

    printf("Inserir dados da reserva #%d:\n", totalReservas + 1);

// verifica os tipos de quarto
    do {
        printf("Tipo de quarto (1: Simples, 2: Duplo, 3: Suite): ");
        scanf("%d", &tipoQuarto[totalReservas]);
        if (tipoQuarto[totalReservas] < 1 || tipoQuarto[totalReservas] > 3) {
            printf("Opcao invalida! Por favor, escolha entre 1 (Simples), 2 (Duplo) ou 3 (Suite).\n");
        }
    } while (tipoQuarto[totalReservas] < 1 || tipoQuarto[totalReservas] > 3);

// pedindo ao usuario os dados da reserva
    printf("Numero de noites: ");
    scanf("%d", &numeroNoites[totalReservas]);
    printf("Numero de pessoas para cafe da manha: ");
    scanf("%d", &numeroPessoasCafe[totalReservas]);

// verificando se usou ou nao o estacionamento
    do {
        printf("Estacionamento (1: Sim, 0: Nao): ");
        scanf("%d", &estacionamento[totalReservas]);
        if (estacionamento[totalReservas] < 0 || estacionamento[totalReservas] > 1) {
            printf("Opcao invalida! Escolha 1 para (Sim) ou 0 para (Nao).\n");
        }
    } while (estacionamento[totalReservas] < 0 || estacionamento[totalReservas] > 1);

// fazendo a soma total da reserva
    valorTotal[totalReservas] = calcularValorTotal(tipoQuarto[totalReservas], numeroNoites[totalReservas], numeroPessoasCafe[totalReservas], estacionamento[totalReservas]);

// definindo o n da reserva
    numeroReserva[totalReservas] = totalReservas + 1;
    totalReservas++;
    printf("Reserva inserida! Valor Total: R$ %.2f\n", valorTotal[totalReservas - 1]);
}

// função para apresentar os resultados e insights
void apresentarResultados() {
    if (totalReservas == 0) {
        printf("Nenhuma reserva registrada.\n");
        return;
    }

    float somaTotal = 0, somaCafe = 0;
    int contadorCafe = 0, contadorEstacionamento = 0, totalNoites = 0;
    int maiorValorReserva = 0;
    float maiorValor = 0;

// calculando os resultados
    for (int i = 0; i < totalReservas; i++) {
        somaTotal += valorTotal[i];
        totalNoites += numeroNoites[i];

        if (numeroPessoasCafe[i] > 0) {
            somaCafe += valorTotal[i];
            contadorCafe++;
        }

        if (estacionamento[i] == 1) {
            contadorEstacionamento++;
        }

        if (valorTotal[i] > maiorValor) {
            maiorValor = valorTotal[i];
            maiorValorReserva = numeroReserva[i];
        }
    }

// mostrando os resultados
    printf("\nResultados:\n");
    printf("1. A media do valor de todas as reservas: R$ %.2f\n", somaTotal / totalReservas);
    if (contadorCafe > 0) {
        printf("2. A media das reservas com cafe da manha: R$ %.2f\n", somaCafe / contadorCafe);
    } else {
        printf("2. A media das reservas com cafe da manha: N/A\n");
    }
    printf("3. O numero da reserva com maior valor: %d\n", maiorValorReserva);
    printf("4. O percentual das reservas com estacionamento: %.2f%%\n", (contadorEstacionamento / (float)totalReservas) * 100);
    printf("5. O total geral de noites reservadas: %d\n", totalNoites);
}

// Função para imprimir todas as reservas
void imprimirReservas() {
    if (totalReservas == 0) {
        printf("Nenhuma reserva registrada.\n");
        return;
    }

    printf("\n Registros de Reservas \n");
    for (int i = 0; i < totalReservas; i++) {
        printf("Reserva #%d: Tipo: %d, Noites: %d, Pessoas Cafe: %d, Estacionamento: %d, Valor Total: R$ %.2f\n",
               numeroReserva[i], tipoQuarto[i], numeroNoites[i], numeroPessoasCafe[i], estacionamento[i], valorTotal[i]);
    }
}

// criacao do menu
int main() {
    int opcao;

    do {
        printf("\n Menu de Opcoes \n");
        printf("0. Sair\n");
        printf("1. Inserir mais registros\n");
        printf("2. Apresentar resultados\n");
        printf("3. Imprimir registros de reservas\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                printf("Saindo...\n");
                break;
            case 1:
                inserirReserva();
                break;
            case 2:
                apresentarResultados();
                break;
            case 3:
                imprimirReservas();
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
