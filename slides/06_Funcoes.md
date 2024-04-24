---
marp: true
theme: custom-default
footer: '@itorisaiias - https://itorisaias.com.br'
paginate: true
---

<!-- _backgroundImage: url('./img/hero-background.svg') -->

![bg left:40% 90%](./img/logoFatec.svg)
# **Linguagem de Programação**

Funções.

---

# Agenda

- Introdução às funções
- Função por valor
- Função por referência
- Comparação entre passagem por valor e por referência
- Benefícios das funções por valor e referência

---

![bg](./img/o_que_comem.png)

---

# Introdução às Funções

**O que são funções em programação.**
  - Funções em programação são um conjunto de instruções que realizam uma tarefa específica.

**Por que as funções são importantes.**
  - Podem ser chamadas por outros programas ou por elas mesmas (recursão).
  - Podem receber e retornar valores.
  - Facilitam a reutilização e a leitura do código.

---

![w:700](./img/funcoes.drawio.svg)

---

# Função VS Procedimentos

- Função **retornam** resultado.
- Procedimento **não retornam** resultado.

---

# Parâmetros

Funções podem receber 0 ou N parâmetros;
Funções sempre tem um tipo de retorno;
Todos os parâmetros devem ter um tipo;

---

# Funções - Valor

![w:1000](./img/funcao_valor_exemplo.drawio.svg)

---

# Desafio

Faça um programa em C, que dado um valor imprima 'Sim' se for par ou 'Nao' caso não seja.

---

# Código

```c
#include <stdio.h>
int main() {
  int numero;
  scanf("%d", &numero);
  if (numero % 2 == 0)
    printf("Sim");
  else
    printf("Nao");
  for (int i = 1; i <= 10; i++)
    printf("%d x %d = %d", i, numero, i * numero);
  return 0;
}
```

---

# Refatorando

```c
#include <stdio.h>
int ehPar(int num) {
  return num % 2;
}
void imprimirTabuada(int num) {
  for (int i = 1; i <= 10; i++)
    printf("%d x %d = %d", i, num, i * num);
}
int main() {
  int numero;
  scanf("%d", &numero);
  if (ehPar(numero))
    printf("Sim");
  else
    printf("Nao");
  imprimirTabuada(numero);
  return 0;
}
```

---

![bg](https://media.giphy.com/media/cJZGTqvVk7LspXHfT6/giphy.gif?cid=790b76112kp8uwicxddzqp3h6jz2c3bcavzwffkg0nhjh3ka&ep=v1_gifs_search&rid=giphy.gif&ct=g)

---

# Funções - Referência (ponteiro)

![w:1000](./img/funcao_referencia_exemplo.drawio.svg)

---

# Ponteiro

**O que é um ponteiro**: Um ponteiro é uma _variável_ que armazena o **endereço de memória** de **outra variável**. Ele **"aponta"** para a localização onde um valor está armazenado na **memória**.
**Declarando um ponteiro**: Você declara um ponteiro colocando um asterisco (*) antes do nome da variável. (`int *ptr`)
**Ampersand (&) - Operador de endereço**: O operador `&` é usado para **obter** o **endereço de memória** de uma variável.
**Asterisco (\*) - Operador de desreferência**: O operador `*` é usado para **acessar** o **valor** armazenado no endereço apontado por um ponteiro.

---

# Desafio

Faça um programa em C, que receba 2 valores e troque os valores entre eles (A -> B) (B -> A), a função main deve ter no máximo 5 linhas.

**Saida esperada**
Valores antes da troca: a = 5, b = 12
Valores depois da troca: a = 12, b = 5

---

# Código

😢 Não conseguimos

```c
#include <stdio.h>

int main() {
  int a = 5, b = 10;
  // scanf("%d %d", &a, &b) // Já utilizamos ponteiro e nem sabíamos...
  printf("Valores antes da troca: a = %d, b = %d\n", a, b);
  int temp = a;
  a = b;
  b = temp;
  printf("Valores depois da troca: a = %d, b = %d\n", a, b);
  return 0;
}
```

---

# Refatorando

```c
#include <stdio.h>
void mudarValores(int *ptr, int *ptr) {
  int temp = *ptr1; // *ptr1 realiza a leitura do valor no ponteiro
  *ptr1 = *ptr2; // *ptr1 = atualiza o valor do ponteiro
  *ptr2 = temp;
}
int main() {
  int a = 5, b = 10;
  printf("Valores antes da troca: a = %d, b = %d\n", a, b);
  mudarValores(&a, &b);
  printf("Valores depois da troca: a = %d, b = %d\n", a, b);
  return 0;
}
```

---

# Comparação entre passagem por valor e por referência

**Valor**
- Cópia dos dados
- Segurança, Previsibilidade e Simplicidade

**Referência**
- Eficiência de memória e Desempenho
- Capacidade de modificar argumentos
- Complexidade adicional
- Riscos de modificação acidental

---

# Duvidas

---

# Começando Lista de Funções

---

# Referencia

- [Fundamentos da programação de computadores](https://archive.org/details/fundamentos-da-programacao-de-computadores-algoritmos-pascal-c-c-padrao-ansi-e-java-pdfdrive)
