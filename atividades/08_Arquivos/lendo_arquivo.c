#include <stdio.h>

int main() {
    FILE *meuarquivo;
    char texto[10];
    int num = 10;
    meuarquivo = fopen("contatos.txt", "a");
    if (meuarquivo == NULL) {
        printf("Error");
        return 1;
    }
    /*while (fgets(texto, 10, meuarquivo) != NULL) {
        printf("%s", texto);
    }*/
    fprintf(meuarquivo, "Sextou galera %d", num);

    fclose(meuarquivo);
    return 0;
}