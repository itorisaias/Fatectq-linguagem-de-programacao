---
marp: true
theme: custom-default
footer: '@itorisaiias - https://itorisaias.com'
---

# Agenda

- Variáveis, constantes e tipos de dados
- Entrada e saída de dados
  - Entradas: `scanf`, `printf`, `getch`
  - Saída: `printf`
- Operadores
  - Aritméticos: `+`, `-`, `*`, `/`, `%`
  - Lógicos: `&&`, `||`, `!`
  - Comparação: `==` `!=`, `>`, `<`
- Estruturas de Controle
  - Condicional: `if`, `else`, `else if`,  `switch`, `case`
  - Repetição: `for`, `while`, `do while`

---

# Variáveis, constantes e tipos de dados

- Variáveis são espaços de memória reservados para armazenar valores.
- Os tipos de dados definem o tipo de valor que uma variável pode armazenar, como inteiros, ponto flutuante, caracteres, booleanos, entre outros.
- Exemplos de tipos de dados comuns incluem int (para números inteiros), float (para números decimais), char (para caracteres) e bool (para valores booleanos).

---

![var_const_dados](/slides/img/var_const_dados.drawio.svg)

---

# Variáveis, constantes e tipos de dados - Código

```c
// constante
#define PI = 3.45

void main() {
  // variáveis
  int idade = 28;
  float taxa_juros = 1.5;
  double premio_mega_sena = ;
  char nome = "Itor Isaias";
  bool formado = true;
}
```

---

# Entrada e saída de dados

---

# Entrada e saída de dados - Código

```c
```

---

# Operadores

- Operadores são símbolos que realizam operações em variáveis e valores.
  - aritméticos: adição (`+`), subtração (`-`), multiplicação (`*`), divisão (`/`) e módulo (`%`).
  - lógicos: AND (`&&`), OR (`||`) e NOT (`!`).
  - relacionais (ou de comparação): igualdade (`==`), desigualdade (`!=`), maior que (`>`), menor que (`<`), entre outros.

---

# Operadores - Código

```c
#define P1 = 10; // constante

void main() {
  float p1_aluno = 7.0; // variável float
  float p2_aluno = 6.5; // variável float
  int faltas = 2; // variável int

  float total_p = p1_aluno + p2_aluno; // adição
  float qtd_pontos_faltou_p1 = P1 - p1_aluno; // subtração
  float media = total_p / 2; // divisão
  float porcentagem_p1 = (p1_aluno * 100) / P1; // multiplicação e divisão
  bool p1_e_par = p1_aluno % 2 == 0; // módulo e igualdade
  bool aprovado = (media > 6) && faltas < 3; // maior que; operador lógico AND; menor que
}
```

---

# Estruturas de Controle

- As estruturas de controle permitem que um programa tome decisões e repita ações com base em condições.
- O comando if-else permite que um programa execute certas instruções se uma condição for verdadeira e outras instruções se a condição for falsa.
- Os loops, como while e for, permitem que um programa execute um bloco de código repetidamente enquanto uma condição específica for verdadeira.

---

# Estruturas de Controle - Condicional - Código

```c
```

---

# Estruturas de Controle - Repetição - Código

```c
```
