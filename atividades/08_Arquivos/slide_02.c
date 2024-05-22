#include <stdio.h>

void main() {
    FILE *file;
    char buffer[256];

    file = fopen("exemplo.txt", "r"); // Abrir o arquivo para leitura

    if (file == NULL) { // Verificar se o arquivo foi aberto com sucesso
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    while (fgets(buffer, 256, file) != NULL) { // Ler e imprimir o conteúdo do arquivo
        printf("%s", buffer);
    }

    fclose(file); // Fechar o arquivo
}
