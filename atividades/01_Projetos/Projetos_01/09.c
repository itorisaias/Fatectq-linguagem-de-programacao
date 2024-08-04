/*
### Sistema de Gerenciamento de Orçamento de Pintura

A empresa PaintPro oferece serviços de pintura para residências e empresas. O sistema deve gerenciar os orçamentos de pintura, calcular os custos e fornecer insights sobre os orçamentos.

#### Regras de Negócio:

- **Tipos de Pintura:**
  - **Pintura Simples:** R$ 25,00 por metro quadrado
  - **Pintura Comum:** R$ 40,00 por metro quadrado
  - **Pintura Premium:** R$ 60,00 por metro quadrado

- **Descontos:**
  - **Desconto para áreas acima de 100 metros quadrados:** 10% sobre o valor total
  - **Desconto para pagamento antecipado:** 10% sobre o valor total
  - **Desconto para clientes novos:** 5% sobre o valor total

- **Acréscimos:**
  - **Acréscimo para pintura em altura (mais de 4 metros):** 15% sobre o valor total

#### Funcionalidades do Sistema:

Desenvolver um programa em C que gerencie até 100 orçamentos de pintura utilizando vetores simples e funções.

#### Menu de Opções:

O programa deve apresentar um menu com as seguintes opções:

0. **Sair**
1. **Inserir mais registros**
2. **Apresentar resultados**
3. **Ordenar os registros pelo valor total do orçamento (decrescente)**
4. **Imprimir registros de orçamento**

#### Dados dos Orçamentos:

Para cada orçamento, o programa deve armazenar as seguintes informações usando vetores simples:

- Número do orçamento
- Tipo de pintura (1 para Simples, 2 para Comum, 3 para Premium)
- Área a ser pintada (em metros quadrados)
- Altura da pintura (em metros)
- Cliente Novo (1 para sim, 0 para não)
- Pagamento antecipado (1 para sim, 0 para não)

#### Resultados e Insights:

O sistema deve calcular e exibir os seguintes resultados:

1. A média do valor de todos os orçamentos.
2. A média dos orçamentos para clientes novos.
3. O número do orçamento com maior valor.
4. O percentual dos orçamentos para pintura Premium em relação ao número total de orçamentos.
5. O total geral de área pintada.

#### Requisitos Adicionais:

- Utilizar vetores simples para armazenar os dados dos orçamentos (número do orçamento, tipo de pintura, área a ser pintada, altura da pintura, cliente novo e pagamento antecipado).
- Implementar a entrada de novos registros até atingir o limite de 100 orçamentos.
- Implementar cálculos e apresentação dos resultados conforme descrito.
- Ordenar os registros pelo valor total do orçamento em ordem decrescente.

#### Exemplo de entrada:

|Número do Orçamento|Tipo de Pintura|Área a Ser Pintada (m²)|Altura da Pintura (m)|Cliente Novo|Pagamento Antecipado|Valor Base|Descontos                                                   |Acréscimos                                                |Valor Total|
|-------------------|----------------|------------------------|---------------------|-------------|---------------------|----------|------------------------------------------------------------|-----------------------------------------------------------|-----------|
|1                  |Comum           |120                    |5                   |Não          |Sim                  |R$ 4.800,00|R$ 480,00 (10%) - R$ 480,00 (10%)                          |R$ 720,00 (15%)                                            |R$ 4.080,00|
|2                  |Simples         |50                     |3                   |Sim          |Não                  |R$ 1.250,00|R$ 62,50 (5%) - R$ 125,00 (10%)                            |R$ 0,00                                                    |R$ 1.062,50|
|3                  |Premium         |80                     |6                   |Não          |Sim                  |R$ 4.800,00|R$ 720,00 (15%) - R$ 480,00 (10%)                          |R$ 720,00 (15%)                                            |R$ 4.320,00|

#### Resultado esperado:

1. A média do valor de todos os orçamentos: R$ 3.144,17
2. A média dos orçamentos para clientes novos: R$ 1.062,50
3. O número do orçamento com maior valor: 1
4. O percentual dos orçamentos para pintura Premium em relação ao número total de orçamentos: 33,33%
5. O total geral de área pintada: 250 m²
*/