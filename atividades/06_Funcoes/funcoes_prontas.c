#include <stdio.h>
#include <stdbool.h>

// Função que printa 'Ola' no terminal
void digaOla()
{
  printf("Ola\n");
}

// Retorna o dobro de um numero
int dobro(int n1)
{
  return n1 * 2;
}

// Multiplica dois números
int multiplica(int n1, int n2)
{
  return n1 * n2;
}

// Soma dois números
int soma(int n1, int n2)
{
  return n1 + n2;
}

// Função que recebe um numero, e retorna um boolean informa se é primo ou não.
bool ehPrimo(int numero)
{
  if (numero <= 1)
    return false;

  for (int i = 2; i * i <= numero; i++)
    if (numero % i == 0)
      return false;
  return true;
}
