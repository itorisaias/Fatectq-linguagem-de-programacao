#include <stdio.h>
#include <locale.h>
#define MAX_CONTRATOS 100 // define o número máximo de contratos

typedef struct
{
    int numeroContrato;
    int qntEnergia;
    int tipoInstalacao;
    int clienteResidencial;
    int placasBasicas;
    int placasIntermediarias;
    int placasAvancadas;
    float valorBase;
    float descontoPorQuantidade;
    float descontoAdicional;
    float valorTotal;
} Contrato; // agrupado de variáveis que irão compor o contrato

Contrato contratos[MAX_CONTRATOS]; // declaração do array
int totalContratos = 0;            // iniciação da variável

// não permite que o programa exceda o número limite de contratos
void inserirContrato()
{
    if (totalContratos >= MAX_CONTRATOS)
    {
        printf("Limite de contratos atingido.\n");
        return;
    }

    Contrato c; // abrevia o struct Contrato

    // coletar as informações do usuário
    printf("Número do contrato: ");
    scanf("%d", &c.numeroContrato);

    printf("Quantidade de energia desejada (kW): ");
    scanf("%d", &c.qntEnergia);

    printf("Tipo de instalação (1 para Básica, 2 para Completa): ");
    scanf("%d", &c.tipoInstalacao);

    printf("Cliente residencial? (1 para Sim, 0 para Não): ");
    scanf("%d", &c.clienteResidencial);

    if (c.qntEnergia <= 5)
    {
        c.placasBasicas = 10;
        c.placasIntermediarias = 0;
        c.placasAvancadas = 0;
    }
    else if (c.qntEnergia <= 10)
    {
        c.placasBasicas = 4;
        c.placasIntermediarias = 8;
        c.placasAvancadas = 0;
    }
    else
    {
        c.placasBasicas = 8;
        c.placasIntermediarias = 6;
        c.placasAvancadas = 6;
    }

    // Calcular o valor base
    c.valorBase = c.placasBasicas * 800 + c.placasIntermediarias * 1200 + c.placasAvancadas * 1800;

    // Aplicar desconto por quantidade de placas
    int totalPlacas = c.placasBasicas + c.placasIntermediarias + c.placasAvancadas;
    if (totalPlacas > 30)
    {
        c.descontoPorQuantidade = 0.10 * c.valorBase;
    }
    else if (totalPlacas > 10)
    {
        c.descontoPorQuantidade = 0.05 * c.valorBase;
    }
    else
    {
        c.descontoPorQuantidade = 0.0;
    }

    // Adicionar custo de instalação
    if (c.tipoInstalacao == 1)
    {
        c.valorTotal = c.valorBase + 500;
    }
    else
    {
        c.valorTotal = c.valorBase + 1000;
    }

    // Aplicar desconto adicional para clientes residenciais
    if (c.clienteResidencial == 1)
    {
        c.descontoAdicional = 0.05 * (c.valorTotal - c.descontoPorQuantidade);
    }
    else
    {
        c.descontoAdicional = 0.0;
    }

    // Calcular o valor total
    c.valorTotal = c.valorTotal - c.descontoPorQuantidade - c.descontoAdicional;

    // Adicionar o contrato ao array
    contratos[totalContratos++] = c;

    printf("Contrato inserido com sucesso!\n");
}

void apresentarResultados()
{
    float somaTotal = 0, somaResidencial = 0;
    int maiorValorIndex = 0, totalResidenciais = 0, totalComMaisDe30Placas = 0;
    int totalBasicas = 0, totalIntermediarias = 0, totalAvancadas = 0;

    for (int i = 0; i < totalContratos; i++)
    {
        somaTotal += contratos[i].valorTotal; // soma o valor dos contratos

        // soma os totais dos contratos residenciais
        if (contratos[i].clienteResidencial)
        {
            somaResidencial += contratos[i].valorTotal;
            totalResidenciais++;
        }

        if (contratos[i].placasBasicas + contratos[i].placasIntermediarias + contratos[i].placasAvancadas > 30)
        {
            totalComMaisDe30Placas++;
        }

        if (contratos[i].valorTotal > contratos[maiorValorIndex].valorTotal)
        {
            maiorValorIndex = i;
        }

        // soma as placas solicitadas
        totalBasicas += contratos[i].placasBasicas;
        totalIntermediarias += contratos[i].placasIntermediarias;
        totalAvancadas += contratos[i].placasAvancadas;
    }

    // soma das médias dos contratos residenciais
    float mediaTotal = somaTotal / totalContratos;
    float mediaResidencial;
    if (totalResidenciais > 0)
    {
        mediaResidencial = somaResidencial / totalResidenciais;
    }
    else
    {
        mediaResidencial = 0;
    }

    // soma do percentual de contratos com mais de 30 placas
    float percentualMais30Placas;
    if (totalContratos > 0)
    {
        percentualMais30Placas = (totalComMaisDe30Placas * 100.0) / totalContratos;
    }
    else
    {
        percentualMais30Placas = 0;
    }

    printf("Média do valor total dos contratos: R$ %.2f\n", mediaTotal);
    printf("Média dos contratos de clientes residenciais: R$ %.2f\n", mediaResidencial);
    printf("Número do contrato com maior valor total: %d\n", contratos[maiorValorIndex].numeroContrato);
    printf("Percentual dos contratos com mais de 30 placas: %.2f%%\n", percentualMais30Placas);
    printf("Total de placas Básicas: %d\n", totalBasicas);
    printf("Total de placas Intermediárias: %d\n", totalIntermediarias);
    printf("Total de placas Avançadas: %d\n", totalAvancadas);
}

void ordenarContratos()
{
    for (int i = 0; i < totalContratos - 1; i++)
    {
        for (int j = i + 1; j < totalContratos; j++)
        {
            if (contratos[i].valorTotal < contratos[j].valorTotal)
            {
                Contrato temp = contratos[i];
                contratos[i] = contratos[j];
                contratos[j] = temp;
            }
        }
    }
    printf("Contratos ordenados pelo valor total em ordem decrescente.\n");
}
void imprimirContratos()
{
    // Cabeçalho da tabela
    printf("%-10s %-12s %-12s %-12s %-10s %-15s %-15s %-15s %-10s\n",
           "Contrato", "Energia(kW)", "Instalacao", "Residencial",
           "Basicas", "Intermediarias", "Avancadas", "Valor Total", "Desconto");

    // Linha de separação
    printf("----------------------------------------------------------------------------------------------------------------------\n");

    // Impressão dos dados de cada contrato
    for (int i = 0; i < totalContratos; i++)
    {
        printf("%-10d %-12d ", contratos[i].numeroContrato, contratos[i].qntEnergia);

        // Verifica o tipo de instalação
        if (contratos[i].tipoInstalacao == 1)
        {
            printf("%-12s ", "Basica");
        }
        else
        {
            printf("%-12s ", "Completa");
        }

        // Verifica se o cliente é residencial
        if (contratos[i].clienteResidencial == 1)
        {
            printf("%-12s ", "Sim");
        }
        else
        {
            printf("%-12s ", "Nao");
        }

        // Imprime os dados restantes (placas e valor total)
        printf("%-10d %-15d %-15d R$ %-12.2f\n",
               contratos[i].placasBasicas,
               contratos[i].placasIntermediarias,
               contratos[i].placasAvancadas,
               contratos[i].valorTotal);
    }
}

// maneira alternativa para mostrar em formato de lista(obs: menos organizado visualmente)
/*void imprimirContratos() {
    for (int i = 0; i < totalContratos; i++) {
        printf("Contrato %d: Energia: %d kW, Instalacao: ", contratos[i].numeroContrato, contratos[i].qntEnergia);

        if (contratos[i].tipoInstalacao == 1) {
            printf("Basica");
        } else {
            printf("Completa");
        }

        printf(", Residencial: ");

        if (contratos[i].clienteResidencial == 1) {
            printf("Sim");
        } else {
            printf("Nao");
        }

        printf(", Placas: Basicas: %d, Intermediarias: %d, Avancadas: %d, Valor Total: R$ %.2f\n",
               contratos[i].placasBasicas,
               contratos[i].placasIntermediarias,
               contratos[i].placasAvancadas,
               contratos[i].valorTotal);
    }
}*/

int main()
{
    setlocale(LC_ALL, "Portuguese");
    printf("Seja bem-vindo(a) á SolarTech!\n\n");

    int opcao; // variável que irá armazenar a opção escolhida pelo usuário

    // opções do loop
    do
    {
        printf("\nMenu de Opções:\n");
        printf("0. Sair\n");
        printf("1. Inserir mais contratos\n");
        printf("2. Apresentar resultados\n");
        printf("3. Ordenar os contratos pelo valor total (decrescente)\n");
        printf("4. Imprimir registros de contratos\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            printf("Saindo...\n");
            break;
        case 1:
            inserirContrato();
            break;
        case 2:
            apresentarResultados();
            break;
        case 3:
            ordenarContratos();
            break;
        case 4:
            imprimirContratos();
            break;
        default:
            printf("Opção inválida!\n");
        }
    } while (opcao != 0); // verifica se a opção digitada é diferente de 0 para que a execução seja realizada

    return 0;
}
