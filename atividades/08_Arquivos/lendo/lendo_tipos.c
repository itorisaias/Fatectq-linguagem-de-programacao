#include <stdio.h>

int main() {
    char titulo[100];
    int ano, maiorAno, menorAno;
    FILE *file = fopen("arquivo.txt", "r");
    if (file == NULL) {
        return 1;
    }

    for (int i = 0; i < 4; i++)
    {
        // Lendo registros do arquivo
        fscanf(file, " %[^\n]", titulo);
        fscanf(file, "%d", &ano);
        
        // Processando
        if (i == 0)
            menorAno = maiorAno = ano;
        if (menorAno > ano)
            menorAno = ano;
        if (maiorAno < ano)
            maiorAno = ano;

        printf("Titulo: %s\n", titulo);
        printf("Ano: %d\n\n", ano);
    }

    printf("Menor ano: %d\n", menorAno);
    printf("Maior ano: %d\n", maiorAno);

    fclose(file);
}