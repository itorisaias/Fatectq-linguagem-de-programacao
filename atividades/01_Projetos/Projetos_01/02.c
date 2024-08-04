/*
### Sistema de Gerenciamento de Entregas de uma Empresa de E-commerce

A empresa FastShip é especializada em entregas rápidas de produtos comprados online. O sistema deve gerenciar as entregas realizadas, calculando custos e oferecendo insights sobre o desempenho das entregas.

#### Regras de Negócio:

- **Tipos de Entrega:**
  - **Local:** R$ 10,00 por entrega
  - **Regional:** R$ 20,00 por entrega
  - **Nacional:** R$ 50,00 por entrega

- **Custos Adicionais:**
  - **Peso do Pacote:**
    - Até 2kg: Sem custo adicional
    - De 2kg a 5kg: R$ 5,00 adicional
    - Acima de 5kg: R$ 10,00 adicional

- **Prazos de Entrega:**
  - **Até 1 dia:** R$ 15,00 adicional
  - **De 2 a 3 dias:** R$ 10,00 adicional
  - **Acima de 3 dias:** Sem custo adicional

#### Funcionalidades do Sistema:

Desenvolver um programa em C que gerencie até 100 registros de entregas utilizando vetores simples e funções.

#### Menu de Opções:

O programa deve apresentar um menu com as seguintes opções:

0. **Sair**
1. **Inserir mais registros**
2. **Apresentar resultados**
3. **Ordenar os registros pelo valor total da entrega (decrescente)**
4. **Imprimir registros de entregas**

#### Dados das Entregas:

Para cada entrega, o programa deve armazenar as seguintes informações usando vetores simples:

- Número da entrega
- Tipo de entrega (1 para Local, 2 para Regional, 3 para Nacional)
- Peso do pacote em kg
- Prazo de entrega em dias

#### Resultados e Insights:

O sistema deve calcular e exibir os seguintes resultados:

1. A média do valor de todas as entregas.
2. A média das entregas que têm prazo de 1 dia.
3. O número da entrega com maior valor.
4. O percentual das entregas com peso acima de 5kg em relação ao número total de entregas.
5. O total geral de dias de todas as entregas.

#### Requisitos Adicionais:

- Utilizar vetores simples para armazenar os dados das entregas (número da entrega, tipo de entrega, peso e prazo).
- Implementar a entrada de novos registros até atingir o limite de 100 entregas.
- Implementar cálculos e apresentação dos resultados conforme descrito.
- Ordenar os registros pelo valor total da entrega em ordem decrescente.

#### Exemplo de entrada:

|Número da Entrega|Tipo de Entrega|Peso|Prazo (dias)|Valor Base|Custos Adicionais|Valor Total|
|-----------------|---------------|----|------------|----------|-----------------|-----------|
|1                |Local          |3kg |1           |R$ 10,00  |R$ 20,00         |R$ 30,00   |
|2                |Nacional       |6kg |2           |R$ 50,00  |R$ 20,00         |R$ 70,00   |
|3                |Regional       |1kg |4           |R$ 20,00  |R$ 0,00          |R$ 20,00   |

#### Resultado esperado:

1. A média do valor de todas as entregas: R$ 40,00
2. A média das entregas que têm prazo de 1 dia: R$ 30,00
3. O número da entrega com maior valor: 2
4. O percentual das entregas com peso acima de 5kg em relação ao número total de entregas: 33,33%
5. O total geral de dias de todas as entregas: 7
*/