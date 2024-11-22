#include <stdio.h>

#define MAX_CONTAS 50

typedef struct {
    char tipo[10];
    double valor;
} Transacao;
typedef struct {
    int numero;
    char nome[50];
    int status;
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
    printf("\ncriarConta \n");
}
void consultarSaldo() {
    printf("\nconsultarSaldo \n");
}
void depositar() {
    printf("\ndepositar \n");
}
void sacar() {
    printf("\nsacar \n");
}
void excluirConta() {
    printf("\nexcluirConta \n");
}
void listarContas() {
    printf("\nlistarContas \n");
}
void exportar() {
    printf("\nexportar \n");
}
void importar() {
    printf("\nimportar \n");
}
