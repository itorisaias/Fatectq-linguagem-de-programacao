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
    printf("\n menu \n");
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
