/*
### Sistema de Gerenciamento de Aluguéis de Carros

A RentCar oferece uma variedade de carros para aluguel. O sistema deve gerenciar os aluguéis realizados, calcular os custos e fornecer insights sobre os aluguéis.

#### Regras de Negócio:

- **Tipos de Carros:**
  - **Econômico:** R$ 80,00 por dia
  - **SUV:** R$ 150,00 por dia
  - **Luxo:** R$ 250,00 por dia

- **Acréscimos:**
  - **Aluguel acima de 5 dias:** 10% de desconto sobre o valor base
  - **Seguro do veículo:** 10% de acréscimo sobre o valor base por dia

#### Funcionalidades do Sistema:

Desenvolver um programa em C que gerencie até 100 registros de aluguéis utilizando vetores simples e funções.

#### Menu de Opções:

O programa deve apresentar um menu com as seguintes opções:

0. **Sair**
1. **Inserir mais registros**
2. **Apresentar resultados**
3. **Ordenar os registros pelo valor total do aluguel (decrescente)**
4. **Imprimir registros de aluguéis**

#### Dados dos Aluguéis:

Para cada aluguel, o programa deve armazenar as seguintes informações usando vetores simples:

- Número do aluguel
- Tipo de carro (1 para Econômico, 2 para SUV, 3 para Luxo)
- Número de dias
- Seguro do veículo (1 para sim, 0 para não)

#### Resultados e Insights:

O sistema deve calcular e exibir os seguintes resultados:

1. A média do valor de todos os aluguéis.
2. A média dos aluguéis com seguro do veículo.
3. O número do aluguel com maior valor.
4. O percentual dos aluguéis de carros de luxo em relação ao número total de aluguéis.
5. O total geral de dias alugados.

#### Requisitos Adicionais:

- Utilizar vetores simples para armazenar os dados dos aluguéis (número do aluguel, tipo de carro, número de dias e seguro do veículo).
- Implementar a entrada de novos registros até atingir o limite de 100 aluguéis.
- Implementar cálculos e apresentação dos resultados conforme descrito.
- Ordenar os registros pelo valor total do aluguel em ordem decrescente.

#### Exemplo de entrada:

|Número do Aluguel|Tipo de Carro|Dias|Seguro do Veículo|Valor Base|Acréscimos                  |Valor Total|
|-----------------|-------------|----|------------------|----------|----------------------------|-----------|
|1                |1            |2   |1                 |R$ 160,00 |R$ 16,00 (10% de acréscimo) |R$ 176,00  |
|2                |3            |10  |0                 |R$ 2500,00|R$ 250,00 (10% de desconto)|R$ 2250,00 |
|3                |2            |1   |1                 |R$ 150,00 |R$ 15,00 (10% de acréscimo) |R$ 165,00  |

#### Resultado esperado:

1. A média do valor de todos os aluguéis: R$ 1975,33
2. A média dos aluguéis com seguro do veículo: R$ 1975,33
3. O número do aluguel com maior valor: 2
4. O percentual dos aluguéis de carros de luxo em relação ao número total de aluguéis: 33,33%
5. O total geral de dias alugados: 13 dias
*/