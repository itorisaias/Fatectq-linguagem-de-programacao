/*
# 2 - Escrita Simples em Arquivo de Texto
Crie um programa que receba 3 posts (título e ano de publicação) e os salve em um arquivo de texto chamado `blog.txt`.

## Dica
- Lembre-se de consultar a documentação de `stdio.h` (https://petbcc.ufscar.br/stdiofuncoes/#fprintf) para ver qual função faz a gravação em arquivo.

## Entrada

```md
Assembly é de comer?
1999
Aprendendo a programar com C
1992
Aprendendo a programar com Python
2010
```
*/
#include <stdio.h>
int main () {
    char titulo[50];
    int ano;
    FILE *file = fopen("blog.txt", "w");
    if (file == NULL)
        return 1;
    for (int i = 0; i < 3; i++) {
        scanf(" %[^\n]", titulo);
        scanf("%d", &ano);
        fprintf(file, "%s\n", titulo);
        fprintf(file, "%d\n", ano);
    }
    fclose(file);
    return 0;
}