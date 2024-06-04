# Lista de Exercícios sobre Manipulação de Arquivos em C

## Prazos

- Primeiro prazo: 14/06/2024
- Segundo prazo: 21/06/2024

---

# 1 - Escrita Simples em Arquivo Binário

Crie um programa em C que receba 5 números inteiros do usuário e os salve em um arquivo binário chamado `numeros.bin`.

## Entrada
```md
10 20 30 40 50
```

# 2 - Leitura Simples em Arquivo Binário

Escreva um programa em C que leia e exiba o conteúdo de um arquivo binário chamado `numeros.bin` que contém uma sequência de inteiros. Utilize a função `fread` para ler os dados.

## Saida
```
10 20 30 40 50
```

# 3 - Escrita de Estrutura em Arquivo Binário

Escreva um programa que receba uma estrutura contendo um nome e uma idade, e a salve em um arquivo binário chamado `pessoa.bin`.

## Entrada
```md
Nome: João
Idade: 30
```

# 4 - Escrita e Leitura de Arquivo Binário

Escreva um programa que leia o arquivo `pessoa.bin`, modifique a idade da pessoa, e salve novamente no arquivo.

# 5 - Sistema de Series

Desenvolva um sistema em C para gerenciar uma lista de séries. O sistema deve permitir as seguintes operações:

- Limpar estado (resetar)
- Cadastrar nova série
- Buscar série por nome
- Ordenar séries por ano
- Desativar série (marcar como desativada sem removê-la da lista)


