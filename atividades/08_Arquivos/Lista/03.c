/*
Escreva um programa que adicione 2 posts no final do arquivo `blog.txt`.

## Dica
- Lembre-se de consultar a documentação de `stdio.h` (https://petbcc.ufscar.br/stdiofuncoes/#fprintf) para ver qual função faz a gravação em arquivo.

## Entrada

```md
Programando com GO
2024
Utilizando Rust
2021
```
*/
#include <stdio.h>
int main () {
    char titulo[50];
    int ano;
    FILE *file = fopen("blog.txt", "a");
    if (file == NULL)
        return 1;
    for (int i = 0; i < 2; i++) {
        scanf(" %[^\n]", titulo);
        scanf("%d", &ano);
        fprintf(file, "%s\n", titulo);
        fprintf(file, "%d\n", ano);
    }
    fclose(file);
    return 0;
}