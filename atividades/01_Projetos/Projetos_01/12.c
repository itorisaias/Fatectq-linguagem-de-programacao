/*
### Sistema de Gerenciamento de Guarda-Volumes

Este sistema será desenvolvido para uma empresa fictícia chamada **SafeStore**, que oferece serviços de guarda-volumes para clientes que precisam armazenar pertences por um período determinado. O sistema ajudará a gerenciar os contratos de armazenamento, aplicar descontos e fornecer relatórios sobre as operações.

#### Regras de Negócio:

- **Tipos de Volume:**
  - **Pequeno:** R$ 50,00 por mês (até 1 m³)
  - **Médio:** R$ 100,00 por mês (de 1 m³ até 3 m³)
  - **Grande:** R$ 200,00 por mês (acima de 3 m³)

- **Descontos:**
  - **Contratos Trimestrais:** Desconto de 5% sobre o valor total do período.
  - **Contratos Anuais:** Desconto de 10% sobre o valor total do período.
  - **Clientes Frequentes:** Desconto de 8% sobre o valor total para clientes com mais de 2 contratos realizados no último ano.

#### Funcionalidades do Sistema:

Desenvolver um programa em C que gerencie até 100 contratos de guarda-volumes utilizando vetores simples e funções.

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
- Tipo de volume (1 para Pequeno, 2 para Médio, 3 para Grande)
- Duração do contrato em meses
- Cliente frequente (1 para sim, 0 para não)

#### Resultados e Insights:

O sistema deve calcular e exibir os seguintes resultados:

1. A média do valor de todos os contratos.
2. A média dos contratos de clientes frequentes.
3. O número do contrato com maior valor.
4. O percentual dos contratos anuais em relação ao número total de contratos.
5. O total geral de meses contratados.

#### Requisitos Adicionais:

- Utilizar vetores simples para armazenar os dados dos contratos (número do contrato, tipo de volume, duração do contrato, cliente frequente).
- Implementar a entrada de novos contratos até atingir o limite de 100 contratos.
- Implementar cálculos e apresentação dos resultados conforme descrito.
- Ordenar os contratos pelo valor total em ordem decrescente.

#### Exemplo de entrada:

|Número do Contrato|Tipo de Volume |Duração (meses)|Cliente Frequente|Valor Base |Descontos |Valor Total|
|------------------|---------------|---------------|-----------------|-----------|----------|-----------|
|1                 |Médio          |3              |Sim              |R$ 300,00  |R$ 39,00  |R$ 261,00  |
|2                 |Grande         |12             |Não              |R$ 2.400,00|R$ 240,00 |R$ 2.160,00|
|3                 |Pequeno        |1              |Não              |R$ 50,00   |R$ 0,00   |R$ 50,00   |

#### Resultado esperado:

1. A média do valor de todos os contratos: R$ 823,67
2. A média dos contratos de clientes frequentes: R$ 261,00
3. O número do contrato com maior valor: 2
4. O percentual dos contratos anuais em relação ao número total de contratos: 33,33%
5. O total geral de meses contratados: 16 meses
*/