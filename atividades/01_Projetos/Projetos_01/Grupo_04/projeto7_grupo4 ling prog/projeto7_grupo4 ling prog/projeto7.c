#include <stdio.h>

#define MAXIMO_INSCRICOES 100

typedef struct {
    int qntdPessoas;
    int vip; // 1-sim e 0-não
    int tipoEvento; // 1 para conferência, 2 para workshop e 3 para seminário
    int numEventos;
    int numRegistro;
    float valorTotal;
} Inscricao;

// Declarar funções
void inserirRegistro(Inscricao inscricoes[], int *qntdInscricoes);
void apresentarResultados(Inscricao inscricoes[], int qntdInscricoes);
void ordenarInscricoes(Inscricao inscricoes[], int qntdInscricoes);
void imprimirInscricoes(Inscricao inscricoes[], int qntdInscricoes);
float calcularValor(int tipoEvento, int numEventos, int vip, int qntdPessoas);

int main() {
    Inscricao inscricoes[MAXIMO_INSCRICOES];
    int opcao;
    int qntdInscricoes = 0; // contador de registro

    do {
        printf("Escolha uma opcao \n");
        printf("0 - Sair \n");
        printf("1 - Inserir mais registros \n");
        printf("2 - Apresentar resultados \n");
        printf("3 - Ordenar os registros pelo valor total da inscricao \n");
        printf("4 - Imprimir registros de inscricoes \n");
        scanf("%d", &opcao); // lê a opção selecionada pelo usuário

        switch(opcao) {
            case 0:
                printf("Encerrando.\n");
                break;

            case 1:
                inserirRegistro(inscricoes, &qntdInscricoes);
                break;

            case 2:
                apresentarResultados(inscricoes, qntdInscricoes);
                break;

            case 3:
                ordenarInscricoes(inscricoes, qntdInscricoes);
                printf("Inscricoes ordenadas por valor.\n");
                break;

            case 4:
                imprimirInscricoes(inscricoes, qntdInscricoes);
                break;

            default:
                printf("Opcao invalida\n");
        }

    } while (opcao != 0);

    return 0;
}

// Função para inserir registros
void inserirRegistro(Inscricao inscricoes[], int *qntdInscricoes) {
    if (*qntdInscricoes >= MAXIMO_INSCRICOES) {
        printf("Numero maximo de inscricoes atingido\n");
        return; // sai da função se o limite for atingido
    }

    Inscricao novoRegistro; // Declara uma variável do tipo Inscricao

    printf("Digite o Numero do Registro: \n");
    scanf("%d", &novoRegistro.numRegistro);
    printf("Digite o tipo de Evento (1 para Conferencia, 2 para Workshop e 3 para Seminario): \n");
    scanf("%d", &novoRegistro.tipoEvento);
    printf("Digite o numero de eventos: \n");
    scanf("%d", &novoRegistro.numEventos);
    printf("Evento VIP? (1 - Sim, 0 - Nao)\n");
    scanf("%d", &novoRegistro.vip);
    printf("Quantidade de pessoas: \n");
    scanf("%d", &novoRegistro.qntdPessoas);

    // Calcula o valor do evento
    novoRegistro.valorTotal = calcularValor(novoRegistro.tipoEvento, novoRegistro.numEventos, novoRegistro.vip, novoRegistro.qntdPessoas);
    // Adiciona ao array de inscricoes
    inscricoes[*qntdInscricoes] = novoRegistro;
    (*qntdInscricoes)++; // incrementa o contador

    printf("Registro inserido com sucesso!\n");
}

float calcularValor(int tipoEvento, int numEventos, int vip, int qntdPessoas) {
    float valorBase = 0;

    switch(tipoEvento) {
        case 1:
            valorBase = 500 * numEventos;
            break;
        case 2:
            valorBase = 300 * numEventos;
            break;
        case 3:
            valorBase = 200 * numEventos;
            break;
        default:
            printf("Opcao invalida\n");
            return 0.0; // mensagem de erro
    }

    if (qntdPessoas > 5) {
        valorBase *= 1.05;
    }

    if (qntdPessoas > 10) {
        valorBase *= 1.10;
    }

    if (numEventos > 2) {
        valorBase *= 1.10;
    }

    if (vip) {
        valorBase *= 1.15;
    }

    return valorBase;
}

// Função para apresentar resultados
void apresentarResultados(Inscricao inscricoes[], int qntdInscricoes) {
    if (qntdInscricoes == 0) {
        printf("Nao ha registros para apresentar.\n");
        return;
    }

    float totalValor = 0.0;
    float totalVip = 0.0;
    int numEventos = 0;
    int maiorValorIndex = 0;

    // Loop para calcular os resultados
    for (int i = 0; i < qntdInscricoes; i++) {
        totalValor += inscricoes[i].valorTotal; // acumula o valor total das inscricoes

        // Se a inscricao é vip
        if (inscricoes[i].vip == 1) {
            totalVip += inscricoes[i].valorTotal;
        }

        // Verifica se a inscricao atual tem um valor maior que o maior atual até agora
        if (inscricoes[i].valorTotal > inscricoes[maiorValorIndex].valorTotal) {
            maiorValorIndex = i; // atualiza o índice do maior valor
        }

        numEventos += inscricoes[i].numEventos;
    }

    float mediaValor = totalValor / qntdInscricoes;
    float mediaVip = (totalVip > 0) ? (totalVip / (totalVip / numEventos)) : 0; // não dividir por 0
    float percentualConferencias = 0.0;
    int conferencias = 0;

    for (int i = 0; i < qntdInscricoes; i++) {
        if (inscricoes[i].tipoEvento == 1) {
            conferencias++;
        }
    }

    percentualConferencias = (float)conferencias / qntdInscricoes * 100;

    // Mostrar resultados
    printf("Media das inscricoes: %.2f\n", mediaValor);
    printf("Media dos eventos VIP: %.2f\n", mediaVip);
    printf("Inscricao com maior valor: %d\n", inscricoes[maiorValorIndex].numRegistro);
    printf("Percentual das inscricoes para conferencias: %.2f%%\n", percentualConferencias);
    printf("Total de eventos inscritos: %d\n", numEventos);
}

// Função para imprimir inscrições
void imprimirInscricoes(Inscricao inscricoes[], int qntdInscricoes) {
    if (qntdInscricoes == 0) {
        printf("Nao ha registros.\n");
        return; // sai da função caso não tenha registros
    }

    for (int i = 0; i < qntdInscricoes; i++) {
        printf("Registro %d: Tipo de Evento: %d, Numero de Eventos: %d, VIP: %d, Pessoas: %d, Valor Total: %.2f\n",
            inscricoes[i].numRegistro, inscricoes[i].tipoEvento,
            inscricoes[i].numEventos, inscricoes[i].vip,
            inscricoes[i].qntdPessoas, inscricoes[i].valorTotal);
    }
}

// Implementação da função para ordenar inscrições
void ordenarInscricoes(Inscricao inscricoes[], int qntdInscricoes) {
    for (int i = 0; i < qntdInscricoes - 1; i++) {
        for (int j = 0; j < qntdInscricoes - i - 1; j++) {
            // Troca se o valor total da inscrição atual for maior que o próximo
            if (inscricoes[j].valorTotal > inscricoes[j + 1].valorTotal) {
                Inscricao temp = inscricoes[j];
                inscricoes[j] = inscricoes[j + 1];
                inscricoes[j + 1] = temp;
            }
        }
    }
}
