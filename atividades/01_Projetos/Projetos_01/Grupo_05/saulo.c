#include <stdio.h>

#define MAX_CONTRATOS 100

//Enzo Stoque Zeferino 0220482413042
// Saulo Pereira da Silva 0220482413006
// Gabriely Sassi 0220482413048

// Definição da estrutura para armazenar os contratos
typedef struct {
    int numero_contrato;
    int tipo_projeto; // 1 para Residencial, 2 para Comercial, 3 para Industrial
    float area_projeto; // em metros quadrados
    int complexidade; // 1 para Baixa, 2 para Média, 3 para Alta
    int cliente_corporativo; // 1 para sim, 0 para não
    float valor_base;
    float desconto_tamanho;
    float desconto_adicional;
    float custo_adicional;
    float valor_total;
} Contrato;

Contrato contratos[MAX_CONTRATOS];
int num_contratos = 0;

// Função para inserir um novo contrato
void inserir_contrato() {
    if (num_contratos < MAX_CONTRATOS) {
        printf("Informe o numero do contrato: ");
        scanf("%d", &contratos[num_contratos].numero_contrato);
        printf("Informe o tipo de projeto (1 para Residencial, 2 para Comercial, 3 para Industrial): ");
        scanf("%d", &contratos[num_contratos].tipo_projeto);
        printf("Informe a area do projeto (em metros quadrados): ");
        scanf("%f", &contratos[num_contratos].area_projeto);
        printf("Informe a complexidade (1 para Baixa, 2 para Media, 3 para Alta): ");
        scanf("%d", &contratos[num_contratos].complexidade);
        printf("É cliente corporativo? (1 para sim, 0 para nao): ");
        scanf("%d", &contratos[num_contratos].cliente_corporativo);

        // Calcular valor base
        switch (contratos[num_contratos].tipo_projeto) {
            case 1:
                contratos[num_contratos].valor_base = contratos[num_contratos].area_projeto * 1000.0;
                break;
            case 2:
                contratos[num_contratos].valor_base = contratos[num_contratos].area_projeto * 1500.0;
                break;
            case 3:
                contratos[num_contratos].valor_base = contratos[num_contratos].area_projeto * 2000.0;
                break;
        }

        // Calcular desconto por tamanho
        if (contratos[num_contratos].area_projeto <= 100) {
            contratos[num_contratos].desconto_tamanho = 0.0;
        } else if (contratos[num_contratos].area_projeto <= 500) {
            contratos[num_contratos].desconto_tamanho = contratos[num_contratos].valor_base * 0.05;
        } else {
            contratos[num_contratos].desconto_tamanho = contratos[num_contratos].valor_base * 0.10;
        }

        // Calcular desconto adicional
        if (contratos[num_contratos].cliente_corporativo) {
            contratos[num_contratos].desconto_adicional = contratos[num_contratos].valor_base * 0.05;
        } else {
            contratos[num_contratos].desconto_adicional = 0.0;
        }

        // Calcular custo adicional
        switch (contratos[num_contratos].complexidade) {
            case 1:
                contratos[num_contratos].custo_adicional = 500.0;
                break;
            case 2:
                contratos[num_contratos].custo_adicional = 1000.0;
                break;
            case 3:
                contratos[num_contratos].custo_adicional = 2000.0;
                break;
        }

        // Calcular valor total
        contratos[num_contratos].valor_total = contratos[num_contratos].valor_base
                                             - contratos[num_contratos].desconto_tamanho
                                             - contratos[num_contratos].desconto_adicional
                                             + contratos[num_contratos].custo_adicional;

        num_contratos++;
    } else {
        printf("Número máximo de contratos atingido.\n");
    }
}

// Função para exibir os resultados
void apresentar_resultados() {
    float soma_valor_total = 0.0;
    int total_clientes_corporativos = 0;
    int total_projetos_grandes = 0;
    int total_residenciais = 0;
    int total_comerciais = 0;
    int total_industriais = 0;

    for (int i = 0; i < num_contratos; i++) {
        soma_valor_total += contratos[i].valor_total;
        if (contratos[i].cliente_corporativo) {
            total_clientes_corporativos++;
        }
        if (contratos[i].area_projeto > 500) {
            total_projetos_grandes++;
        }
        switch (contratos[i].tipo_projeto) {
            case 1:
                total_residenciais++;
                break;
            case 2:
                total_comerciais++;
                break;
            case 3:
                total_industriais++;
                break;
        }
    }

    float media_valor_total = soma_valor_total / num_contratos;
    float media_valor_clientes_corporativos = soma_valor_total / total_clientes_corporativos;
    int indice_contrato_mais_caro = 0;
    for (int i = 1; i < num_contratos; i++) {
        if (contratos[i].valor_total > contratos[indice_contrato_mais_caro].valor_total) {
            indice_contrato_mais_caro = i;
        }
    }
    float percentual_projetos_grandes = (float)total_projetos_grandes / num_contratos * 100.0;

    printf("Média do valor total: R$ %.2f\n", media_valor_total);
    printf("Média do valor para clientes corporativos: R$ %.2f\n", media_valor_clientes_corporativos);
    printf("Contrato com maior valor total: %d\n", contratos[indice_contrato_mais_caro].numero_contrato);
    printf("Percentual de projetos grandes: %.2f%%\n", percentual_projetos_grandes);
    printf("Número de projetos residenciais: %d\n", total_residenciais);
    printf("Número de projetos comerciais: %d\n", total_comerciais);
    printf("Número de projetos industriais: %d\n", total_industriais);
}

// Função para ordenar os contratos pelo valor total (decrescente)
void ordenar_contratos() {
    for (int i = 0; i < num_contratos - 1; i++) {
        for (int j = i + 1; j < num_contratos; j++) {
            if (contratos[j].valor_total > contratos[i].valor_total) {
                Contrato temp = contratos[i];
                contratos[i] = contratos[j];
                contratos[j] = temp;
            }
        }
    }
}

// Função para imprimir os registros de contratos
void imprimir_registros_contratos() {
    for (int i = 0; i < num_contratos; i++) {
        printf("Contrato %d:\n", contratos[i].numero_contrato);
        printf("  Tipo de projeto: %d\n", contratos[i].tipo_projeto);
        printf("  Área do projeto: %.2f m²\n", contratos[i].area_projeto);
        printf("  Complexidade: %d\n", contratos[i].complexidade);
        printf("  Cliente corporativo: %d\n", contratos[i].cliente_corporativo);
        printf("  Valor base: R$ %.2f\n", contratos[i].valor_base);
        printf("  Desconto por tamanho: R$ %.2f\n", contratos[i].desconto_tamanho);
        printf("  Desconto adicional: R$ %.2f\n", contratos[i].desconto_adicional);
        printf("  Custo adicional: R$ %.2f\n", contratos[i].custo_adicional);
        printf("  Valor total: R$ %.2f\n", contratos[i].valor_total);
    }
}

// Função principal para o menu
int main() {
    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1. Inserir novo contrato\n");
        printf("2. Apresentar resultados\n");
        printf("3. Ordenar contratos\n");
        printf("4. Imprimir registros de contratos\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserir_contrato();
                break;
            case 2:
                apresentar_resultados();
                break;
            case 3:
                ordenar_contratos();
                break;
            case 4:
                imprimir_registros_contratos();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
