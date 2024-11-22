/*
### Enunciado: Sistema Bancário em C

Você deverá implementar um **sistema bancário simples** utilizando **structs** e **arrays** em linguagem C. Esse sistema permitirá a criação e manipulação de contas bancárias através de um menu interativo.

#### Funcionalidades a implementar:
1. **Criar Conta:**
   - O usuário poderá criar uma nova conta fornecendo o número da conta, o nome do cliente e o saldo inicial.
   - Cada conta terá um histórico de transações (depósitos e saques).

2. **Consultar Saldo:**
   - O sistema deverá exibir o saldo atual de uma conta específica, considerando todas as transações realizadas.

3. **Depositar:**
   - Permitir que o usuário insira um valor em uma conta específica.

4. **Sacar:**
   - Permitir que o usuário retire um valor de uma conta, desde que tenha saldo suficiente.

5. **Excluir Conta:**
   - Excluir uma conta, caso ela esteja com saldo zerado.

6. **Listar Contas:**
   - Exibir todas as contas ativas, com o saldo atualizado de cada uma.

7. **Exportar Contas:**
   - Salvar os dados de todas as contas ativas em um arquivo no formato CSV.

8. **Importar Contas:**
   - Ler um arquivo no formato CSV e importar as contas para o sistema.

#### Regras e Orientações:
1. Cada conta é representada por uma **struct** chamada `Conta`, contendo:
   - Número da conta (inteiro).
   - Nome do cliente (string).
   - Status da conta (ativa ou inativa).
   - Histórico de transações (array de structs `Transacao`).
2. Cada transação (depósito ou saque) é representada por uma **struct** chamada `Transacao`, contendo:
   - Tipo da transação (`Depósito` ou `Saque`).
   - Valor da transação.
3. O sistema deverá armazenar no máximo **50 contas bancárias** e cada conta poderá ter até **100 transações**.
4. Utilize um menu interativo para navegar entre as funcionalidades.

#### Exemplo de Menu:
```
=== Banco Simples ===
0. Sair
1. Criar Conta
2. Consultar Saldo
3. Depositar
4. Sacar
5. Excluir Conta
6. Listar Contas
7. Exportar
8. Importar
Escolha uma opção:
```

#### Desafios Extras:
- Valide entradas do usuário, como valores negativos em saques e depósitos.
- Garanta que cada número de conta seja único.
- Implemente a função para exportar e importar contas usando arquivos no formato CSV.

Esse exercício ajudará a fixar os conceitos de **structs**, **arrays**, manipulação de **strings**, e uso de **arquivos**.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTAS 50

typedef struct {
    int numeroConta;
    float valor;
    char tipo[10];
} Transacao;
typedef struct {
    int numero;
    char nome[50];
    int ativa;
    int quantidade_transacoes;
    Transacao transacoes[100];
} Conta;

Conta contas[MAX_CONTAS];
int quantidade_conta = 0;

void menu();
void criarConta();
void listarContas();
void consultarSaldo();
void depositar();
void sacar();
void excluirConta();
void exportar();
void importar();

// Função Principal
void main () {
    menu();
}

// Funções Auxiliares
void limparBuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void pausar() {
    printf("\n\nPressione ENTER para continuar...");
    limparBuffer();
    getchar();
}
void limparTela() {
    system("clear");
}

// Funções de Conta
float calcularSaldo(Conta conta) {
    float saldo = 0;
    for (int i = 0; i < conta.quantidade_transacoes; i++)
    {
        Transacao transacao = conta.transacoes[i];
        
        if (strcmp(transacao.tipo, "Depósito") == 0) {
            saldo += transacao.valor;
        } else {
            saldo -= transacao.valor;
        }
    }
    return saldo;
}

// Sistema de Banco
void menu() {
    int opcao;
    do {
        limparTela();
        printf("\n=== Banco Simples ===\n");
        printf("0. Sair\n");
        printf("1. Criar Conta\n");
        printf("2. Consultar Saldo\n");
        printf("3. Depositar\n");
        printf("4. Sacar\n");
        printf("5. Excluir Conta\n");
        printf("6. Listar Contas\n");
        printf("7. Exportar\n");
        printf("8. Importar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparTela();

        switch (opcao) {
            case 1:
                criarConta();
                break;
            case 2:
                consultarSaldo();
                break;
            case 3:
                depositar();
                break;
            case 4:
                sacar();
                break;
            case 5:
                excluirConta();
                break;
            case 6:
                listarContas();
                break;
            case 7:
                exportar();
                break;
            case 8:
                importar();
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 0);
}
void criarConta() {
    if (quantidade_conta >= MAX_CONTAS) {
        printf("Número máximo de contas atingido!\n");
        return;
    }

    printf("> Criar Conta\n");

    Conta novaConta;

    limparBuffer();
    printf("Informe o nome do cliente: ");
    fgets(novaConta.nome, sizeof(novaConta.nome), stdin);
    novaConta.nome[strcspn(novaConta.nome, "\n")] = '\0';

    printf("Informe o número da conta: ");
    scanf("%d", &novaConta.numero);

    printf("Informe o saldo inicial: ");
    scanf("%f", &novaConta.transacoes[0].valor);
    strcpy(novaConta.transacoes[0].tipo, "Depósito");

    novaConta.ativa = 1;
    novaConta.quantidade_transacoes = 1;

    contas[quantidade_conta] = novaConta;
    quantidade_conta++;

    printf("\nConta criada com sucesso!\n");
    pausar();
}
void listarContas() {
    printf("> Listar Contas\n\n");

    if (quantidade_conta == 0) {
        printf("Nenhuma conta cadastrada!\n");
        pausar();
        return;
    }

    printf("=== Contas Cadastradas ===\n");
    for (int i = 0; i < quantidade_conta; i++) {
        if (contas[i].ativa) {
            printf("Número: %d | Nome: %s | Saldo: %.2f\n", contas[i].numero, contas[i].nome, calcularSaldo(contas[i]));
        }
    }

    pausar();
}
void consultarSaldo() {
    printf("> Consultar Saldo\n");

    Conta conta;
    int numeroConta, encontrou = 0;
    float saldo = 0;
    printf("Informe o número da conta: ");
    scanf("%d", &numeroConta);

    for (int i = 0; i < quantidade_conta; i++) {
        if (contas[i].numero == numeroConta && contas[i].ativa) {
            encontrou = 1;
            conta = contas[i];
        }
    }

    if (!encontrou) {
        printf("Conta não encontrada!\n");
        pausar();
        return;
    }

    printf("Saldo da conta %d: %.2f\n", conta.numero, calcularSaldo(conta));
    pausar();
}
void depositar() {
    printf("> Depositar\n");

    int numeroConta;
    printf("Informe o número da conta: ");
    scanf("%d", &numeroConta);

    for (int i = 0; i < quantidade_conta; i++) {
        if (contas[i].numero == numeroConta && contas[i].ativa) {
            float valor;
            int quantidade_transacoes = contas[i].quantidade_transacoes;
            printf("Informe o valor do depósito: ");
            scanf("%f", &valor);

            Transacao deposito;
            deposito.valor = valor;
            strcpy(deposito.tipo, "Depósito");

            contas[i].transacoes[quantidade_transacoes] = deposito;
            contas[i].quantidade_transacoes++;

            float novoSaldo = calcularSaldo(contas[i]);
            
            printf("\nDepósito realizado com sucesso!\n");
            printf("Novo saldo: %.2f\n", novoSaldo);
            pausar();
            return;
        }
    }

    printf("Conta não encontrada!\n");
    pausar();
}
void sacar() {
    printf("> Sacar\n");

    int numeroConta;
    printf("Informe o número da conta: ");
    scanf("%d", &numeroConta);

    for (int i = 0; i < quantidade_conta; i++) {
        if (contas[i].numero == numeroConta && contas[i].ativa) {
            float valor;
            int quantidade_transacoes = contas[i].quantidade_transacoes;

            printf("Informe o valor do saque: ");
            scanf("%f", &valor);

            if (valor > calcularSaldo(contas[i])) {
                printf("Saldo insuficiente!\n");
                pausar();
                return;
            }

            Transacao saque;
            saque.valor = valor;
            strcpy(saque.tipo, "Saque");

            contas[i].transacoes[quantidade_transacoes] = saque;
            contas[i].quantidade_transacoes++;

            float novoSaldo = calcularSaldo(contas[i]);

            printf("\nSaque realizado com sucesso!\n");
            printf("Novo saldo: %.2f\n", novoSaldo);

            pausar();
            return;
        }
    }

    printf("Conta não encontrada!\n");
    pausar();
}
void excluirConta() {
    printf("> Excluir Conta\n");

    int numeroConta;
    printf("Informe o número da conta: ");
    scanf("%d", &numeroConta);

    for (int i = 0; i < quantidade_conta; i++) {
        if (contas[i].numero == numeroConta && contas[i].ativa) {
            if (calcularSaldo(contas[i]) > 0) {
                printf("\nA conta possui saldo! Realize o saque antes de excluí-la.\n");
                pausar();
                return;
            }

            contas[i].ativa = 0;
            printf("Conta excluída com sucesso!\n");
            pausar();
            return;
        }
    }

    printf("Conta não encontrada!\n");
    pausar();
}
void exportar() {
    if (quantidade_conta == 0) {
        printf("Nenhuma conta cadastrada!\n");
        pausar();
        return;
    }
    char nomeArquivo[50];
    printf("Informe o nome do arquivo de relatório: ");
    limparBuffer();
    fgets(nomeArquivo, sizeof(nomeArquivo), stdin);
    nomeArquivo[strcspn(nomeArquivo, "\n")] = '\0';

    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao criar arquivo de relatório!\n");
        pausar();
        return;
    }

    fprintf(arquivo, "numero;nome;saldo\n");
    for (int i = 0; i < quantidade_conta; i++) {
        if (contas[i].ativa) {
            Conta conta = contas[i];
            fprintf(arquivo, "%d;%s;%.2f\n", conta.numero, conta.nome, calcularSaldo(conta));
        }
    }

    fclose(arquivo);
    printf("Relatório exportado com sucesso!\n");
    pausar();
}
void importar() {
    char nomeArquivo[50];
    printf("Informe o nome do arquivo de relatório: ");
    limparBuffer();
    fgets(nomeArquivo, sizeof(nomeArquivo), stdin);
    nomeArquivo[strcspn(nomeArquivo, "\n")] = '\0';

    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Arquivo de relatório não encontrado!\n");
        pausar();
        return;
    }

    char linha[100];
    fgets(linha, sizeof(linha), arquivo);
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        Conta conta;
        Transacao transacao;
        sscanf(linha, "%d;%[^;];%f", &conta.numero, conta.nome, &transacao.valor);

        strcpy(transacao.tipo, "Depósito");

        conta.transacoes[0] = transacao;
        conta.quantidade_transacoes = 1;
        conta.ativa = 1;
        contas[quantidade_conta] = conta;
        quantidade_conta++;
    }

    fclose(arquivo);
    printf("Relatório importado com sucesso!\n");
    pausar();
}