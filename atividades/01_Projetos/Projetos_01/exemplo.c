/*
### Sistema de Gerenciamento de Planos de Saúde

A Seguradora Saúde Total oferece diversos planos de saúde. O custo do plano varia de acordo com a faixa etária do cliente e a duração do contrato.

#### Regras de Negócio:

- **Até 18 anos**: R$ 100,00 por mês
- **De 19 a 40 anos**: R$ 200,00 por mês
- **Acima de 40 anos**: R$ 300,00 por mês

#### Taxa adicional pela duração do contrato:

- **Até 12 meses**: R$ 600,00 de taxa adicional
- **De 13 até 24 meses**: R$ 300,00 de taxa adicional
- **Acima de 24 meses**: sem taxa adicional

#### Funcionalidades do Sistema:

Desenvolver um programa em C que gerencie até 100 contratos utilizando vetores simples.

#### Menu de Opções:

O programa deve apresentar um menu com as seguintes opções:

0. **Sair**
1. **Inserir mais registros**
2. **Apresentar resultados**
3. **Ordenar os contratos pelo valor (decrescente)**
4. **Imprimir contratos**

#### Dados dos Contratos:

Para cada contrato, o programa deve armazenar as seguintes informações usando vetores simples:

- Número do contrato
- Idade do cliente
- Duração em meses

#### Resultados e Insights:

O sistema deve calcular e exibir os seguintes resultados:

1. A média do valor de todos os contratos.
2. A média dos contratos de clientes acima de 40 anos.
3. O número do contrato com maior valor.
4. O percentual dos contratos com duração acima de 24 meses em relação ao número total de contratos.
5. O total geral de meses contratados.

#### Requisitos Adicionais:

- Utilizar vetores simples para armazenar os dados dos contratos (número do contrato, idade e duração).
- Implementar a entrada de novos registros até atingir o limite de 100 contratos.
- Implementar cálculos e apresentação dos resultados conforme descrito.
- Ordenar os contratos pelo valor em ordem decrescente.

#### Exemplo de entrada:

28 anos, 15 meses (R$ 200,00 + R$ 300,00 = R$ 500,00)
45 anos, 30 meses (R$ 300,00             = R$ 300,00)
18 anos, 12 meses (R$ 100,00 + R$ 600,00 = R$ 700,00)

#### Resultado esperado:

1. A média do valor de todos os contratos: R$ 500,00
2. A média dos contratos de clientes acima de 40 anos: R$ 300,00
3. O número do contrato com maior valor: 3
4. O percentual dos contratos com duração acima de 24 meses em relação ao número total de contratos: 33,33%
5. O total geral de meses contratados: 57
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_CONTRATOS 100

void limparTerminal();
float taxaAdicionalDuracaoDoContrato(int duracao);
float valorPlanoPorIdade(int idade);
float valorTotalContrato(int idade, int duracao);
void inserirContrato();
void apresentarResultados();
void ordenarContratos();
void imprimirContratos();

int contratos[MAX_CONTRATOS];
int idades[MAX_CONTRATOS];
int duracoes[MAX_CONTRATOS];
int numeroContrato = 0;

int main() {
    int opc = -1;

    limparTerminal();

    while (opc != 0) {
        printf("0. Sair\n");
        printf("1. Inserir mais registros\n");
        printf("2. Apresentar resultados\n");
        printf("3. Ordenar os contratos pelo valor (decrescente)\n");
        printf("4. Imprimir contratos\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                limparTerminal();
                inserirContrato();
                break;
            case 2:
                limparTerminal();
                apresentarResultados();
                break;
            case 3:
                limparTerminal();
                ordenarContratos();
                break;
            case 4:
                limparTerminal();
                imprimirContratos();
                break;
            case 0:
                printf("Tchau!\n");
                break;
            default:
                limparTerminal();
                printf("Opção [%d] inválida!\n\n", opc);
                break;
        }
    }

    return 0;
}

void limparTerminal() {
    system("clear");
}

float taxaAdicionalDuracaoDoContrato(int duracao) {
    if (duracao <= 12) {
        return 600;
    } else if (duracao <= 24) {
        return 300;
    } else {
        return 0;
    }
}

float valorPlanoPorIdade(int idade) {
    if (idade <= 18) {
        return 100;
    } else if (idade <= 40) {
        return 200;
    } else {
        return 300;
    }
}

float valorTotalContrato(int idade, int duracao) {
    return valorPlanoPorIdade(idade) + taxaAdicionalDuracaoDoContrato(duracao);
}

void inserirContrato() {
    if (numeroContrato >= MAX_CONTRATOS) {
        printf("Número máximo de contratos atingido!\n\n");
        return;
    }

    printf("Cadastro de contrato\n\n");

    int idadeCliente, duracaoContrato;

    printf("Número do contrato: %d\n", numeroContrato + 1);
    printf("Idade do cliente: ");
    scanf("%d", &idadeCliente);
    printf("Duração do contrato (em meses): ");
    scanf("%d", &duracaoContrato);
    printf("Valor do plano: %.2f\n", valorPlanoPorIdade(idadeCliente));
    printf("Taxa adicional: %.2f\n", taxaAdicionalDuracaoDoContrato(duracaoContrato));
    printf("Valor total: %.2f\n", valorTotalContrato(idadeCliente, duracaoContrato));

    contratos[numeroContrato] = numeroContrato + 1;
    idades[numeroContrato] = idadeCliente;
    duracoes[numeroContrato] = duracaoContrato;

    numeroContrato++;

    printf("\n\nContrato cadastrado com sucesso!\n\n");
}

void apresentarResultados() {
    printf("Resultados\n\n");

    float totalGeral = 0, maiorValor = 0, totalValorAcima40 = 0;
    int totalContratosAcima24 = 0, contratoMaiorValor = 0, totalMeses = 0;
    int totalContratos = numeroContrato;
    int totalClientesAcima40 = 0;

    for (int i = 0; i < numeroContrato; i++) {
        float valor = valorTotalContrato(idades[i], duracoes[i]);
        totalGeral += valor;
        totalMeses += duracoes[i];

        if (idades[i] > 40) {
            totalValorAcima40 += valor;
            totalClientesAcima40++;
        }

        if (valor > maiorValor) {
            contratoMaiorValor = contratos[i];
            maiorValor = valor;
        }

        if (duracoes[i] > 24) {
            totalContratosAcima24++;
        }
    }

    printf("1. A média do valor de todos os contratos: %.2f\n", totalGeral / totalContratos);
    printf("2. A média dos contratos de clientes acima de 40 anos: %.2f\n", totalClientesAcima40 > 0 ? totalValorAcima40 / totalClientesAcima40 : 0);
    printf("3. O número do contrato com maior valor: %d\n", contratoMaiorValor);
    printf("4. O percentual dos contratos com duração acima de 24 meses em relação ao número total de contratos: %.2f%%\n", (totalContratosAcima24 * 100.0) / totalContratos);
    printf("5. O total geral de meses contratados: %d\n", totalMeses);
    printf("\n\n");
}

void ordenarContratos() {
    printf("Ordenar os contratos pelo valor (decrescente)\n\n");

    for (int i = 0; i < numeroContrato - 1; i++) {
        for (int j = i + 1; j < numeroContrato; j++) {
            float valorContratoI = valorTotalContrato(idades[i], duracoes[i]);
            float valorContratoJ = valorTotalContrato(idades[j], duracoes[j]);

            if (valorContratoI < valorContratoJ) {
                int tempIdade = idades[i];
                idades[i] = idades[j];
                idades[j] = tempIdade;

                int tempDuracao = duracoes[i];
                duracoes[i] = duracoes[j];
                duracoes[j] = tempDuracao;

                int tempContrato = contratos[i];
                contratos[i] = contratos[j];
                contratos[j] = tempContrato;
            }
        }
    }

    printf("Contratos ordenados com sucesso!\n\n");
}

void imprimirContratos() {
    printf("Contratos\n\n");

    for (int i = 0; i < numeroContrato; i++) {
        printf("Contrato: %d\n", contratos[i]);
        printf("Idade: %d\n", idades[i]);
        printf("Duração: %d\n", duracoes[i]);
        printf("Valor: %.2f\n", valorTotalContrato(idades[i], duracoes[i]));
        printf("\n");
    }
}
