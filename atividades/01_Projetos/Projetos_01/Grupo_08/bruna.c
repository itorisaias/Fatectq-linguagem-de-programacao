#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define MAX_CONTRATOS 100

typedef struct {
    int numero_contrato;
    int tipo_servico;
    int quantidade_pecas;
    int manchas_dificeis;
    int la_seda;
    float valor_total;
} Contrato;

void inserir_contratos(Contrato contratos[]);
void apresentar_resultados(Contrato contratos[], int num_contratos);
void ordenar_contratos(Contrato contratos[], int num_contratos);
void imprimir_registros(Contrato contratos[], int num_contratos);
float valor_total_calcular(int tipo_servico, int quantidade_pecas, int manchas_dificeis, int la_seda);
float desconto_calcular(int quantidade_pecas, float valor_total);
float adicional_calcular(int quantidade_pecas, int manchas_dificeis, int la_seda);

Contrato contratos[MAX_CONTRATOS];
int num_contratos = 0;

void menu_inicial() {
    setlocale(LC_ALL, "Portuguese");
    int opcao;

    do {
        system("cls");
        printf("--- Menu de Opções ---\n");
        printf("0 - Sair\n");
        printf("1 - Inserir\n");
        printf("2 - Apresentar resultados\n");
        printf("3 - Ordenar contratos\n");
        printf("4 - Imprimir registros\n");
        printf("Escolha uma opção: \n");
        scanf("%d", &opcao);

        switch(opcao) {
            case 0:
                printf("Encerrando...\n");
                break;
            case 1:
                inserir_contratos(contratos);
                break;
            case 2:
                apresentar_resultados(contratos, num_contratos);
                break;
            case 3:
                ordenar_contratos(contratos, num_contratos);
                break;
            case 4:
                imprimir_registros(contratos, num_contratos);
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
        system("pause");
    } while (opcao != 0);
}

void inserir_contratos(Contrato contratos[]) {
    if (num_contratos >= MAX_CONTRATOS) {
        printf("Quantidade máxima de contratos atingida!\n");
        return;
    }

    Contrato adicionar_contrato;
    printf("Número do contrato: ");
    scanf("%d", &adicionar_contrato.numero_contrato);
    printf("Tipo de serviço (1 - Lavagem Padrão, 2 - Lavagem Delicada, 3 - Lavagem a Seco): ");
    scanf("%d", &adicionar_contrato.tipo_servico);
    printf("Quantidade de peças: ");
    scanf("%d", &adicionar_contrato.quantidade_pecas);
    printf("Roupas com manchas difíceis (1 - Sim, 0 - Não): ");
    scanf("%d", &adicionar_contrato.manchas_dificeis);
    printf("Roupas de lã e/ou seda (1 - Sim, 0 - Não): ");
    scanf("%d", &adicionar_contrato.la_seda);

    adicionar_contrato.valor_total = valor_total_calcular(adicionar_contrato.tipo_servico, adicionar_contrato.quantidade_pecas, adicionar_contrato.manchas_dificeis, adicionar_contrato.la_seda);
    contratos[num_contratos] = adicionar_contrato;
    num_contratos++; // Incrementa a variável global
}

void apresentar_resultados(Contrato contratos[], int num_contratos) {
    if (num_contratos == 0) {
        printf("Nenhum contrato encontrado!\n");
        return;
    }

    float total_soma = 0.0;
    float manchas_soma = 0.0;
    float max_valor = 0.0;
    int manchas_total = 0;
    int max_contrato = 0;
    int contratos_acima_50 = 0;
    int pecasDelicadas_total = 0;

    for (int i = 0; i < num_contratos; i++) {
        total_soma += contratos[i].valor_total;
        if (contratos[i].manchas_dificeis) {
            manchas_soma += contratos[i].valor_total;
            manchas_total++;
        }
        if (contratos[i].valor_total > max_valor) {
            max_valor = contratos[i].valor_total;
            max_contrato = contratos[i].numero_contrato;
        }
        if (contratos[i].quantidade_pecas > 50) {
            contratos_acima_50++;
        }
        if (contratos[i].tipo_servico == 2) {
            pecasDelicadas_total += contratos[i].quantidade_pecas;
        }
    }

    printf("A média do valor total dos contratos: R$ %.2f\n", total_soma / num_contratos);

    if (manchas_total > 0) {
        printf("Média dos contratos que possuem roupas com manchas difíceis: R$ %.2f\n", manchas_soma / manchas_total);
    } else {
        printf("Nenhum contrato de roupas com manchas difíceis encontrado!\n");
    }
    printf("O número do contrato com maior valor total: %d\n", max_contrato);
    printf("O percentual dos contratos que possuem mais de 50 peças em relação ao número total de contratos: %.2f%%\n", (float)contratos_acima_50 / num_contratos * 100);
    printf("O total de peças de roupas delicadas lavadas: %d peças\n", pecasDelicadas_total);
}

void ordenar_contratos(Contrato contratos[], int num_contratos) {
    for (int i = 0; i < num_contratos - 1; i++) {
        for (int j = i + 1; j < num_contratos; j++) {
            if (contratos[i].valor_total < contratos[j].valor_total) {
                Contrato temp = contratos[i];
                contratos[i] = contratos[j];
                contratos[j] = temp;
            }
        }
    }

    printf("Contratos ordenados pelo valor total (decrescente):\n");
    printf(" | Número | Tipo Serviço | Qtde Peças | Manchas Difíceis | Lã/Seda | Valor Total |\n");
    for (int i = 0; i < num_contratos; i++) {
        printf(" | %d | %d | %d | %s | %s | R$ %.2f |\n",
               contratos[i].numero_contrato,
               contratos[i].tipo_servico,
               contratos[i].quantidade_pecas,
               contratos[i].manchas_dificeis ? "Sim" : "Não",
               contratos[i].la_seda ? "Sim" : "Não",
               contratos[i].valor_total);
    }
}

void imprimir_registros(Contrato contratos[], int num_contratos) {
    if (num_contratos == 0) {
        printf("Nenhum contrato para exibir.\n");
        return;
    }

    printf("\nRegistros dos Contratos:\n");
    for (int i = 0; i < num_contratos; i++) {
        printf("Número do Contrato: %d\n", contratos[i].numero_contrato);
        printf("Tipo de Serviço: %d\n", contratos[i].tipo_servico);
        printf("Quantidade de Peças: %d\n", contratos[i].quantidade_pecas);
        printf("Roupas com Manchas Difíceis: %s\n", contratos[i].manchas_dificeis ? "Sim" : "Não");
        printf("Roupas de Lã e/ou Seda: %s\n", contratos[i].la_seda ? "Sim" : "Não");
        printf("Valor Total: R$ %.2f\n\n", contratos[i].valor_total);
    }
}

float valor_total_calcular(int tipo_servico, int quantidade_pecas, int manchas_dificeis, int la_seda) {
    float valor_base = 0.0;

    switch (tipo_servico) {
    case 1:
        valor_base = 50.0;
        break;
    case 2:
        valor_base = 75.0;
        break;
    case 3:
        valor_base = 100.0;
        break;
    default:
        valor_base = 0.0;
        break;
    }

    valor_base += quantidade_pecas * 5.0;
    valor_base += adicional_calcular(quantidade_pecas, manchas_dificeis, la_seda);
    valor_base -= desconto_calcular(quantidade_pecas, valor_base);

    return valor_base;
}

float desconto_calcular(int quantidade_pecas, float valor_total) {
    if (quantidade_pecas > 10) {
        return valor_total * 0.1;
    }
    return 0.0;
}

float adicional_calcular(int quantidade_pecas, int manchas_dificeis, int la_seda) {
    float adicional = 0.0;

    if (manchas_dificeis) {
        adicional += 20.0;
    }
    if (la_seda) {
        adicional += 30.0;
    }
    return adicional;
}

int main (){
    menu_inicial();
    return 0;
}
