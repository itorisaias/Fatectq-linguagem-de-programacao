---
marp: true
theme: custom-default
footer: '@itorisaiias - https://itorisaias.com.br'
paginate: true
---

<!-- _backgroundImage: url('https://marp.app/assets/hero-background.svg') -->

![bg left:40% 90%](https://www.fatectq.edu.br/img/logoFatec.svg)
# **Linguagem de Programação**

Revisão.

---

# Agenda

- Variáveis, constantes e tipos de dados
- Entrada e saída de dados
  - Entradas: `scanf` e `getch`
  - Saída: `printf`
- Operadores
  - Aritméticos: `+`, `-`, `*`, `/`, `%`, `++` e `--`
  - Lógicos: `&&`, `||` e `!`
  - Comparação: `==` `!=`, `>`, `<`, `<=` e `>=`
- Estruturas de Controle
  - Condicional: `if`, `else`, `else if`,  `switch` e `case`
  - Repetição: `while`, `do while` e `for`

---

![bg w:900](https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExeHBlMjlvdDRhM2ZkaHc5cHlqNHRqeDIzd2lrOXI0ZjBkeWJreDR5diZlcD12MV9naWZzX3NlYXJjaCZjdD1n/BpGWitbFZflfSUYuZ9/giphy.gif)

---

# Variáveis, constantes e tipos de dados

- Variáveis são espaços de memória reservados para armazenar valores.
- Os tipos de dados definem o tipo de valor que uma variável pode armazenar, como inteiros, ponto flutuante, caracteres, booleanos, entre outros.
- Exemplos de tipos de dados comuns incluem int (para números inteiros), float (para números decimais), char (para caracteres) e bool (para valores booleanos).

---

# Variáveis, constantes e tipos de dados

```c
// constante
#define PI = 3.14;

void main() {
  // variáveis
  int idade = 28;
  float taxa_juros = 1.5;
  double premio_mega_sena = 46000000;
  char aceitouTermo = "S";
  char nome[5] = "itor";
  bool formado = true;
}
```

---

![var_const_dados](./img/var_const_dados.drawio.svg)

---

![bg](https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExcDFqdjZ2Nm0xMnhmanU0NGV0MjZhZjZiaHBuaWhqMG45cmNlb3QwdCZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/ZUomWFktUWpFu/giphy-downsized-large.gif)

---

# Entrada e saída de dados

- Funções de entrada (input)
- Funções de saída (output)
- Todas estão na biblioteca stdio (#include <stdio.h>)

---

# Entrada e saída de dados

#### **Entrada**

- `scanf` : É utilizada para fazer a leitura de dados formatados via teclado.

#### Exemplo

```c
#include <stdio.h>

int main() {
  int n; // Inicializa a variável do tipo int

  printf("Digite um número: "); // Imprimi na tela à frase "Digite um número: "
  scanf("%d", &n); // Aguardo usuário realizar a digitação do numero no teclado

  printf("O valor digitado foi %d\n",n); // Imprimi na tela a frase "O valor digitado foi X"

  return 0;
}
```

---

# Entrada e saída de dados

#### **Saida**

```c
#include <stdio.h> // carregamento da biblioteca stdio

int main() {
  int idade = 28;
  float taxa_juros = 1.5;
  char aceitouTermo = "S";
  char nome[5] = "itor";

  printf("Hello World"); // output sem parâmetro
  printf("Usuario aceitou o termo? %c", aceitouTermo); // output com parâmetro do tipo char
  printf("Nome do usuario? %s", nome); // output com parâmetro do tipo char
  printf("Idade: %d", idade); // output com parâmetro do tipo int
  printf("Taxa de juros: %f", taxa_juros); // output com parâmetro do tipo float

  return 0;
}
```

---
# Entrada e saída de dados

#### Tabela - Tipos de dados básicos

|Tipo|Formato|
|---|---|
|int|%d|
|float|%f|
|char|%c|
|char[]|%s|

---

![bg](https://media.giphy.com/media/11sBLVxNs7v6WA/giphy.gif?cid=790b7611ep1j4354alzfhi0fo9jhvmgsig1cu3xwprpu25uq&ep=v1_gifs_search&rid=giphy.gif&ct=g)

---

# Operadores

- Operadores são símbolos que realizam operações em variáveis e valores.
  - Aritméticos: adição (`+`), subtração (`-`), multiplicação (`*`), divisão (`/`), módulo (`%`), incremento (`++`) e decremento (`--`).
  - Lógicos: AND (`&&`), OR (`||`) e NOT (`!`).
  - Relacionais (ou de comparação): igualdade (`==`), desigualdade (`!=`), maior que (`>`), menor que (`<`), maior ou igual (`>=`) e menor ou igual (`<=`).

---

# Operadores - Aritméticos

```c
#include <stdio.h>

int main(void) {
  int a = 5, b = 3;

  int soma = a + b;
  printf("soma de %d e %d é %d\n", a, b, soma);

  int subtracao = a - b;
  printf("subtracao de %d e %d é %d\n", a, b, subtracao);

  int mult = a * b;
  printf("multiplicação de %d e %d é %d\n", a, b, mult);

  int divisao = a / b;
  printf("divisao de %d e %d é %d\n", a, b, divisao);

  int mod = a % b;
  printf("resto da divisão de %d e %d é %d\n", a, b, mod);

  a++;
  printf("incremento: %d\n", a);

  b--;
  printf("decremento: %d\n", b);

  return 0;
}
```

---

# Operadores - Lógicos

```c
#include <stdio.h>

int main(void) {
  int a = 1, b = 1;

  // AND (E)
  int resultado = (a && b);
  printf("%d && %d é %d\n", a, b, resultado);

  // OR (OU)
  resultado = (a || b);
  printf("%d || %d é %d\n", a, b, resultado);

  // NOT (NÃO)
  resultado = !a;
  printf("!%d é %d\n", a, resultado);

  // Combinação de operadores lógicos
  resultado = (a && b) || !a;
  printf("(%d && %d) || !%d é %d\n", a, b, a, resultado);

  return 0;
}
```

---

# Operadores - Relacionais

```c
#include <stdio.h>

int main(void) {
  int a = 5, b = 3;

  // Igualdade
  int resultado = (a == b);
  printf("%d == %d é %d\n", a, b, resultado);

  // Diferença
  resultado = (a != b);
  printf("%d != %d é %d\n", a, b, resultado);

  // Maior
  resultado = (a > b);
  printf("%d > %d é %d\n", a, b, resultado);

  // Menor
  resultado = (a < b);
  printf("%d < %d é %d\n", a, b, resultado);

  // Maior ou igual
  resultado = (a >= b);
  printf("%d >= %d é %d\n", a, b, resultado);

  // Menor ou Igual
  resultado = (a <= b);
  printf("%d <= %d é %d\n", a, b, resultado);

  return 0;
}
```

---

![bg](https://media.giphy.com/media/kyLYXonQYYfwYDIeZl/giphy.gif)

---

# Estruturas de Controle

- As estruturas de controle permitem que um programa tome decisões e repita ações com base em condições.
- O comando if-else permite que um programa execute certas instruções se uma condição for verdadeira e outras instruções se a condição for falsa.
- Os loops, como while e for, permitem que um programa execute um bloco de código repetidamente enquanto uma condição específica for verdadeira.

---

# Estruturas de Controle - Condicional

#### Pseudocódigo:

```
Inicio
  Se (condicao) então
    Instruções;
  Senão
    Instruções;
Fim
```

---

# Estruturas de Controle - Condicional

## **IF**

#### Código em C

```c
#include <stdio.h>

int main(void) {
  int idade = 30; // Declarando e inicializando a variável idade

  if (idade < 18) { // Testando a condição se é maior de idade
    printf("Você é menor de idade.\n");
  }

  return 0;
}
```

---

# Estruturas de Controle - Condicional

## **ELSE**

#### Código em C

```c
#include <stdio.h>

int main() {
  int idade = 30; // Declarando e inicializando a variável idade

  if (idade < 18) { // Testando a condição se é maior de idade
    printf("Você é menor de idade.\n");
  } else { // Senão não é um adulto
    printf("Você é maior de idade.\n");
  }

  return 0;
}
```

---

# Estruturas de Controle - Condicional

## **ELSE IF**

#### Código em C

```c
#include <stdio.h>

int main() {
  int idade = 30; // Declarando e inicializando a variável idade

  if (idade < 18) { // Testando a condição se é maior de idade
    printf("Você é menor de idade.\n");
  } else if (idade >= 18 && idade <= 30) { // Testando a condição se é maior ou igual à 18 E menor ou igual à 30
    printf("Você é jovem adulto.\n");
  } else { // Senão não é um adulto
    printf("Você é adulto.\n");
  }

  return 0;
}
```

---

# Estruturas de Controle - Repetição

## **WHILE**

- Verifica primeiro, executa depois;
- Repete somente enquanto <condição> = verdade;

#### Pseudocódigo:
```
Iniciar a variável de controle

Enquanto (condição) faça
  Instruções;
```

---

# Estruturas de Controle - Repetição

## **WHILE**

#### Código em C
```c
#include <stdio.h>

int main() {
  int contador = 0; // Declarando e inicializando a variável de controle

  while (contador <= 10) { // Testando a condição
    printf("%d ", contador); // Executando um comando dentro do laço
    contador++; // Atualizando a variável de controle
  }

  return 0;
}
```

---

# Estruturas de Controle - Repetição

## **DO WHILE**

- Executa primeiro, verifica depois:
- Repete somente enquanto <condição> = verdadeira;

#### Pseudocódigo:

```
Iniciar a variável de controle

Faca
  Instruções;
Enquanto (condição)
```

---

# Estruturas de Controle - Repetição

## **DO WHILE**

#### Código em C
```c
#include <stdio.h>

int main() {
  int contador = 0; // Declarando e inicializando a variável de controle

  do {
    printf("%d ", contador); // Executando um comando dentro do laço
    contador++; // Atualizando a variável de controle
  } while (contador <= 10)  // Testando a condição

  return 0;
}
```

---

# Estruturas de Controle - Repetição

## **FOR**

- Repetição condicionada a uma contagem;
- Não precisa de variável de controle para o número de execuções;
- A própria estrutura gerencia o incremento da quantidade de execuções;

#### Pseudocódigo:

```
Para (valor inicial até condição_final passo n) faça
  Instruções;
```

```
for (valor_inicial; condição_final; valor_incremento) {
  instruções;
}
```

---

# Estruturas de Controle - Repetição

## **FOR**

#### Código em C:

```c
#include <stdio.h>

int main() {
  int quantidade = 10;

  for (int i = 0; i < quantidade; i++) {
    printf("%d ", i);
  }

  return 0;
}
```

---

# Interpretação - Ideal X Real

---

# Ideal - Conversor de Moeda

**Objetivo:**
O objetivo desta atividade é criar um programa em C que permita aos usuários converter um determinado valor em reais brasileiros (BRL) para dólares americanos (USD), utilizando a cotação do dólar fornecida pelo usuário.

**Instruções:**
1. O programa deve solicitar ao usuário que insira a cotação atual do dólar americano (USD).
2. Em seguida, o programa deve solicitar ao usuário que insira o valor em reais brasileiros (BRL) que deseja converter.
3. Com base na cotação fornecida pelo usuário, o programa deve calcular o valor equivalente em dólares americanos (USD).
4. Por fim, o programa deve exibir o valor em reais (BRL) e o valor equivalente em dólares (USD).

---

# Real - Conversor de Moeda

Criar um programa em C que converta um valor em reais (BRL) para dólares (USD), usando a cotação do dólar informada pelo usuário.

---

![bg w:700](https://repository-images.githubusercontent.com/189922138/85df1100-8613-11e9-80e2-9f11d176680b)

---

# Exercícios

Serão **10 exercícios** para praticar que serão relacionados á conteúdos que **caíram na prova**.

---

1. Criar um programa em C que converta um valor em reais (BRL) para dólares (USD), usando a cotação do dólar informada pelo usuário.
2. a
3. Faça um programa em C que mostre a tabuada de qualquer número escolhido pelo usuário (considerar tabuada do número 1 ao 10).
4. Faça um programa em C (com a estrutura do...while) que leia 20 valores inteiros e:
   1. Encontre e mostre o maior valor;
   2. Encontre e mostre o menor valor;
   3. Calcule e mostre a média dos números lidos;
5. Faça um programa em C (utilize a estrutura for) que leia 10 valores inteiros e:
   1. Encontre e mostre o maior valor
   2. Encontre e mostre o menor valor
   3. Calcule e mostre a média dos números lidos

---

6. Faça um programa em C que exiba na tela os números ímpares entre 100 e 300.
7. Faça um programa em C que receba um número inteiro e positivo, e diga se esse número é primo ou não. Obs: Um número é primo somente quando for divisível por 1 e por ele mesmo.
8. Faça um programa em C que receba a idade de 10 pessoas e mostre quantas são maiores que 18 anos.
9. A prefeitura de uma cidade fez uma pesquisa com 200 pessoas, coletando dados sobre o salário e o número de filhos. A prefeitura deseja saber:
   1.  A média do salário dessas pessoas
   2.  A média do número de filhos
   3.  O maior salário
   4.  A percentagem de pessoas com salários até R$ 150,00
10. a

---

![bg](https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExaHlrMnM5b3BsaWlybHZ0d252MnF3aTYyazhmdGx4NGd1aTJsa3luYSZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/lD76yTC5zxZPG/giphy.gif)
