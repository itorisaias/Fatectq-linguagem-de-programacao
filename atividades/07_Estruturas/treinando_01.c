#include <stdio.h>

int main() {
  char nome[100];
  int idade;
  char sexo;

  printf("Nome: ");
  // fgets(nome, 100, stdin); // leitura de string de utilizando função pronta
  scanf("%[^\n]", nome); // leitura de strings até o \n

  printf("Idade: ");
  scanf("%d", &idade);

  printf("Sexo (f ou m): ");
  // getchar(); // quando fazemos um scanf de carácter logo após um \n (seria enter da idade), o programa acaba pegando o lixo de memoria para isso precisamos limpar antes
  scanf("%c", &sexo);

  printf("Nome: %s \n", nome);
  printf("Idade: %d\n", idade);
  printf("Sexo: %c\n", sexo);
}
