/*
### Sistema de Gerenciamento de Financiamentos

Este sistema será desenvolvido para uma empresa fictícia chamada **FinanFácil**, que oferece diferentes tipos de financiamentos para clientes. O sistema ajudará a gerenciar os contratos de financiamento, calcular juros e descontos, além de fornecer relatórios sobre as operações.

#### Regras de Negócio:

- **Tipos de Financiamento:**
  - **Financiamento Imobiliário:** Juros de 0,5% ao mês sobre o valor financiado.
  - **Financiamento de Veículos:** Juros de 0,8% ao mês sobre o valor financiado.
  - **Financiamento Pessoal:** Juros de 1,2% ao mês sobre o valor financiado.

- **Descontos:**
  - **Entrada de 20% ou mais:** Desconto de 10% sobre o valor total dos juros.
  - **Pagamentos Antecipados:** Desconto de 5% sobre o valor das parcelas pagas antecipadamente.
  - **Clientes com Bom Histórico:** Desconto de 8% sobre o valor total dos juros para clientes com bom histórico de crédito (definido pelo cliente como "sim" ou "não").

#### Funcionalidades do Sistema:

Desenvolver um programa em C que gerencie até 100 contratos de financiamento utilizando vetores simples e funções.

#### Menu de Opções:

O programa deve apresentar um menu com as seguintes opções:

0. **Sair**
1. **Inserir mais contratos**
2. **Apresentar resultados**
3. **Ordenar os contratos pelo valor total (decrescente)**
4. **Imprimir registros de contratos**

#### Dados dos Contratos:

Para cada contrato, o programa deve armazenar as seguintes informações usando vetores simples:

- Número do contrato
- Tipo de financiamento (1 para Imobiliário, 2 para Veículos, 3 para Pessoal)
- Valor financiado
- Duração do financiamento em meses
- Entrada (em % do valor total)
- Bom histórico de crédito (1 para sim, 0 para não)

#### Resultados e Insights:

O sistema deve calcular e exibir os seguintes resultados:

1. A média do valor total dos financiamentos (incluindo juros e descontos).
2. A média dos financiamentos de clientes com bom histórico de crédito.
3. O número do contrato com maior valor financiado.
4. O percentual dos contratos de financiamento imobiliário em relação ao número total de contratos.
5. O valor total de juros aplicados em todos os contratos.

#### Requisitos Adicionais:

- Utilizar vetores simples para armazenar os dados dos contratos (número do contrato, tipo de financiamento, valor financiado, duração, entrada, bom histórico de crédito).
- Implementar a entrada de novos contratos até atingir o limite de 100 contratos.
- Implementar cálculos e apresentação dos resultados conforme descrito.
- Ordenar os contratos pelo valor total em ordem decrescente.

#### Exemplo de entrada:

|Número do Contrato|Tipo de Financiamento|Valor Financiado|Duração (meses)|Entrada (%)|Bom Histórico|Juros Aplicados|Descontos|Valor Total|
|------------------|---------------------|----------------|---------------|-----------|-------------|---------------|---------|-----------|
|1                 |Imobiliário          |R$ 200.000,00   |240            |20%        |Sim          |R$ 120.000,00  |R$ 9.600,00|R$ 310.400,00|
|2                 |Veículos             |R$ 50.000,00    |60             |10%        |Não          |R$ 24.000,00   |R$ 0,00   |R$ 74.000,00|
|3                 |Pessoal              |R$ 10.000,00    |12             |30%        |Sim          |R$ 1.440,00    |R$ 72,00  |R$ 11.368,00|

#### Resultado esperado:

1. A média do valor total dos financiamentos: R$ 131.256,00
2. A média dos financiamentos de clientes com bom histórico de crédito: R$ 160.884,00
3. O número do contrato com maior valor financiado: 1
4. O percentual dos contratos de financiamento imobiliário em relação ao número total de contratos: 33,33%
5. O valor total de juros aplicados em todos os contratos: R$ 145.440,00
*/