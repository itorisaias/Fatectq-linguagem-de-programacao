#include <stdio.h>
#include <stdlib.h>

// Definindo estrutura e funções
typedef struct {
    char nome[100];
    int idade;
    char sexo;
} Pessoa;
int cadastrarPessoa();
void imprimirPessoa();

// Criando variavel global
#define TAMANHO 10
Pessoa contatos[TAMANHO]
int quantidade = 0;

// Compo main
int main() {
    int opcao;

    do {
        printf("0 - Sair\n");
        printf("1 - Cadastrar Pessoa\n");
        printf("2 - Listar Pessoa\n");
        printf("Digite a opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                printf("Bye!\n");
                break;
            case 1:
                cadastrarPessoa();
                break;
            case 2:
                imprimirPessoa();
                break;
            default:
                printf("Opcao invalida!\n\n");
        }
    } while (opcao != 0);

    return 0;
}

// Implementação
int cadastrarPessoa() {
    if (quantidade > TAMANHO) {
        printf("ERROR: vetor de contatos cheio.\n");
        return 0;
    }

    Pessoa novaPessoa;
    printf("Nome: ");
    fgets(novaPessoa.nome, 100, stdin);
    printf("Idade e sexo (m ou f): ");
    scanf("%d %c", &novaPessoa.idade, &novaPessoa.sexo);

    contatos[quantidade] = novaPessoa;
    quantidade++;

    return 1;
}

void imprimirPessoa() {
    for(int i = 0; i < quantidade; i++) {
        printf("Nome: %s\n", contatos[i].nome);
        printf("Idade: %d\n", contatos[i].idade);
        printf("Sexo: %c\n", contatos[i].sexo);
        printf("--------------------------\n");
    }
}