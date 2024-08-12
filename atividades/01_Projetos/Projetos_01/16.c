/*
### Sistema de Gerenciamento de Lavagem de Roupas

Este sistema será desenvolvido para uma empresa fictícia chamada **CleanWear**, especializada em serviços de lavagem e cuidado de roupas. O sistema ajudará a gerenciar os contratos de lavagem, calcular valores baseados em critérios específicos, aplicar descontos, e fornecer relatórios sobre as operações.

#### Regras de Negócio:

- **Tipo de Serviço:**
  - **Lavagem Padrão:** R$ 15,00 por peça
  - **Lavagem Delicada:** R$ 25,00 por peça
  - **Lavagem a Seco:** R$ 35,00 por peça

- **Desconto por Volume:**
  - **Até 20 peças:** Sem desconto
  - **De 21 a 50 peças:** 5% de desconto sobre o valor total
  - **Acima de 50 peças:** 10% de desconto sobre o valor total

- **Adicional por Tipo de Roupa:**
  - **Roupas com Manchas Difíceis:** R$ 10,00 por peça
  - **Roupas de Lã e Seda:** R$ 15,00 por peça

#### Funcionalidades do Sistema:

Desenvolver um programa em C que gerencie até 100 contratos de serviços de lavagem de roupas utilizando vetores simples e funções.

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
- Tipo de serviço (1 para Lavagem Padrão, 2 para Lavagem Delicada, 3 para Lavagem a Seco)
- Quantidade de peças
- Roupas com manchas difíceis (1 para sim, 0 para não)
- Roupas de lã e seda (1 para sim, 0 para não)

#### Resultados e Insights:

O sistema deve calcular e exibir os seguintes resultados:

1. A média do valor total dos contratos.
2. A média dos contratos que incluem roupas com manchas difíceis.
3. O número do contrato com maior valor total.
4. O percentual dos contratos que possuem mais de 50 peças em relação ao número total de contratos.
5. O total de peças de roupas delicadas lavadas.

#### Requisitos Adicionais:

- Utilizar vetores simples para armazenar os dados dos contratos (número do contrato, tipo de serviço, quantidade de peças, roupas com manchas difíceis, roupas de lã e seda).
- Implementar a entrada de novos contratos até atingir o limite de 100 contratos.
- Implementar cálculos e apresentação dos resultados conforme descrito.
- Ordenar os contratos pelo valor total em ordem decrescente.

#### Exemplo de entrada:

|Número do Contrato|Tipo de Serviço|Quantidade de Peças|Manchas Difíceis|Lã/Seda|Valor Base|Descontos|Adicionais|Valor Total|
|------------------|----------------|--------------------|-----------------|-------|----------|---------|----------|-----------|
|1                 |Lavagem Delicada|30                  |Sim              |Não    |R$ 750,00 |R$ 37,50 |R$ 300,00 |R$ 1.012,50|
|2                 |Lavagem a Seco  |60                  |Não              |Sim    |R$ 2.100,00|R$ 210,00|R$ 900,00 |R$ 2.790,00|
|3                 |Lavagem Padrão  |10                  |Não              |Não    |R$ 150,00 |R$ 0,00  |R$ 0,00   |R$ 150,00  |

#### Resultado esperado:

1. A média do valor total dos contratos: R$ 1.317,50
2. A média dos contratos que incluem roupas com manchas difíceis: R$ 1.012,50
3. O número do contrato com maior valor total: 2
4. O percentual dos contratos com mais de 50 peças em relação ao número total de contratos: 66,67%
5. O total de peças de roupas delicadas lavadas: 60 peças
*/