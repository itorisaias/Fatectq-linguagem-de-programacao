/*
### Sistema de Gerenciamento de Lavagem de Veículos

Este sistema será desenvolvido para uma empresa fictícia chamada **AutoClean Pro**, especializada em serviços de lavagem de veículos. O sistema ajudará a gerenciar contratos de lavagem, calcular custos baseados em critérios específicos e fornecer relatórios sobre os serviços prestados.

#### Regras de Negócio:

- **Tipo de Lavagem:**
  - **Simples:** R$ 60,00 por veículo
  - **Completa:** R$ 120,00 por veículo
  - **Premium:** R$ 180,00 por veículo

- **Desconto por Tipo de Veículo:**
  - **Moto:** 10% de desconto
  - **Carro:** Sem desconto
  - **SUV/Van:** 5% de desconto
  - **Caminhão:** 15% de desconto

- **Adicional por Tipo de Lavagem:**
  - **Veículo Pequeño:** Sem adicional
  - **Veículo Médio:** R$ 30,00 por veículo
  - **Veículo Grande:** R$ 60,00 por veículo

- **Desconto Adicional para Clientes Frequentes:**
  - **Mais de 10 lavagens no mês:** 10% de desconto adicional sobre o valor total

#### Funcionalidades do Sistema:

Desenvolver um programa em C que gerencie até 100 contratos de lavagem de veículos utilizando vetores simples e funções.

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
- Tipo de lavagem (1 para Simples, 2 para Completa, 3 para Premium)
- Tipo de veículo (1 para Moto, 2 para Carro, 3 para SUV/Van, 4 para Caminhão)
- Tipo de veículo (1 para Pequeno, 2 para Médio, 3 para Grande)
- Frequência de serviços no mês (em número de vezes)

#### Resultados e Insights:

O sistema deve calcular e exibir os seguintes resultados:

1. A média do valor total dos contratos.
2. A média dos contratos para clientes frequentes (mais de 10 lavagens no mês).
3. O número do contrato com maior valor total.
4. O percentual dos contratos para cada tipo de veículo em relação ao número total de contratos.
5. O total de veículos de cada tipo (Pequeno, Médio, Grande) lavados.

#### Requisitos Adicionais:

- Utilizar vetores simples para armazenar os dados dos contratos (número do contrato, tipo de lavagem, tipo de veículo, tipo de veículo, frequência de serviços).
- Implementar a entrada de novos contratos até atingir o limite de 100 contratos.
- Implementar cálculos e apresentação dos resultados conforme descrito.
- Ordenar os contratos pelo valor total em ordem decrescente.

#### Exemplo de entrada e processamento:

|Número do Contrato|Tipo de Lavagem|Tipo de Veículo|Tipo de Veículo|Frequência (vezes por mês)|Valor Base|Desconto por Tipo de Veículo|Desconto Adicional|Adicionais|Valor Total|
|------------------|----------------|----------------|----------------|--------------------------|-----------|----------------------------|-------------------|----------|-----------|
|1                 |Completa        |Carro           |Médio           |12                       |R$ 120,00  |R$ 0,00                     |R$ 12,00           |R$ 30,00 |R$ 138,00 |
|2                 |Premium         |SUV/Van         |Grande          |5                        |R$ 180,00  |R$ 9,00                     |R$ 0,00            |R$ 60,00 |R$ 171,00 |
|3                 |Simples         |Moto            |Pequeno         |15                       |R$ 60,00   |R$ 6,00                     |R$ 6,00            |R$ 0,00  |R$ 60,00  |

#### Resultado esperado:

1. A média do valor total dos contratos: R$ 156,00
2. A média dos contratos para clientes frequentes: R$ 138,00
3. O número do contrato com maior valor total: 1
4. O percentual dos contratos para cada tipo de veículo:
   - Motos: 33,33%
   - Carros: 33,33%
   - SUVs/Vans: 33,33%
   - Caminhões: 0%
5. Total de veículos de cada tipo:
   - Veículos Pequenos: 1
   - Veículos Médios: 1
   - Veículos Grandes: 1
*/