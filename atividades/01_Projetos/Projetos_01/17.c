/*
### Sistema de Gerenciamento de Vendas de Placas Solares

Este sistema será desenvolvido para a **SolarTech**, especializada na venda e instalação de sistemas de energia solar. O sistema ajudará a gerenciar os contratos de venda com base na quantidade de energia desejada pelos clientes, calcular valores baseados em critérios específicos, aplicar descontos e fornecer relatórios sobre as operações.

#### Regras de Negócio:

- **Quantidade de Energia Desejada:**
  - **Até 5 kW:** Inclui 10 placas Básicas
  - **De 6 a 10 kW:** Inclui 8 placas Intermediárias e 4 placas Básicas
  - **Acima de 10 kW:** Inclui 6 placas Avançadas e 8 placas Intermediárias

- **Preço por Placa:**
  - **Placa Básica:** R$ 800,00 por unidade
  - **Placa Intermediária:** R$ 1.200,00 por unidade
  - **Placa Avançada:** R$ 1.800,00 por unidade

- **Desconto por Quantidade de Placas:**
  - **Até 10 placas:** Sem desconto
  - **De 11 a 30 placas:** 5% de desconto sobre o valor total
  - **Acima de 30 placas:** 10% de desconto sobre o valor total

- **Adicional por Instalação:**
  - **Instalação Básica:** R$ 500,00 por instalação
  - **Instalação Completa:** R$ 1.000,00 por instalação

- **Desconto Adicional para Clientes Residenciais:**
  - **Clientes Residenciais:** 5% de desconto adicional sobre o valor total

#### Funcionalidades do Sistema:

Desenvolver um programa em C que gerencie até 100 contratos de venda e instalação de placas solares utilizando vetores simples e funções.

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
- Quantidade de energia desejada (em kW)
- Tipo de instalação (1 para Instalação Básica, 2 para Instalação Completa)
- Cliente residencial (1 para sim, 0 para não)

#### Resultados e Insights:

O sistema deve calcular e exibir os seguintes resultados:

1. A média do valor total dos contratos.
2. A média dos contratos de clientes residenciais.
3. O número do contrato com maior valor total.
4. O percentual dos contratos com mais de 30 placas em relação ao número total de contratos.
5. O total de placas de cada tipo (Básica, Intermediária, Avançada) utilizadas.

#### Requisitos Adicionais:

- Utilizar vetores simples para armazenar os dados dos contratos (número do contrato, quantidade de energia desejada, tipo de instalação, cliente residencial).
- Implementar a entrada de novos contratos até atingir o limite de 100 contratos.
- Implementar cálculos e apresentação dos resultados conforme descrito.
- Ordenar os contratos pelo valor total em ordem decrescente.

#### Exemplo de entrada e processamento:

|Número do Contrato|Quantidade de Energia (kW)|Tipo de Instalação|Residencial|Placas Básicas|Placas Intermediárias|Placas Avançadas|Valor Base|Desconto por Quantidade|Desconto Adicional|Adicionais|Valor Total|
|------------------|--------------------------|------------------|-----------|--------------|----------------------|----------------|----------|-----------------------|-------------------|----------|-----------|
|1                 |4 kW                      |Completa          |Sim        |10            |0                    |0               |R$ 8.000,00|R$ 0,00                |R$ 400,00          |R$ 1.000,00|R$ 7.600,00|
|2                 |8 kW                      |Básica            |Não        |4             |8                    |0               |R$ 12.800,00|R$ 640,00              |R$ 0,00            |R$ 500,00 |R$ 12.960,00|
|3                 |12 kW                     |Completa          |Sim        |8             |6                    |6               |R$ 22.800,00|R$ 2.280,00            |R$ 1.140,00        |R$ 1.000,00|R$ 20.680,00|

#### Resultado esperado:

1. A média do valor total dos contratos: R$ 13.746,67
2. A média dos contratos de clientes residenciais: R$ 14.890,00
3. O número do contrato com maior valor total: 3
4. O percentual dos contratos com mais de 30 placas em relação ao número total de contratos: 33,33%
5. Total de placas de cada tipo:
   - Placas Básicas: 22
   - Placas Intermediárias: 14
   - Placas Avançadas: 6
*/