#include <stdio.h>

void main()
{
    FILE *file;

    file = fopen("exemplo.txt", "a"); // Abrir um arquivo para adicionar conteúdo

    if (file == NULL)
    { // Verificar se o arquivo foi aberto com sucesso
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(file, "Adicionando uma nova linha.\n"); // Adicionar conteúdo ao arquivo

    fclose(file); // Fechar o arquivo
}