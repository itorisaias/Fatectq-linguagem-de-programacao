#include <stdio.h>
//criacao de variaveis que serão utilizadas 
//durante  todo o codigo
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

//criação de 4 funções void
//que irão executar tarefas dentro do menu no int main

void calcularValorContrato(int i)
 {
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

void apresentarResultados() 
{
    float mediaTotal = somaValores / totalContratos;
    float mediaMais30 = (totalMais30 > 0) ? somaValoresMais30 / totalMais30 : 0;
    float percentualAnuais = (float)totalAnuais / totalContratos * 100;

    printf("1. A media do valor total dos contratos: R$ %.2f\n", mediaTotal);
    printf("2. A media dos contratos de predios com mais de 30 unidades: R$ %.2f\n", mediaMais30);
    printf("3. O numero do contrato com maior valor total: %d\n", contratoMaiorValor);
    printf("4. O percentual dos contratos anuais em relacao ao numero total de contratos: %.2f%%\n", percentualAnuais);
    printf("5. O total de predios que incluem servicos de manutencao preventiva: %d\n", totalManutencao);    
}

//devido a configuração do meu editor
//foi preciso criar as variáveis i e j fora do laço
int i ,j;

void ordenarContratos()
 {
    for(i = 0; i < totalContratos - 1; i++) {
        for(j = i + 1; j < totalContratos; j++) {
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

int i;
void imprimirContratos()
{
	printf("Registros de Contratos:\n");
    	for(i = 0; i < totalContratos; i++) {
            printf("Contrato %d:\n", numeroContratos[i]);
            printf("Unidades: %d\n", unidades[i]);
            printf("Manutencao Preventiva: %d\n", manutencao[i]);
            printf("Jardinagem: %d\n", jardinagem[i]);
            printf("Contrato Anual: %d\n", contratoAnual[i]);
            printf("Cliente Fidelidade: %d\n", fidelidade[i]);
            printf("Valor Total: R$ %.2f\n", valorTotal[i]);
            printf("---------------------------\n");
        }
}

// agora no main, o código irão funcionar
// e as funções representam as opções dentro de cada if
//vai fexecutar o bloco de códigos que foi criado no início 
int main()
{
	do {
		printf("Bem vindo a ADMINPRED, abaixo esta o nosso menu, escolha a opcao desejada:\n\n");
        printf("\nMenu de Opcoes:\n\n");
        printf("0. Sair\n");
        printf("1. Inserir mais contratos\n");
        printf("2. Apresentar resultados\n");
        printf("3. Ordenar os contratos pelo valor total (decrescente)\n");
        printf("4. Imprimir registros de contratos\n\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if(opcao == 1) {
            if(totalContratos < 100) {
                printf("Numero do contrato: ");
                scanf("%d", &numeroContratos[totalContratos]);

                printf("Quantidade de unidades no predio: ");
                scanf("%d", &unidades[totalContratos]);

                printf("Manutencao preventiva (1 para sim, 0 para nao): ");
                scanf("%d", &manutencao[totalContratos]);

                printf("Jardinagem (1 para sim, 0 para nao): ");
                scanf("%d", &jardinagem[totalContratos]);

                printf("Contrato anual (1 para sim, 0 para nao): ");
                scanf("%d", &contratoAnual[totalContratos]);

                printf("Cliente fidelidade (1 para sim, 0 para nao): ");
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


