#include <stdio.h>

#define MAX_VENDAS 100

typedef struct {
    int numeroVenda;
    int categoria;
    int quantidade;
    int clienteVIP;
    float valorBase;
    float valorDesconto;
    float valorTotal;
} Venda;

const char* categorias[] = {"", "Celulares", "Notebooks", "Tablets", "Acessorios"};

// 1
float calcularValorBase(int categoria, int quantidade) {
    float preco;
    switch (categoria) {
        case 1: preco = 1000.0; break;
        case 2: preco = 3000.0; break;
        case 3: preco = 1500.0; break;
        case 4: preco = 200.0; break;
        default: return 0;
    }

    float valorBase = preco * quantidade;
    
    return valorBase;
}

// 2
float calcularDesconto(float valorBase, int clienteVIP) {
    float desconto = 0;

    if (valorBase > 5000) {
        desconto = valorBase * 0.10;
    } 
    
    if (clienteVIP) {
        desconto = valorBase * 0.15;
    }

    return desconto;
}

// 3
void ordenarVendas(Venda vendas[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j++) {
            if (vendas[j].valorTotal < vendas[j + 1].valorTotal) {
                Venda temp = vendas[j];
                vendas[j] = vendas[j + 1];
                vendas[j + 1] = temp;
            }
        }
    }
}

// 4
void imprimirResultados(Venda vendas[], int count) {
    float totalVendas = 0, totalVIP = 0;
    int totalProdutos = 0, maxVendaIndex = 0;
    float maiorValor = 0;
    int contNotebooks = 0;

    float totalPorCategoria[5] = {0};
    int quantidadePorCategoria[5] = {0};

    for (int i = 0; i < count; i++) {
        totalVendas += vendas[i].valorTotal; // totalVendas = totalVendas + vendas[i].valorTotal;
        totalProdutos += vendas[i].quantidade;
        if (vendas[i].valorTotal > maiorValor) {
            maiorValor = vendas[i].valorTotal;
            maxVendaIndex = i;
        }
        if (vendas[i].categoria == 2) {
            contNotebooks++;
        }
        if (vendas[i].clienteVIP) {
            totalVIP += vendas[i].valorTotal;
        }

        totalPorCategoria[vendas[i].categoria] += vendas[i].valorTotal;
        quantidadePorCategoria[vendas[i].categoria] += vendas[i].quantidade;
    }

    float mediaVendas = totalVendas / count;
    float mediaVIP = (contNotebooks > 0) ? totalVIP / contNotebooks : 0;
    float percentualNotebooks = (float)contNotebooks / count * 100;

    printf("1. A media do valor de todas as vendas: R$ %.2f\n", mediaVendas);
    printf("2. A media das vendas para clientes VIP: R$ %.2f\n", mediaVIP);
    printf("3. O numero da venda com maior valor: %d\n", vendas[maxVendaIndex].numeroVenda);
    printf("4. O percentual das vendas de Notebooks em relacao ao numero total de vendas: %.2f%%\n", percentualNotebooks);
    printf("5. O total geral de produtos vendidos: %d\n", totalProdutos);

    printf("\nValores vendidos e quantidades por categoria:\n");
    for (int i = 1; i <= 4; i++) {
        printf("%s: Valor Total: R$ %.2f, Quantidade: %d\n", categorias[i], totalPorCategoria[i], quantidadePorCategoria[i]);
    }
}

// 5 - valores não alinhados
void imprimirVendas(Venda vendas[], int count) {
    printf("Número da Venda | Categoria | Quantidade | Cliente Vip | Valor Base | Descontos | Valor Total\n");
    printf("------------------------------------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%d          | %s      | %d       |  %s    | R$ %.2f     | R$ %.2f        | R$ %.2f\n",
        vendas[i].numeroVenda, 
        categorias[vendas[i].categoria], 
        vendas[i].quantidade,
        (vendas[i].clienteVIP == 1 ? "Sim" : "Não"),
        vendas[i].valorBase, 
        vendas[i].valorDesconto, 
        vendas[i].valorTotal
        );
    }
}

// 5 - valores alinhados
// void imprimirVendas(Venda vendas[], int count) {
//     printf("Número da Venda | Categoria      | Quantidade     | Cliente Vip    | Valor Base    | Descontos     | Valor Total\n");
//     printf("----------------------------------------------------------------------------------------------------------------\n");
    
//     for (int i = 0; i < count; i++) {
//         printf("%-15d | %-14s | %-14d | %-14s | R$ %-10.2f | R$ %-10.2f | R$ %-10.2f\n",
//         vendas[i].numeroVenda, 
//         categorias[vendas[i].categoria], 
//         vendas[i].quantidade,
//         (vendas[i].clienteVIP == 1 ? "Sim" : "Não"),
//         vendas[i].valorBase, 
//         vendas[i].valorDesconto, 
//         vendas[i].valorTotal
//         );
//     }
// }

// 6
void inserirVenda(Venda vendas[], int count) {
    if (count < MAX_VENDAS) {
        // printf("Numero da Venda: ");
        // scanf("%d", &vendas[count].numeroVenda);
        vendas[count].numeroVenda = count + 1;
        printf("Categoria do Produto (1-Celulares, 2-Notebooks, 3-Tablets, 4-Acessorios): ");
        scanf("%d", &vendas[count].categoria);
        printf("Quantidade: ");
        scanf("%d", &vendas[count].quantidade);
        printf("Cliente VIP (1-Sim, 0-Nao): ");
        scanf("%d", &vendas[count].clienteVIP);

        vendas[count].valorBase = calcularValorBase(vendas[count].categoria, vendas[count].quantidade);
        vendas[count].valorDesconto = calcularDesconto(vendas[count].valorBase, vendas[count].clienteVIP);
        vendas[count].valorTotal = vendas[count].valorBase - vendas[count].valorDesconto;

    } else {
        printf("Limite de vendas alcancado!\n");
    }
}

// 7 - principal
int main() {
    Venda vendas[MAX_VENDAS];
    int count = 0;
    int opcao;

    while (1) {
        printf("\nMenu:\n");
        printf("0. Sair\n");
        printf("1. Inserir mais registros\n");
        printf("2. Apresentar resultados\n");
        printf("3. Ordenar os registros pelo valor total da venda (decrescente)\n");
        printf("4. Imprimir registros de vendas\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 0) {
            break;
        } else if (count == 0 && opcao != 1) {
            printf("Nenhuma venda registrada!\n");
        } else if (opcao == 1) {
            inserirVenda(vendas, count);
            count++;
        } else if (opcao == 2) {
            imprimirResultados(vendas, count);
        } else if (opcao == 3) {
            ordenarVendas(vendas, count);
            printf("Vendas ordenadas pelo valor total.\n");
        } else if (opcao == 4) {
            imprimirVendas(vendas, count);
        } else {
            printf("Opcao invalida!\n");
        }
    }

    return 0;
}
