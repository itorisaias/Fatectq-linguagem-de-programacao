---
marp: true
theme: custom-default
footer: '@itorisaiias - https://itorisaias.com.br'
paginate: true
---

<!-- _backgroundImage: url('./img/hero-background.svg') -->

![bg left:40% 90%](./img/logoFatec.svg)
# **Linguagem de Programação**

Estruturas.

---

# Agenda

- Registros (Estruturas)
  - Sintaxes
  - Declarando
  - Acessando "atributos"
  - Exercícios

---

# Registros ou Estruturas

Permitem combinar vários tipos (primitivos) de dados sob um único nome, útil para representar objetos complexos. Cada membro de uma estrutura pode ter um tipo de dados diferente, facilitando a organização e manipulação de dados em programas.

## **abstração**/**agrupamento**

---

# Sintaxes

```c
typedef struct {      // typedef struct {
  char nome[50];      //    tipo atributo;
  int ano_nascimento; //    tipo atributo;
} Pessoa1;            // } Nome_Estrutura;
```

```c
struct Pessoa2 {      // struct Nome_Estrutura {
  char nome[50];      //    tipo atributo;
  int ano_nascimento; //    tipo atributo;
};                    // };
```

> A diferença principal está na conveniência de uso. Usar `typedef` permite declarar variáveis da estrutura sem repetir `struct`, tornando o código mais limpo e legível

---

# What the hell is this

## **typedef**

Cria **apelidos** para tipos de dados existentes, simplificando a declaração de variáveis e aumentando a legibilidade do código, especialmente útil para tipos complexos como **estruturas** ou ponteiros para funções.

---

# Declarando

```c
typedef struct {
  char nome[50];
  int ano_nascimento;
} Pessoa;

Pessoa p1 = {"Itor Isaias", 1996}; // Criando variável p2 e atribuindo valores.
```

---

# Atribuindo

```c
#include <stdio.h>

typedef struct {
  char nome[50];
  int ano_nascimento;
} Pessoa;

Pessoa p1;

p1.ano_nascimento = 1996;
// p1.nome = "Itor Isaias" // Isso não funciona
strcpy(p1.nome, "Itor Isaias"); // Quando queremos atribuir dados á string precisamos usar strcpy de stdio.h
```

---

# Acessando "atributos"

```c
#include <stdio.h>
typedef struct {
  char nome[50];
  int ano_nascimento;
} Pessoa;
void main() {
  Pessoa p1;
  scanf("%d", &p1.ano_nascimento);
  scanf("%[^\n]", p1.nome); // não precisamos utilizar & quando for string
  // fgets(p1.nome, 50, stdin); // outra forma de ler string
  printf("Pessoa \nNome: %s \nAno: %d", p1.nome, p1.ano_nascimento);
}
```

---

# Exercícios

- 01 - Faça a a leitura de um registro nome, idade e sexo sem utilizar struct
- 02 - Refaça o programa utilizando struct (Pessoa)
- 03 - Agora adicione uma estrutura nova para salvar a data nascimento de Pessoa

---

![bg](./img/3o6MbudLhIoFwrkTQY.webp)

---

# Lista

---

# Referências

- [Fundamentos da programação de computadores](https://archive.org/details/fundamentos-da-programacao-de-computadores-algoritmos-pascal-c-c-padrao-ansi-e-java-pdfdrive)
