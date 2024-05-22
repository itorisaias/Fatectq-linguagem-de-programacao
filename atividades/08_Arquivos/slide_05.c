#include <stdio.h>

typedef struct {
    char nome[100];
    int idade;
} Pessoa;

void main() {
    FILE *file;
    Pessoa pessoa;

    file = fopen("exemplo.bin", "rb"); // Abrir um arquivo binário para leitura

    if (file == NULL) { // Verificar se o arquivo foi aberto com sucesso
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fread(&pessoa, sizeof(Pessoa), 1, file); // Ler o conteúdo binário

    printf("Nome: %s\n", pessoa.nome);
    printf("Idade: %d\n", pessoa.idade);

    fclose(file); // Fechar o arquivo
}