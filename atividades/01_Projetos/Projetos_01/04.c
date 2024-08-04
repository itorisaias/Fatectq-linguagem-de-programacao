/*
### Sistema de Gerenciamento de Vendas de uma Loja de Eletrônicos

A TechStore deseja automatizar o gerenciamento de suas vendas. O sistema deve registrar as vendas realizadas, calcular os custos e oferecer insights sobre o desempenho das vendas.

#### Regras de Negócio:

- **Categorias de Produtos:**
  - **Celulares:** R$ 1.000,00 por unidade
  - **Notebooks:** R$ 3.000,00 por unidade
  - **Tablets:** R$ 1.500,00 por unidade
  - **Acessórios:** R$ 200,00 por unidade

- **Descontos:**
  - **Compras acima de R$ 5.000,00:** 10% de desconto sobre o valor total
  - **Clientes VIP:** 15% de desconto sobre o valor total

#### Funcionalidades do Sistema:

Desenvolver um programa em C que gerencie até 100 registros de vendas utilizando vetores simples e funções.

#### Menu de Opções:

O programa deve apresentar um menu com as seguintes opções:

0. **Sair**
1. **Inserir mais registros**
2. **Apresentar resultados**
3. **Ordenar os registros pelo valor total da venda (decrescente)**
4. **Imprimir registros de vendas**

#### Dados das Vendas:

Para cada venda, o programa deve armazenar as seguintes informações usando vetores simples:

- Número da venda
- Categoria do produto (1 para Celulares, 2 para Notebooks, 3 para Tablets, 4 para Acessórios)
- Quantidade
- Cliente VIP (1 para sim, 0 para não)

#### Resultados e Insights:

O sistema deve calcular e exibir os seguintes resultados:

1. A média do valor de todas as vendas.
2. A média das vendas para clientes VIP.
3. O número da venda com maior valor.
4. O percentual das vendas de Notebooks em relação ao número total de vendas.
5. O total geral de produtos vendidos.

#### Requisitos Adicionais:

- Utilizar vetores simples para armazenar os dados das vendas (número da venda, categoria do produto, quantidade e cliente VIP).
- Implementar a entrada de novos registros até atingir o limite de 100 vendas.
- Implementar cálculos e apresentação dos resultados conforme descrito.
- Ordenar os registros pelo valor total da venda em ordem decrescente.

#### Exemplo de entrada:

|Número da Venda|Categoria do Produto|Quantidade|Cliente VIP|Valor Base|Descontos        |Valor Total|
|---------------|--------------------|----------|-----------|----------|-----------------|-----------|
|1              |Celulares           |3         |Sim        |R$ 3.000,00|R$ 450,00        |R$ 2.550,00|
|2              |Notebooks           |2         |Não        |R$ 6.000,00|R$ 600,00        |R$ 5.400,00|
|3              |Acessórios          |5         |Não        |R$ 1.000,00|R$ 0,00          |R$ 1.000,00|

#### Resultado esperado:

1. A média do valor de todas as vendas: R$ 2.983,33
2. A média das vendas para clientes VIP: R$ 2.550,00
3. O número da venda com maior valor: 2
4. O percentual das vendas de Notebooks em relação ao número total de vendas: 33,33%
5. O total geral de produtos vendidos: 10
*/