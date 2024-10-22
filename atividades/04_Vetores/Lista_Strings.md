# Lista de Strings

```c
/*
Playlist recomendada para aprender sobre manipulação de strings em C:
https://youtube.com/playlist?list=PLqJK4Oyr5WSj1JW1ysRNi4Lvw5oUB-4g0&si=3PpvELVFAVTk30k2
*/

#include <stdio.h>
#include <string.h>

```

### **Exercícios Fáceis**

1. **Contagem de Caracteres** (Utilizando `strlen` de `string.h`)
   - **Enunciado**: Escreva um programa que receba uma string e conte quantos caracteres ela possui usando a função `strlen`.
   - **Entrada**: Uma string, por exemplo: `"programacao"`.
   - **Saída**: O número de caracteres, por exemplo: `11`.

2. **Inversão de String** (Utilizando `strrev`)
   - **Enunciado**: Crie um programa que inverta a string dada pelo usuário utilizando a função `strrev`.
   - **Entrada**: Uma string, por exemplo: `"fatec"`.
   - **Saída**: A string invertida, por exemplo: `"cetaf"`.

3. **Remover Espaços** (Manual)
   - **Enunciado**: Escreva um programa que remova todos os espaços em branco de uma string sem usar funções da biblioteca `string.h`.
   - **Entrada**: Uma string com espaços, por exemplo: `"ola mundo"`.
   - **Saída**: A string sem espaços, por exemplo: `"olamundo"`.

4. **Comparar Strings** (Utilizando `strcmp`)
   - **Enunciado**: Escreva um programa que receba duas strings e verifique se elas são iguais usando a função `strcmp`.
   - **Entrada**: Duas strings, por exemplo: `"fatec"` e `"FATEC"`.
   - **Saída**: Se as strings são iguais (`0`) ou diferentes (`1`).

---

### **Exercícios Médios**

1. **Palíndromo** (Manual)
   - **Enunciado**: Desenvolva um programa que verifique se uma string é um palíndromo (lê-se igual de trás para frente), sem usar funções prontas de manipulação de strings.
   - **Entrada**: Uma string, por exemplo: `"arara"`.
   - **Saída**: `Sim` (se for palíndromo) ou `Não` (se não for), por exemplo: `"Sim"`.

2. **Copiar String** (Utilizando `strcpy`)
   - **Enunciado**: Escreva um programa que copie uma string para outra usando a função `strcpy`.
   - **Entrada**: Uma string, por exemplo: `"FATEC"`.
   - **Saída**: A nova string copiada, por exemplo: `"FATEC"`.

3. **Manipulação de Matriz de Strings** (Nome dos Alunos)
   - **Enunciado**: Escreva um programa que armazene os nomes de 5 alunos em uma matriz de strings (array bidimensional). Após armazenar os nomes, o programa deve exibir os nomes em ordem inversa.
   - **Entrada**: 5 strings, por exemplo: `"Ana"`, `"Bruno"`, `"Carlos"`, `"Diana"`, `"Eduardo"`.
   - **Saída**: Exibição dos nomes em ordem inversa, por exemplo: `"Eduardo", "Diana", "Carlos", "Bruno", "Ana"`.

---

### **Exercícios Difíceis**

1. **Concatenar Strings** (Utilizando `strcat`)
   - **Enunciado**: Crie um programa que concatene duas strings utilizando a função `strcat`.
   - **Entrada**: Duas strings, por exemplo: `"Fatec "` e `"Taquaritinga"`.
   - **Saída**: A string concatenada, por exemplo: `"Fatec Taquaritinga"`.

2. **Verificar Substring** (Utilizando `strstr`)
   - **Enunciado**: Desenvolva um programa que verifique se uma substring existe dentro de outra string usando a função `strstr`.
   - **Entrada**: Duas strings, por exemplo: `"programacao"` e `"grama"`.
   - **Saída**: Posição onde a substring foi encontrada ou mensagem indicando que a substring não foi encontrada, por exemplo: `Posição 3`.

3. **Ordenação de Nomes (Bubble Sort em Matriz de Strings)**
   - **Enunciado**: Escreva um programa que leia os nomes de 5 alunos em uma matriz de strings e os ordene em ordem alfabética usando o algoritmo Bubble Sort.
   - **Entrada**: 5 strings, por exemplo: `"Carlos"`, `"Ana"`, `"Bruno"`, `"Eduardo"`, `"Diana"`.
   - **Saída**: A lista de nomes ordenada, por exemplo: `"Ana", "Bruno", "Carlos", "Diana", "Eduardo"`.

---

### **Exercício Extra**

1. **Divisão de Frase em Palavras** (Utilizando `strtok`)
   - **Enunciado**: Escreva um programa que receba uma string contendo uma frase e a divida em palavras, utilizando a função `strtok`. O programa deve exibir cada palavra em uma linha separada.
   - **Entrada**: Uma string com uma frase, por exemplo: `"Aprender C é divertido"`.
   - **Saída**: 
     ```
     Aprender
     C
     é
     divertido
     ```

Esse exercício ajuda a treinar o uso de `strtok` para dividir uma string em substrings com base em um delimitador (no caso, o espaço entre as palavras).
Vídeo de referência: https://youtu.be/_ncrm53eAzU?si=cbOxtQid8uK8KwjH