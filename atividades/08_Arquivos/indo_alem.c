#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINHA 256

typedef struct
{
    char nome[50];
    int idade;
    char sexo[10];
} Pessoa;

int main()
{
    FILE *file;
    char linha[MAX_LINHA];
    int count = 0;
    int capacidade = 10;

    // Alocando memória para armazenar as pessoas
    Pessoa *pessoas = malloc(capacidade * sizeof(Pessoa));
    if (pessoas == NULL)
    {
        perror("Erro ao alocar memória");
        return 1;
    }

    // Abrindo o arquivo CSV para leitura
    file = fopen("dados.csv", "r");
    if (file == NULL)
    {
        perror("Erro ao abrir o arquivo");
        free(pessoas);
        return 1;
    }

    // Lendo o cabeçalho e ignorando
    fgets(linha, MAX_LINHA, file);

    // Lendo cada linha do arquivo
    while (fgets(linha, MAX_LINHA, file) != NULL)
    {
        if (count >= capacidade)
        {
            capacidade *= 2;
            pessoas = realloc(pessoas, capacidade * sizeof(Pessoa));
            if (pessoas == NULL)
            {
                perror("Erro ao realocar memória");
                fclose(file);
                return 1;
            }
        }

        // Separando os campos
        char *token = strtok(linha, ";");
        strcpy(pessoas[count].nome, token);

        token = strtok(NULL, ";");
        pessoas[count].idade = atoi(token);

        token = strtok(NULL, "\n");
        strcpy(pessoas[count].sexo, token);

        count++;
    }

    // Fechando o arquivo
    fclose(file);

    // Exibindo os dados lidos
    for (int i = 0; i < count; i++)
    {
        printf("Nome: %s, Idade: %d, Sexo: %s\n", pessoas[i].nome, pessoas[i].idade, pessoas[i].sexo);
    }

    // Liberando a memória alocada
    free(pessoas);

    return 0;
}
