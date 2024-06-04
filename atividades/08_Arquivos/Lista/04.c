/*
# 4 - Leitura em Arquivo de Texto
Escreva um programa que leia o arquivo `blog.txt` e armazene os dados dos 5 posts em uma estrutura. Em seguida, apresente seus dados no seguinte formato (`Titulo: %s\n Postado em: %d\n`) 
e exiba também os títulos dos artigos com a **menor** e a **maior** ano de publicação.

`blog.txt`
```md
Assembly é de comer?
1999
Aprendendo a programar com C
1992
Aprendendo a programar com Python
2010
Programando com GO
2024
Utilizando Rust
2021
```

## Dica 
- Lembre-se de que podemos utilizar o `fscanf(file, " %[^\n]", variavel);` para ler dados. (exemplo https://github.com/itorisaias/Fatectq-linguagem-de-programacao/tree/main/atividades/08_Arquivos)
*/

#include <stdio.h>
#include <string.h>
int main () {
    char titulo[50], tituloMaior[50], tituloMenor[40];
    int ano, maior, menor;
    FILE *file = fopen("blog.txt", "r");
    if (file == NULL)
        return 1;
    for (int i = 0; i < 5; i++) {
        fscanf(file, " %[^\n]", titulo);
        fscanf(file, "%d", &ano);

        if (i == 0) {
            maior = menor = ano;
            strcpy(tituloMenor, titulo);
            strcpy(tituloMaior, titulo);
        }   
        if (maior < ano) {
            maior = ano;
            strcpy(tituloMaior, titulo);
        }
        if (menor > ano) {
            menor = ano;
            strcpy(tituloMenor, titulo);
        }

        printf("Titulo: %s\n Postado em: %d\n", titulo, ano);
    }
    printf("\n\nMaior: %s\nMenor: %s", tituloMaior, tituloMenor);
    fclose(file);
    return 0;
}