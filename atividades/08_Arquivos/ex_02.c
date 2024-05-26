#include <stdio.h>

int main() {
    FILE *meuarquivo;
    char tarefas[3][100];

    meuarquivo = fopen("ex1.txt", "r");
    if (meuarquivo == NULL) {
        printf("Error");
        return 1;
    }

    for (int i = 0; i < 3; i++)
    {
        fscanf(meuarquivo, " %[^\n]", tarefas[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", tarefas[i]);
    }
    
    
    fclose(meuarquivo);
    return 0;
}