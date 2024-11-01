#include <stdio.h>

int main() {
    char nome[100], cidade[100];
    printf("Digite seu nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strlen(nome) - 1] = '\0';
    printf("Digite sua cidade: ");
    fgets(cidade, sizeof(cidade), stdin);
    cidade[strlen(cidade) - 1] = '\0';
    printf("Ola %s voce nasceu em %s", nome, cidade);
}
