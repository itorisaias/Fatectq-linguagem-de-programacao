#include <string.h>
#include <stdio.h>

void main() {
    FILE *arq;
    arq = fopen("01.txt", "r");
    if (arq == NULL) {
        printf("Falha\n");
        return;
    }
    /*
    char cidade[100];
    char estado[50];

    printf("Digite uma cidade e estado (cidade/estado): ");
    scanf("%[^/]/%[^\n]", cidade, estado);
    printf("Estado: %s \nCidade: %s", estado, cidade);
    fprintf(arq, cidade);
    */
   /*
    fprintf(arq, "itor;1;2\n");
    fprintf(arq, "maria;1;2\n");
    fprintf(arq, "joao;1;2\n");
    fprintf(arq, "joana;1;2\n");
   */

    // palavra;numero;numero
    char nome[10];
    int n1, n2;

    while (fscanf(arq, "%[^;];%d;%d\n", nome, &n1, &n2) == 3) {
        printf("Nome: %s | N1: %d | N2: %d\n", nome, n1, n2);
    }
 
    fclose(arq);
}