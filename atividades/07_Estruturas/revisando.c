#include <stdio.h>
#include <string.h>

#define MAX_CONTAS 50
#define DEPOSITO "d"
#define SAQUE "s"
#define ATIVO 1
#define INATIVO 0

typedef struct {
    char tipo[10];
    float valor;
} Transacao;
typedef struct {
    int numero;
    char nome[50];
    int status;
    int qtd_transacoes;
    Transacao transacoes[100];
} Conta;

void menu();
void criarConta();
void consultarSaldo();
void depositar();
void sacar();
void listarContas();
void excluirConta();
void exportar();
void importar();

Conta contas[MAX_CONTAS];
int qtd_contas = 0;

void main() {
    menu();
}

float calcularSaldo(Conta conta) {
    float saldo = 0;
    for (int t = 0; t < conta.qtd_transacoes; t++)
    {
        Transacao transacao = conta.transacoes[t];
        if (strcmp(transacao.tipo, DEPOSITO) == 0) {
            saldo += transacao.valor;
        } else {
            saldo -= transacao.valor;
        }
    }
    return saldo;
}
int buscarIndiceConta(int numeroConta) {
    if (numeroConta == 0 ) {
        printf("Digite o numero da conta: ");
        scanf("%d", &numeroConta);
    }

    for (int i = 0; i < qtd_contas; i++)
    {
        Conta conta = contas[i];

        if (conta.numero == numeroConta && conta.status == ATIVO) {
            return i;
        }
    }

    return -1;
}

void menu() {
    int opc;
    do {
        printf("Selecione uma opcao:\n");
        printf("0 - Sair\n");
        printf("1 - Criar Conta\n");
        printf("2 - Consultar Saldo\n");
        printf("3 - Depositar\n");
        printf("4 - Sacar\n");
        printf("5 - Listar Contas\n");
        printf("6 - Excluir Conta\n");
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
            listarContas();
            break;
        case 6:
            excluirConta();
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
    } while(opc != 0);
}
void criarConta() {
    printf("Criar Conta\n");

    Conta novaConta;

    setbuf(stdin, NULL);
    printf("Digite o nome: ");
    fgets(novaConta.nome, sizeof(novaConta.nome), stdin);
    novaConta.nome[strlen(novaConta.nome) - 1] = '\0';

    printf("Digite o numero da conta: ");
    scanf("%d", &novaConta.numero);

    printf("Digite o valor do primeiro deposito: ");
    scanf("%f", &novaConta.transacoes[0].valor);
    strcpy(novaConta.transacoes[0].tipo, DEPOSITO);
    novaConta.qtd_transacoes = 1;

    novaConta.status = ATIVO;

    contas[qtd_contas] = novaConta;
    qtd_contas += 1;

    printf("Conta Cadastrada!\n");
}
void consultarSaldo() {
    printf("Consultar Saldo\n");

    int indiceConta = buscarIndiceConta(0);
    if (indiceConta == -1) {
        printf("Conta nao encontrada!\n");
        return;
    }

    Conta conta = contas[indiceConta];
    float saldo = calcularSaldo(conta);

    printf("Saldo da conta %d é de R$ %.2f\n", conta.numero, saldo);
}
void depositar() {
    printf("Depositar\n");

    int indiceConta = buscarIndiceConta(0);
    if (indiceConta == -1) {
        printf("Conta nao encontrada!\n");
        return;
    }

    Conta conta = contas[indiceConta];
    Transacao deposito;

    printf("Digite o valor: ");
    scanf("%f", &deposito.valor);
    strcpy(deposito.tipo, DEPOSITO);

    conta.transacoes[conta.qtd_transacoes] = deposito;
    conta.qtd_transacoes += 1;
    contas[indiceConta] = conta;

    printf("Deposito realizado!\n");
}
void sacar() {
    printf("Sacar\n");

    int indiceConta = buscarIndiceConta(0);
    if (indiceConta == -1) {
        printf("Conta nao encontrada!\n");
        return;
    }
    Conta conta = contas[indiceConta];
    Transacao saque;
    float saldo = calcularSaldo(conta);

    printf("Digite o valor: ");
    scanf("%f", &saque.valor);
    strcpy(saque.tipo, SAQUE);
    
    if (saque.valor > saldo) {
        printf("Saldo insuficiente!\n");
        return;
    }

    conta.transacoes[conta.qtd_transacoes] = saque;
    conta.qtd_transacoes += 1;

    contas[indiceConta] = conta;

    printf("Saque realizado!\n");
}
void listarContas() {
    printf("Listar Contas\n");

    for (int i = 0; i < qtd_contas; i++)
    {
        Conta conta = contas[i];
        float saldo = calcularSaldo(conta);
        printf("Nome: %s | Numero: %d | saldo: R$ %.2f\n", conta.nome, conta.numero, saldo);
    }

    printf("Contas listas!\n");
}
void excluirConta() {
    printf("Excluir Conta\n");

    int indiceConta = buscarIndiceConta(0);
    if (indiceConta == -1) {
        printf("Conta nao encontrada!\n");
        return;
    }
    Conta conta = contas[indiceConta];
    float saldo = calcularSaldo(conta);

    if (saldo > 0) {
        printf("Antes de inativar a conta zero o saldo!\n");
        return;
    }

    contas[indiceConta].status = INATIVO;

    printf("Conta excluida!\n");
}
void exportar() {
    printf("Exportar\n");

    FILE *arq = fopen("contas.csv", "w");

    if (arq == NULL) {
        printf("Problema ao criar o arquivo!\n");
        return;
    }

    fprintf(arq, "numero;nome;tipo_transacao;valor_transacao\n");

    for (int i = 0; i < qtd_contas; i++)
    {
        Conta conta = contas[i];
        for (int t = 0; t < conta.qtd_transacoes; t++)
        {
            Transacao transacao = conta.transacoes[t];
            fprintf(
                arq,
                "%d;%s;%s;%.2f\n",
                conta.numero, conta.nome, transacao.tipo, transacao.valor
            );
        }
    }

    fclose(arq);
    printf("Exportacao realizada com sucesso!\n");
}
void importar() {
    printf("Importar\n");

    FILE *arq = fopen("contas.csv", "r");
    if (arq == NULL) {
        printf("Falha ao abrir arquivo!\n");
        return;
    }

    fscanf(arq, "%s\n");
    
    Conta conta;
    Transacao transacao;

    while (
        fscanf(
            arq,
            "%d;%[^;];%[^;];%f\n",
            &conta.numero, conta.nome, &transacao.tipo, &transacao.valor
        )
    ) {
        int indiceConta = buscarIndiceConta(conta.numero);

        if (indiceConta == -1) {
            conta.transacoes[0] = transacao;
            conta.qtd_transacoes = 1;

            conta.status = ATIVO;
            contas[qtd_contas] = conta;
            qtd_contas += 1;
        } else {
            Conta conta = contas[indiceConta];
            conta.transacoes[conta.qtd_transacoes] = transacao;
            conta.qtd_transacoes += 1;
            contas[indiceConta] = conta;
        }
    }
}