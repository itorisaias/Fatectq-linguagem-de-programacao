#include <stdio.h>

typedef struct {
    char nome[100];
    int idade;
} Pessoa;

void main() {
    FILE *file;
    Pessoa pessoa = {"Itor Isaias", 28};

    file = fopen("exemplo.bin", "wb"); // Abrir um arquivo binário para escrita

    if (file == NULL) { // Verificar se o arquivo foi aberto com sucesso
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fwrite(&pessoa, sizeof(Pessoa), 1, file); // Escrever no arquivo (variavel, tamanho da estrutura, quantidade e vezes, arquivo)

    fclose(file); // Fechar o arquivo
}
