#include <stdio.h>

#define QTD_NOTAS 4 // coluna
#define QTD_ALUNOS 2 // linha

void main() {
    float notas[QTD_ALUNOS][QTD_NOTAS], total_notas;

    for (int aluno = 0; aluno < QTD_ALUNOS; aluno++) { // linha
        for (int nota = 0; nota < QTD_NOTAS; nota++) { // coluna
            printf("Digite a nota %d do aluno %d: ", nota + 1, aluno + 1);
            scanf("%f", &notas[aluno][nota]);
        }

        total_notas = 0;
        for (int i = 0; i < QTD_NOTAS; i++)
        {
            total_notas += notas[aluno][i];
        }
        float media = total_notas / QTD_NOTAS;
        printf("Media %.3f\n", media);
        
        if (media < 6) {
            printf("Precisa estudar mais\n");
        } else if (media >= 6 && media <= 8) {
            printf("Esta na media\n");
        } else if (media > 8 && media <= 10) {
            printf("Parabens\n");
        } else {
            printf("Voce e o bixao\n");
        }

        float maior = notas[aluno][0];
        for (int i = 1; i < QTD_NOTAS; i++)
        {
            if (notas[aluno][i] > maior) {
                maior = notas[aluno][i];
            }
        }
        
        printf("Maior nota %f", maior);
    }
}