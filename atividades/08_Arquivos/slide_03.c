#include <stdio.h>

void main() {
    FILE *file;

    file = fopen("exemplo.txt", "w"); // Abrir um arquivo para escrita

    if (file == NULL) { // Verificar se o arquivo foi aberto com sucesso
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(file, "Olá, Mundo!\n"); // Escrever no arquivo
    fprintf(file, "Aprendendo manipulação de arquivos em C.\n");

    fclose(file); // Fechar o arquivo
}