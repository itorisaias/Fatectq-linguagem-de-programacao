# **Lista de Exercícios para Treinamento**

### **1. Array com Struct e Funções (Fácil)**
Escreva um programa em C que utilize um array de structs para armazenar informações de 5 alunos (nome, idade e nota). Crie funções para:  
1. Inserir dados dos alunos.  
2. Exibir os dados.  
3. Encontrar o aluno com a maior nota.  

---

### **2. Exportação para CSV (Médio)**
Amplie o programa anterior para exportar os dados dos alunos para um arquivo no formato CSV. O nome do arquivo deve ser solicitado ao usuário.  

---

### **3. Menu com While e Structs (Difícil)**
Implemente um programa em C com um menu interativo utilizando `while`. O menu deve permitir:  
1. Adicionar um produto (nome, preço, quantidade).  
2. Listar produtos cadastrados.  
3. Buscar um produto pelo nome.  
4. Salvar os dados em um arquivo CSV.  
5. Encerrar o programa.  

---

### **4. Simulação de Prédio (Difícil)**  
Implemente um programa que simule um prédio com N andares e 4 apartamentos por andar. Cada apartamento pode estar com a porta aberta ou fechada. Crie funções para:  
1. Alterar o estado de portas de acordo com condições (e.g., todos os múltiplos de 2 abrem).  
2. Apresentar o estado final de todas as portas do prédio.  

---

### **5. Matriz - Soma dos Elementos (Fácil)**  
Escreva um programa que receba uma matriz 3x3 como entrada e calcule a soma de todos os elementos.

Entrada:
```
1 2 3
4 5 6
7 8 9
```

Saída:
```
Soma dos elementos: 45
```

---

### **6. Transposição de Matriz (Fácil)**  
Escreva um programa para calcular a transposta de uma matriz 3x2.

---

### **7. Ordenação de Matriz (Difícil)**  
Ordene os elementos de uma matriz NxN em ordem crescente e reorganize a matriz com os valores ordenados.  

---

### **8. Comparação de Matrizes (Médio)**  
Escreva um programa que verifique se duas matrizes de mesma ordem são iguais.  

---

### **9. Uso de Vetores em Funções (Fácil)**  
Crie um programa que receba um vetor de inteiros e:  
1. Calcule a média dos valores.  
2. Conte quantos valores estão acima da média.  

---

### **10. Busca em Vetor (Médio)**  
Escreva um programa que busque um valor em um vetor e informe sua posição ou diga que ele não foi encontrado.  

---

### **11. Simulação de Tabuleiro (Difícil)**  
Implemente uma versão simplificada do jogo "Batalha Naval" em uma matriz 5x5. Solicite ao jogador dois palpites e informe se acertou ou errou.  

---

### **12. Função com Ponteiros (Fácil)**  
Escreva uma função que receba dois ponteiros para inteiros e troque os valores entre eles.  

```c
void swap(int *valorA, int *valorB) {
    // complete o código
}
```

---

### **13. Jogo da vida**

**Enunciado**:
O jogador começa em um tabuleiro 5x5 e se move nas direções **cima**, **baixo**, **esquerda** e **direita** para explorar o tabuleiro. O tabuleiro contém 3 tipos de células:

- **0**: Célula vazia
- **1**: Célula com item (coleta 1 ponto)
- **2**: Célula com inimigo (perde 1 ponto)

A cada movimento, o jogador coleta pontos ou perde pontos dependendo da célula em que estiver. O jogo termina quando o jogador atinge 5 pontos ou decide sair.

### **Objetivo**:
- O jogador começa em uma posição inicial.
- A cada movimento, o programa atualiza a posição do jogador e exibe o novo tabuleiro.
- O jogador ganha ou perde pontos conforme interage com o tabuleiro.

### **Exemplo de Entrada**:
```
Movimento do jogador (w/a/s/d para cima, esquerda, baixo, direita): s
Movimento do jogador (w/a/s/d para cima, esquerda, baixo, direita): d
```

**Exemplo de Saída**:
```
Tabuleiro Atual:
0 0 0 0 0
0 1 0 2 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0

Jogador está na posição (2,3)
Pontos: 1
```

---

### **14. Simetria em Matrizes (Médio)**  
Escreva um programa que verifique se uma matriz quadrada é simétrica.  

---

### **15. Função Recursiva (Médio)**  
Crie uma função recursiva para calcular a soma de 10 números.  

---

### **16. Sistema de Cadastro com Structs (Difícil)**  
Implemente um sistema de cadastro para uma loja que armazena informações de clientes e produtos. Deve incluir:  
1. Cadastro de clientes e produtos.  
2. Listagem de dados.  
3. Salvar tudo em um arquivo.  

---

### **17. Matrizes em Funções (Fácil)**  
Crie uma função que receba uma matriz e calcule a soma de cada linha, retornando os resultados em um vetor.  

---

### **18. Complete o Código (Fácil)**  
Complete o código abaixo para exibir os números pares de um vetor:  
```c
void exibirPares(int vetor[], int tamanho) {
    // Preencha aqui
}
```

---

### **19. Complete o Código (Médio)**  
Complete o código abaixo para ordenar um vetor em ordem crescente:  
```c
void ordenarVetor(int vetor[], int tamanho) {
    // Preencha aqui
}
```

---

### **20. Complete o Código (Difícil)**  
Complete o código abaixo para salvar dados de uma struct em um arquivo CSV:  
```c
void salvarCSV(StructExemplo dados[], int tamanho, char *nomeArquivo) {
    // Preencha aqui
}
```
