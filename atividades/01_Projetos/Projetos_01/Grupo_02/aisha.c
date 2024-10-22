#include <stdio.h>

int numeroContratos[100];
int unidades[100];
int manutencao[100];
int jardinagem[100];
int contratoAnual[100];
int fidelidade[100];
float valorBase[100];
float valorTotal[100];
int totalContratos = 0;
int opcao;

float somaValores = 0;
float somaValoresMais30 = 0;
int totalMais30 = 0;
int contratoMaiorValor = 0;
float maiorValor = 0;
int totalAnuais = 0;
int totalManutencao = 0;

void calcularValorContrato(int i) {
    if(unidades[i] <= 10) {
        valorBase[i] = 2000;
    } else if(unidades[i] <= 30) {
        valorBase[i] = 4000;
    } else {
        valorBase[i] = 6000;
    }

    float adicional = 0;
    if(manutencao[i] == 1) {
        adicional += 500;
        totalManutencao++;
    }
    if(jardinagem[i] == 1) {
        adicional += 300;
    }

    valorTotal[i] = valorBase[i] + adicional;

    float desconto = 0;
    if(contratoAnual[i] == 1) {
        desconto += 0.10 * valorTotal[i];
    }
    if(unidades[i] > 30) {
        desconto += 0.05 * valorTotal[i];
    }
    if(fidelidade[i] == 1) {
        desconto += 0.15 * valorTotal[i];
    }

    valorTotal[i] -= desconto;

    somaValores += valorTotal[i];
    if(unidades[i] > 30) {
        somaValoresMais30 += valorTotal[i];
        totalMais30++;
    }
    if(valorTotal[i] > maiorValor) {
        maiorValor = valorTotal[i];
        contratoMaiorValor = numeroContratos[i];
    }
    if(contratoAnual[i] == 1) {
        totalAnuais++;
    }

    totalContratos++;
}

void apresentarResultados() {
    float mediaTotal = somaValores / totalContratos;
    float mediaMais30 = (totalMais30 > 0) ? somaValoresMais30 / totalMais30 : 0;
    float percentualAnuais = (float)totalAnuais / totalContratos * 100;

    printf("1. A média do valor total dos contratos: R$ %.2f\n", mediaTotal);
    printf("2. A média dos contratos de prédios com mais de 30 unidades: R$ %.2f\n", mediaMais30);
    printf("3. O número do contrato com maior valor total: %d\n", contratoMaiorValor);
    printf("4. O percentual dos contratos anuais em relação ao número total de contratos: %.2f%%\n", percentualAnuais);
    printf("5. O total de prédios que incluem serviços de manutenção preventiva: %d\n", totalManutencao);
}

void ordenarContratos() {
    for(int i = 0; i < totalContratos - 1; i++) {
        for(int j = i + 1; j < totalContratos; j++) {
            if(valorTotal[i] < valorTotal[j]) {
                float auxValor = valorTotal[i];
                valorTotal[i] = valorTotal[j];
                valorTotal[j] = auxValor;

                int auxNumero = numeroContratos[i];
                numeroContratos[i] = numeroContratos[j];
                numeroContratos[j] = auxNumero;

                int auxUnidades = unidades[i];
                unidades[i] = unidades[j];
                unidades[j] = auxUnidades;

                int auxManutencao = manutencao[i];
                manutencao[i] = manutencao[j];
                manutencao[j] = auxManutencao;

                int auxJardinagem = jardinagem[i];
                jardinagem[i] = jardinagem[j];
                jardinagem[j] = auxJardinagem;

                int auxContratoAnual = contratoAnual[i];
                contratoAnual[i] = contratoAnual[j];
                contratoAnual[j] = auxContratoAnual;

                int auxFidelidade = fidelidade[i];
                fidelidade[i] = fidelidade[j];
                fidelidade[j] = auxFidelidade;
            }
        }
    }
    printf("Contratos ordenados com sucesso!\n");
}

void imprimirContratos() {
printf("Registros de Contratos:\n");
            for(int i = 0; i < totalContratos; i++) {
                printf("Contrato %d:\n", numeroContratos[i]);
                printf("Unidades: %d\n", unidades[i]);
                printf("Manutenção Preventiva: %d\n", manutencao[i]);
                printf("Jardinagem: %d\n", jardinagem[i]);
                printf("Contrato Anual: %d\n", contratoAnual[i]);
                printf("Cliente Fidelidade: %d\n", fidelidade[i]);
                printf("Valor Total: R$ %.2f\n", valorTotal[i]);
                printf("---------------------------\n");
            }
}

int main() {
    do {
        printf("Menu de Opções:\n");
        printf("0. Sair\n");
        printf("1. Inserir mais contratos\n");
        printf("2. Apresentar resultados\n");
        printf("3. Ordenar os contratos pelo valor total (decrescente)\n");
        printf("4. Imprimir registros de contratos\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if(opcao == 1) {
            if(totalContratos < 100) {
                printf("Número do contrato: ");
                scanf("%d", &numeroContratos[totalContratos]);

                printf("Quantidade de unidades no prédio: ");
                scanf("%d", &unidades[totalContratos]);

                printf("Manutenção preventiva (1 para sim, 0 para não): ");
                scanf("%d", &manutencao[totalContratos]);

                printf("Jardinagem (1 para sim, 0 para não): ");
                scanf("%d", &jardinagem[totalContratos]);

                printf("Contrato anual (1 para sim, 0 para não): ");
                scanf("%d", &contratoAnual[totalContratos]);

                printf("Cliente fidelidade (1 para sim, 0 para não): ");
                scanf("%d", &fidelidade[totalContratos]);

                calcularValorContrato(totalContratos);

            }
        } else if(opcao == 2) {

                apresentarResultados();

        } else if(opcao == 3) {

                ordenarContratos();

        } else if(opcao == 4) {

                imprimirContratos();
        }

    } while(opcao != 0);

    return 0;
}
