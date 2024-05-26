#include <stdio.h>

int main() {
    FILE *meuarquivo;
    char tarefas[3][100];

    meuarquivo = fopen("ex1.txt", "w");
    if (meuarquivo == NULL) {
        printf("Error");
        return 1;
    }

    for (int i = 0; i < 3; i++)
    {
        printf("Digite a tarefa %d: ", i + 1);
        setbuf(stdin, NULL);
        fgets(tarefas[i], 100, stdin);
    }

    for (int i = 0; i < 3; i++)
    {
        fprintf(meuarquivo, "%s", tarefas[i]);
    }
    
    fclose(meuarquivo);
    return 0;
}