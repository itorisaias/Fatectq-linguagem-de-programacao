#include <stdio.h>

typedef struct {
    char nome[100];
    int idade;
} Pessoa;

int escrever();
int ler();

int main() {
    escrever();
    ler();
    return 0;
}

int escrever() {
    Pessoa pessoas[2] = {
        {"Joao", 26},
        {"Ana", 19}
    };
    FILE *file = fopen("pessoas.bin", "wb");
    if (file == NULL)
        return 1;

    fwrite(&pessoas, sizeof(Pessoa), 2, file);

    fclose(file);
    return 0;
}

int ler() {
    Pessoa pessoas[2];
    FILE *file = fopen("pessoas.bin", "rb");
    if (file == NULL)
        return 1;

    fread(&pessoas, sizeof(Pessoa), 2, file);

    for (int i = 0; i < 2; i++)
    {
        printf("Nome: %s\n", pessoas[i].nome);
    }

    fclose(file);
    return 0;
}
