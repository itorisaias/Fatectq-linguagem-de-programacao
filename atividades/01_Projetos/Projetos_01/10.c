/*
### Sistema de Gerenciamento de Transporte de Turismo

A empresa TourTransport oferece serviços de transporte para turistas em diversas cidades. O sistema deve gerenciar os orçamentos e reservas de transporte, calcular os custos e fornecer insights sobre as operações.

#### Regras de Negócio:

- **Tipos de Transporte:**
  - **Ônibus:** R$ 500,00 por dia
  - **Van:** R$ 300,00 por dia
  - **Carro:** R$ 150,00 por dia

- **Descontos e Acréscimos:**
  - **Desconto para reservas de mais de 7 dias:** 10% sobre o valor total
  - **Desconto para grupos maiores de 20 pessoas:** 5% sobre o valor total
  - **Acréscimo para transporte em datas festivas (Natal, Ano Novo, etc.):** 15% sobre o valor total

#### Funcionalidades do Sistema:

Desenvolver um programa em C que gerencie até 100 reservas de transporte utilizando vetores simples e funções.

#### Menu de Opções:

O programa deve apresentar um menu com as seguintes opções:

0. **Sair**
1. **Inserir mais registros**
2. **Apresentar resultados**
3. **Ordenar os registros pelo valor total da reserva (decrescente)**
4. **Imprimir registros de reserva**

#### Dados das Reservas:

Para cada reserva, o programa deve armazenar as seguintes informações usando vetores simples:

- Número da reserva
- Tipo de transporte (1 para Ônibus, 2 para Van, 3 para Carro)
- Número de dias
- Número de pessoas
- Transporte em data festiva (1 para sim, 0 para não)

#### Resultados e Insights:

O sistema deve calcular e exibir os seguintes resultados:

1. A média do valor de todas as reservas.
2. A média das reservas para grupos maiores de 20 pessoas.
3. O número da reserva com maior valor.
4. O percentual das reservas para transporte de Ônibus em relação ao número total de reservas.
5. O total geral de dias reservados.

#### Requisitos Adicionais:

- Utilizar vetores simples para armazenar os dados das reservas (número da reserva, tipo de transporte, número de dias, número de pessoas e transporte em data festiva).
- Implementar a entrada de novos registros até atingir o limite de 100 reservas.
- Implementar cálculos e apresentação dos resultados conforme descrito.
- Ordenar os registros pelo valor total da reserva em ordem decrescente.

#### Exemplo de entrada:

|Número da Reserva|Tipo de Transporte|Número de Dias|Número de Pessoas|Data Festiva|Valor Base|Descontos                                              |Acréscimos                                              |Valor Total|
|-----------------|-------------------|--------------|----------------|------------|----------|-------------------------------------------------------|--------------------------------------------------------|-----------|
|1                |Ônibus            |10            |25               |Sim         |R$ 5.000,00|R$ 500,00 (10%)                                        |R$ 750,00 (15%)                                         |R$ 5.250,00|
|2                |Van               |5             |15               |Não         |R$ 1.500,00|R$ 0,00 (sem desconto)                                |R$ 0,00 (sem acréscimo)                                 |R$ 1.500,00|
|3                |Carro             |7             |5                |Sim         |R$ 1.050,00|R$ 0,00 (sem desconto)                                |R$ 157,50 (15%)                                         |R$ 1.207,50|

#### Resultado esperado:

1. A média do valor de todas as reservas: R$ 2.652,50
2. A média das reservas para grupos maiores de 20 pessoas: R$ 5.250,00
3. O número da reserva com maior valor: 1
4. O percentual das reservas para transporte de Ônibus em relação ao número total de reservas: 33,33%
5. O total geral de dias reservados: 22 dias
*/