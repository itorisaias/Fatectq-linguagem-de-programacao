/*
### Projeto 1: Sistema de Gerenciamento de Serviços de Streaming

A empresa Fakeflix surgiu em 2015 com a missão de proporcionar entretenimento de qualidade a preços acessíveis. A empresa oferece diversos planos de streaming que variam conforme o perfil do cliente. O sistema que você vai desenvolver ajudará a gerenciar esses contratos de maneira eficiente.

#### Regras de Negócio:

- **Quantidade de Telas:**
|Plano   |Valor   |
|--------|--------|  
|1 tela  |R$ 30,00|
|2 telas |R$ 50,00| 
|4 telas |R$ 80,00|

- **Tipo de cobrança:**
    - **Plano mensal (recorrente):** Sem desconto
    - **Plano anual:** 10% de desconto sobre valor total

- **Descontos:**
  - **Estudantes:** 10% de desconto sobre valor total

#### Funcionalidades do Sistema:

Desenvolver um programa em C que gerencie até 100 contratos utilizando vetores simples e funções.

#### Menu de Opções:

O programa deve apresentar um menu com as seguintes opções:

0. **Sair**
1. **Inserir mais registros**
2. **Apresentar resultados**
3. **Ordenar os registro por quantidade de telas (decrescente)**
4. **Imprimir contratos**

#### Dados dos Contratos:

Para cada contrato, o programa deve armazenar as seguintes informações usando vetores simples:

- Número do contrato
- Quantidade de telas
- Tipo de cobrança (1 para mensal, 2 para anual)
- Estudante (1 para sim, 0 para não)

#### Resultados e Insights:

O sistema deve calcular e exibir os seguintes resultados:

1. A média do valor de todos os contratos.
2. A média dos contratos de clientes que são estudantes.
3. O número do contrato com maior valor.
4. O percentual dos contratos anuais em relação ao número total de contratos.
5. O total geral de meses contratados.

#### Requisitos Adicionais:

- Utilizar vetores simples para armazenar os dados dos contratos (número do contrato, quantidade de telas, tipo de cobrança, estudante).
- Implementar a entrada de novos registros até atingir o limite de 100 contratos.
- Implementar cálculos e apresentação dos resultados conforme descrito.
- Ordenar os registro por quantidade de telas em ordem decrescente.

#### Exemplo de entrada:

|Numero do contrato|Nome |Telas  |Cobrança|Estudante|Valor         |Valor com desconto|
|------------------|-----|-------|--------|---------|--------------|------------------|
| 1                |João |2 telas|mensal  |sim      |R$ 50,00 - 10%|R$ 45,00          |
| 2                |Maria|4 telas|anual   |         |R$ 80,00 - 10%|R$ 72,00          |
| 3                |Pedro|1 tela |mensal  |         |R$ 30,00      |R$ 30,00          |

#### Resultado esperado:

1. A média do valor de todos os contratos: R$ 49,00
2. A média dos contratos de clientes que são estudantes: R$ 45,00
3. O número do contrato com maior valor: 2
4. O percentual dos contratos anuais em relação ao número total de contratos: 33.33%
5. O total geral de meses contratados: 14 meses
*/