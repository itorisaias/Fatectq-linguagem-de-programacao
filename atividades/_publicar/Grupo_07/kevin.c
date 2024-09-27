#include <stdio.h>

#define MAX_INSCRICOES 100

int numeros_inscricao[MAX_INSCRICOES];
int tipos_evento[MAX_INSCRICOES];
int numeros_eventos[MAX_INSCRICOES];
int eventos_vip[MAX_INSCRICOES];
int qtd_pessoas[MAX_INSCRICOES];
float valores_totais[MAX_INSCRICOES];
int total_inscricoes = 0;

// Funções de Calculo
float calcular_valor_inscricao(int tipo_evento, int numero_eventos, int qtd_pessoas, int evento_vip) {
    float valor_base = 0;
    switch (tipo_evento) {
        case 1: valor_base = 500.0; break;  // Conferência
        case 2: valor_base = 300.0; break;  // Workshop
        case 3: valor_base = 200.0; break;  // Seminário
    }

    float valor_total = valor_base * numero_eventos;

    // Ajuste por numero de pessoas
    if (qtd_pessoas > 5 && qtd_pessoas <= 10) {
        valor_total *= 1.05;
    } else if (qtd_pessoas > 10) {
        valor_total *= 1.10;
    }

    // Ajuste para evento VIP
    if (evento_vip) {
        valor_total *= 1.15;
    }

    // Ajuste se houver mais de 2 eventos
    if (numero_eventos > 2) {
        valor_total *= 1.10;
    }

    return valor_total;
}

float calcular_soma_total() {
    float soma = 0;
    for (int i = 0; i < total_inscricoes; i++) {
        soma += valores_totais[i];
    }
    return soma;
}

float calcular_media_total() {
    if (total_inscricoes == 0) return 0;
    return calcular_soma_total() / total_inscricoes;
}

float calcular_media_vip() {
    int count_vip = 0;
    float soma_vip = 0;
    for (int i = 0; i < total_inscricoes; i++) {
        if (eventos_vip[i]) {
            soma_vip += valores_totais[i];
            count_vip++;
        }
    }
    return (count_vip > 0) ? (soma_vip / count_vip) : 0;
}

float calcular_percentual_conferencias() {
    int count_conferencias = 0;
    for (int i = 0; i < total_inscricoes; i++) {
        if (tipos_evento[i] == 1) {
            count_conferencias++;
        }
    }
    return (total_inscricoes > 0) ? ((float)count_conferencias / total_inscricoes) * 100 : 0;
}

int calcular_total_eventos_inscritos() {
    int total_eventos = 0;
    for (int i = 0; i < total_inscricoes; i++) {
        total_eventos += numeros_eventos[i];
    }
    return total_eventos;
}

// Funções de Controle
void adicionar_inscricao(int numero, int tipo, int eventos, int vip, int pessoas) {
    if (total_inscricoes < MAX_INSCRICOES) {
        numeros_inscricao[total_inscricoes] = numero;
        tipos_evento[total_inscricoes] = tipo;
        numeros_eventos[total_inscricoes] = eventos;
        eventos_vip[total_inscricoes] = vip;
        qtd_pessoas[total_inscricoes] = pessoas;
        valores_totais[total_inscricoes] = calcular_valor_inscricao(tipo, eventos, pessoas, vip);
        total_inscricoes++;
    } else {
        printf("Limite de inscrições atingido.\n");
    }
}

void imprimir_inscricoes() {
    for (int i = 0; i < total_inscricoes; i++) {
        printf("Inscrição %d: R$ %.2f\n", numeros_inscricao[i], valores_totais[i]);
    }
}

void apresentar_resultados() {
    printf("Soma total das inscrições: R$ %.2f\n", calcular_soma_total());
    printf("Média de todas as inscrições: R$ %.2f\n", calcular_media_total());
    printf("Média das inscrições VIP: R$ %.2f\n", calcular_media_vip());
    printf("Percentual de inscrições para conferências: %.2f%%\n", calcular_percentual_conferencias());
    printf("Total de eventos inscritos: %d\n", calcular_total_eventos_inscritos());
}

void ordenar_por_valor() {
    for (int i = 0; i < total_inscricoes - 1; i++) {
        for (int j = i + 1; j < total_inscricoes; j++) {
            if (valores_totais[i] < valores_totais[j]) {
                
                float temp_valor = valores_totais[i];
                valores_totais[i] = valores_totais[j];
                valores_totais[j] = temp_valor;

                int temp_num = numeros_inscricao[i];
                numeros_inscricao[i] = numeros_inscricao[j];
                numeros_inscricao[j] = temp_num;

                int temp_tipo = tipos_evento[i];
                tipos_evento[i] = tipos_evento[j];
                tipos_evento[j] = temp_tipo;

                int temp_eventos = numeros_eventos[i];
                numeros_eventos[i] = numeros_eventos[j];
                numeros_eventos[j] = temp_eventos;

                int temp_vip = eventos_vip[i];
                eventos_vip[i] = eventos_vip[j];
                eventos_vip[j] = temp_vip;

                int temp_pessoas = qtd_pessoas[i];
                qtd_pessoas[i] = qtd_pessoas[j];
                qtd_pessoas[j] = temp_pessoas;
            }
        }
    }
}

// Interfaces para o Usuário
void inserir_inscricao() {
    int numero, tipo, eventos, vip, pessoas;

    // Validação do número de inscrição
    printf("Digite o número da inscrição: ");
    scanf("%d", &numero);
    if (numero <= 0) {
        printf("Número de inscrição inválido. Voltando ao menu...\n");
        return;
    }

    // Validação do tipo de evento
    printf("Digite o tipo de evento (1: Conferência, 2: Workshop, 3: Seminário): ");
    scanf("%d", &tipo);
    if (tipo < 1 || tipo > 3) {
        printf("Tipo de evento inválido. Voltando ao menu...\n");
        return;
    }

    // Validação do número de eventos
    printf("Digite o número de eventos: ");
    scanf("%d", &eventos);
    if (eventos <= 0) {
        printf("Número de eventos inválido. Voltando ao menu...\n");
        return;
    }

    // Validação do evento VIP
    printf("O evento é VIP? (1: Sim, 0: Não): ");
    scanf("%d", &vip);
    if (vip != 0 && vip != 1) {
        printf("Valor inválido para VIP. Voltando ao menu...\n");
        return;
    }

    // Validação da quantidade de pessoas
    printf("Digite a quantidade de pessoas: ");
    scanf("%d", &pessoas);
    if (pessoas <= 0) {
        printf("Quantidade de pessoas inválida. Voltando ao menu...\n");
        return;
    }

    adicionar_inscricao(numero, tipo, eventos, vip, pessoas);
}

void menu() {
    int opcao;
    do {
        printf("0 - Sair\n");
        printf("1 - Inserir Inscrição\n");
        printf("2 - Apresentar Resultados\n");
        printf("3 - Ordenar Inscrições\n");
        printf("4 - Imprimir Todas as Inscrições\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                inserir_inscricao();
                break;
            case 2:
                apresentar_resultados();
                break;
            case 3:
                ordenar_por_valor();
                break;
            case 4:
                imprimir_inscricoes();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Voltando ao menu...\n");
        }
    } while (opcao != 0);
}

// Função principal
int main() {
    menu();
    return 0;
}