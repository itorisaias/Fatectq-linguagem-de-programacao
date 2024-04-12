#include <stdio.h> // carregamento da biblioteca stdio

int main() {
  int idade = 28;
  float taxa_juros = 1.5;
  char aceitouTermo = 'S';
  char nome[5] = "itor";

  printf("Hello World\n"); // output sem parâmetro
  printf("Usuario aceitou o termo? %c \n", aceitouTermo); // output com parâmetro do tipo char
  printf("Nome do usuario? %s\n", nome); // output com parâmetro do tipo char
  printf("Idade: %d\n", idade); // output com parâmetro do tipo int
  printf("Taxa de juros: %f\n", taxa_juros); // output com parâmetro do tipo float
  printf("Taxa de juros: %.2f\n", taxa_juros); // output com parâmetro do tipo float formatado
  printf("Taxa de juros: %.1f\n", taxa_juros); // output com parâmetro do tipo float formatado

  return 0;
}
