#include <stdio.h>
#include <string.h>

#define QTD_NOME 5
#define TAM_NOME 100

int main() {
    char nomes[QTD_NOME][TAM_NOME];
    char palavra[TAM_NOME];

    printf("Digite %d nomes:\n", QTD_NOME);
    for (int i = 0; i < QTD_NOME; i++) {
        printf("Nome %d: ", i + 1);
        fgets(nomes[i], TAM_NOME, stdin);
        size_t len = strlen(nomes[i]);
        if (len > 0 && nomes[i][len - 1] == '\n') {
            nomes[i][len - 1] = '\0';
        }
    }

    printf("Digite a palavra para buscar: ");
    fgets(palavra, TAM_NOME, stdin);

    size_t len = strlen(palavra);
    if (len > 0 && palavra[len - 1] == '\n') {
        palavra[len - 1] = '\0';
    }

    printf("\nNomes que contêm a palavra \"%s\":\n", palavra);
    int encontrou = 0;
    for (int i = 0; i < QTD_NOME; i++) {
        if (strstr(nomes[i], palavra) != NULL) {
            printf("%s\n", nomes[i]);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhum nome contém a palavra \"%s\".\n", palavra);
    }

    return 0;
}
