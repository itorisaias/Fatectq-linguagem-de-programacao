#include <stdio.h>
#include <string.h>

#define MAX_CONTAS 50
#define DEPOSITO "d"
#define SAQUE "s"

typedef struct {
    char tipo[10];
    float valor;
} Transacao;
typedef struct {
    int numero;
    char nome[50];
    int status;
    int quantidade_transacoes;
    Transacao transacoes[100];
} Conta;

void menu();
void criarConta();
void consultarSaldo();
void depositar();
void sacar();
void excluirConta();
void listarContas();
void exportar();
void importar();

Conta contas[MAX_CONTAS];
int quantidade_contas = 0;

void main() {
    menu();
}

void menu() {
    int opc;
    do {
        printf("Selecione uma opção: \n");
        printf("0 - Sair\n");
        printf("1 - Criar Conta\n");
        printf("2 - Conultar Saldo\n");
        printf("3 - Depositar\n");
        printf("4 - Sacar\n");
        printf("5 - Excluir Conta\n");
        printf("6 - Listar Contas\n");
        printf("7 - Exportar\n");
        printf("8 - Importar\n");
        scanf("%d", &opc);

        switch (opc)
        {
        case 0:
            printf("Saindo...\n");
            break;
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
        default:
            printf("Opcao invalida!\n");
            break;
        }
    } while (opc != 0);
}
void criarConta() {
    printf("\nCriar Conta \n");
    setbuf(stdin, NULL);

    Conta novaConta;
    Transacao deposito;
    
    printf("Digite o nome do cliente: ");
    fgets(novaConta.nome, sizeof(novaConta.nome), stdin);
    novaConta.nome[strlen(novaConta.nome) - 1] = '\0';

    printf("Digite o numero da conta: ");
    scanf("%d", &novaConta.numero);

    printf("Digite o saldo inicial: ");
    scanf("%f", &deposito.valor);
    strcpy(deposito.tipo, DEPOSITO);

    novaConta.transacoes[0] = deposito;
    novaConta.quantidade_transacoes = 1;
    novaConta.status = 1;

    contas[quantidade_contas] = novaConta;
    quantidade_contas++;

    printf("\nConta criada com sucesso!\n");
}
void consultarSaldo() {
    printf("\nConsultar Saldo \n");

    int numeroConta;
    printf("Digite o numero da conta: ");
    scanf("%d", &numeroConta);

    for (int i = 0; i < quantidade_contas; i++)
    {
        Conta conta = contas[i];

        if (conta.numero == numeroConta && conta.status == 1) {
            float saldo = 0;
            for (int t = 0; t < conta.quantidade_transacoes; t++)
            {
                Transacao transacao = conta.transacoes[t];

                if (strcmp(transacao.tipo, DEPOSITO) == 0) {
                    saldo += transacao.valor;
                } else {
                    saldo -= transacao.valor;
                }
            }

            printf("Saldo da conta %d é de R$ %.2f\n", conta.numero, saldo);
        }
    }

    printf("Conta não encontrada!\n");
}
void depositar() {
    printf("\nDepositar \n");

    int numeroConta;
    printf("Digite o numero da conta: ");
    scanf("%d", &numeroConta);

    for (int i = 0; i < quantidade_contas; i++)
    {
        Conta conta = contas[i];

        if (conta.numero == numeroConta && conta.status == 1) {
            Transacao deposito;
            
            printf("Digite o valor desejado: ");
            scanf("%f", &deposito.valor);
            strcpy(deposito.tipo, DEPOSITO);

            contas[i].transacoes[conta.quantidade_transacoes] = deposito;
            contas[i].quantidade_transacoes++;

            printf("Deposito realizado com sucesso!\n");

            return;
        }
    }
    
    printf("Conta não encontrada!\n");
}
void sacar() {
    printf("\nSacar \n");

    int numeroConta;
    printf("Digite o numero da conta: ");
    scanf("%d", &numeroConta);

    for (int i = 0; i < quantidade_contas; i++)
    {
        Conta conta = contas[i];

        if (conta.numero == numeroConta && conta.status == 1) {
            Transacao saque;
            printf("Digite o valor desejado: ");
            scanf("%f", &saque.valor);
            strcpy(saque.tipo, SAQUE);

            float saldo = 0;
            for (int t = 0; t < conta.quantidade_transacoes; t++)
            {
                Transacao transacao = conta.transacoes[t];

                if (strcmp(transacao.tipo, DEPOSITO) == 0) {
                    saldo += transacao.valor;
                } else {
                    saldo -= transacao.valor;
                }
            }

            if (saque.valor > saldo) {
                printf("Saldo insuficiente!\n");
                return;
            }

            contas[i].transacoes[conta.quantidade_transacoes] = saque;
            contas[i].quantidade_transacoes++;

            printf("Saque realizado com suecesso! \n");

            return;
        }
    }
    
    printf("Conta não encontrada!\n");
}
void excluirConta() {
    printf("\nExcluir Conta \n");

    int numeroConta;
    printf("Digite o numero da conta: ");
    scanf("%d", &numeroConta);

    for (int i = 0; i < quantidade_contas; i++)
    {
        Conta conta = contas[i];

        if (conta.numero == numeroConta && conta.status == 1) {
            float saldo = 0;
            for (int t = 0; t < conta.quantidade_transacoes; t++)
            {
                Transacao transacao = conta.transacoes[t];

                if (strcmp(transacao.tipo, DEPOSITO) == 0) {
                    saldo += transacao.valor;
                } else {
                    saldo -= transacao.valor;
                }
            }

            if (saldo > 0) {
                printf("Antes precisa zerar o valor de saldo da conta!\n");
                return;
            }

            contas[i].status = 0;

            printf("Conta desativado com sucesso!\n");
            return;
        }
    }
    
    printf("Conta não encontrada!\n");
}
void listarContas() {
    printf("\nListar Contas \n");

    for(int i = 0; i < quantidade_contas; i++) {
        Conta conta = contas[i];
        float saldo = 0;

        for (int j = 0; j < conta.quantidade_transacoes; j++)
        {
            Transacao transacao = conta.transacoes[j];

            if (strcmp(transacao.tipo, DEPOSITO) == 0) {
                saldo += transacao.valor;
            } else {
                saldo -= transacao.valor;
            }
        }

        printf("Nome: %s | Numero: %d | Saldo: R$ %.2f\n", conta.nome, conta.numero, saldo);
    }
}

void exportar() {
    printf("\nexportar \n");
}
void importar() {
    printf("\nimportar \n");
}
