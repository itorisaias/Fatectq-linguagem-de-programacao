/* Escreva um programa que leia e exiba o conteúdo de um arquivo de texto chamado `mensagem.txt` 
utilizando `fgets`. 
(Lembre-se de criar previamente o arquivo `mensagem.txt` e adicionar algum conteúdo).*/

#include <stdio.h>
int main() {
    char buf[255];
    FILE *file = fopen("mensagem.txt", "r");
    if (file == NULL)
        return 1;
    while(fgets(buf, sizeof(buf), file) != NULL)
        printf("%s", buf);
    fclose(file);
    return 0;
}
