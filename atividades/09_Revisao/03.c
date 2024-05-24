/*
# Revisão de Matriz

Modifique o programa anterior para trabalhar com uma matriz. O programa deve agora receber as notas de 2 alunos.
*/

#include <stdio.h>

int main() {
    float notas[2][4], maior, media;

    for (int aluno = 0; aluno < 2; aluno++)
    {
        printf("Aluno %d\n", aluno + 1);
        for (int nota = 0; nota < 4; nota++)
        {
            printf("Nota %d: ", nota + 1);
            scanf("%f", &notas[aluno][nota]);
        }

        media = (notas[aluno][0] + notas[aluno][1] + notas[aluno][2] + notas[aluno][3]) / 4;
        printf("Media: %.2f\n", media);
        if (media < 6) {
            printf("Precisa estudar mais\n");
        } else if (media < 8) {
            printf("Está na média\n");
        } else {
            printf("Parabéns\n");
        }

        maior = notas[aluno][0];
        for (int nota = 0; nota < 4; nota++)
        {
            if (notas[aluno][nota] > maior) {
                maior = notas[aluno][nota];
            }
        }
        printf("Maior nota é: %.2f\n", maior);
    }
    
    return 0;
}