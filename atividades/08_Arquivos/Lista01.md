# Lista de Exercícios sobre Manipulação de Arquivos em C

## Prazos

- Primeiro prazo: 31/05/2024
- Segundo prazo: 07/06/2024

---

# 1 - Leitura Simples de Arquivo de Texto
Escreva um programa que leia e exiba o conteúdo de um arquivo de texto chamado `mensagem.txt` utilizando `fgets`. (Lembre-se de criar previamente o arquivo `mensagem.txt` e adicionar algum conteúdo).

# 2 - Escrita Simples em Arquivo de Texto
Crie um programa que receba 3 posts (título e ano de publicação) e os salve em um arquivo de texto chamado `blog.txt`.

## Dica
- Lembre-se de consultar a documentação de `stdio.h` (https://petbcc.ufscar.br/stdiofuncoes/#fprintf) para ver qual função faz a gravação em arquivo.

## Entrada

```md
Assembly é de comer?
1999
Aprendendo a programar com C
1992
Aprendendo a programar com Python
2010
```

# 3 - Adicionar Conteúdo em Arquivo de Texto
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

# 4 - Leitura em Arquivo de Texto
Escreva um programa que leia o arquivo `blog.txt` e armazene os dados dos 5 posts em uma estrutura. Em seguida, apresente seus dados no seguinte formato (`Titulo: %s\n Postado em: %d\n`) e exiba também os títulos dos artigos com a **menor** e a **maior** ano de publicação.

`blog.txt`
```md
Assembly é de comer?
1999
Aprendendo a programar com C
1992
Aprendendo a programar com Python
2010
Programando com GO
2024
Utilizando Rust
2021
```

## Dica 
- Lembre-se de que podemos utilizar o `fscanf(file, " %[^\n]", variavel);` para ler dados. (exemplo https://github.com/itorisaias/Fatectq-linguagem-de-programacao/tree/main/atividades/08_Arquivos)

# 5 - Ordenação de Dados em Arquivo CSV

Crie um programa que leia um arquivo CSV chamado `alunos.csv` contendo nomes e notas de alunos (utilize estrutura para simplificar). Ordene os dados por média (em ordem decrescente) e salve o resultado em um novo arquivo chamado `alunos_ordenados.csv`.

`alunos.csv`
```md
3
Itor Isaias,6,4,9,8
Maria Joca,5,3,7,6
Joao Pedro,9,8,9,8.8
```

## Dica
- Note que a primeira linha é a quantidade de registros de alunos
- Ainda não precisamos utilizar sizeof.
- Defina o nome com um valor arbitrário (exemplo 50).

---

# Dúvidas

Caso tenha dúvidas, consulte o material no github - https://github.com/itorisaias/Fatectq-linguagem-de-programacao/tree/main/atividades/08_Arquivos.
