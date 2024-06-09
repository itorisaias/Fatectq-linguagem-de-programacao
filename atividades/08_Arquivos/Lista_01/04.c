/* Escreva um programa que leia o arquivo blog.txt e 
armazene os dados dos 5 posts em uma estrutura. 
Em seguida, apresente seus dados no seguinte 
formato (Titulo: %s\n Postado em: %d\n) e 
exiba também os títulos dos artigos com a menor e a 
maior ano de publicação. */

#include <stdio.h>
#include <string.h>

int main() {
    char titulo[50], tituloMaiorAno[50], tituloMenorAno[50];
    int ano, maior, menor;
    FILE *file = fopen("blog.txt", "r");
    if (file == NULL) {
        printf("Falha ao abrir o arquivo.\n");
        return 1;
    }
    for (int i = 0; i < 5; i++)
    {
        fscanf(file, "%[^\n]", titulo);
        fscanf(file, "%d\n", &ano);

        if (i == 0) {
            maior = ano;
            menor = ano;
            strcpy(tituloMaiorAno, titulo);
            strcpy(tituloMenorAno, titulo);
        }

        if (maior < ano) {
            maior = ano;
            strcpy(tituloMaiorAno, titulo);
        }
        if (menor > ano) {
            menor = ano;
            strcpy(tituloMenorAno, titulo);
        }

        printf("Titulo: %s\n", titulo);
        printf("Ano: %d\n\n", ano);
    }

    printf("Maior [%d] %s \n", maior, tituloMaiorAno);
    printf("Menor [%d] %s \n", menor, tituloMenorAno);
    
    fclose(file);
    return 0;
}