#include <stdio.h>

void main() {
    FILE *file;
    file = fopen("exemplo.txt", "r"); // Abrir um arquivo para leitura

    if (file == NULL) { // Verificar se o arquivo foi aberto com sucesso
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    if (fclose(file) != 0) { // Fechar o arquivo
        printf("Erro ao fechar o arquivo.\n");
    }
}