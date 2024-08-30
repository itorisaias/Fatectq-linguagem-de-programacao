/*
### Sistema de Gerenciamento de Segurança para Festas

Este sistema será desenvolvido para uma empresa fictícia chamada **SafeParty**, especializada em oferecer serviços de segurança para eventos e festas. O sistema ajudará a gerenciar os contratos de segurança, calcular valores baseados em critérios específicos, aplicar descontos, e fornecer relatórios sobre as operações.

#### Regras de Negócio:

- **Tipos de Evento (Baseado na Quantidade de Pessoas):**
  - **Até 50 pessoas:** R$ 1.000,00 por evento
  - **De 51 a 200 pessoas:** R$ 2.500,00 por evento
  - **Acima de 200 pessoas:** R$ 5.000,00 por evento

- **Adicional por Segurança Armado:**
  - R$ 500,00 por segurança armado adicional (independente do tamanho do evento)

- **Descontos:**
  - **Eventos durante a semana (segunda a quinta-feira):** Desconto de 10% sobre o valor total
  - **Contratos para múltiplos eventos (3 ou mais):** Desconto de 15% sobre o valor total do pacote
  - **Clientes Corporativos:** Desconto de 12% sobre o valor total

#### Funcionalidades do Sistema:

Desenvolver um programa em C que gerencie até 100 contratos de segurança para festas utilizando vetores simples e funções.

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
- Quantidade de pessoas
- Número de seguranças armados
- Evento durante a semana (1 para sim, 0 para não)
- Contrato para múltiplos eventos (1 para sim, 0 para não)
- Cliente corporativo (1 para sim, 0 para não)

#### Resultados e Insights:

O sistema deve calcular e exibir os seguintes resultados:

1. A média do valor total dos contratos de segurança.
2. A média dos contratos de clientes corporativos.
3. O número do contrato com maior valor total.
4. O percentual dos contratos de eventos grandes (mais de 200 pessoas) em relação ao número total de contratos.
5. O total de seguranças armados contratados em todos os eventos.

#### Requisitos Adicionais:

- Utilizar vetores simples para armazenar os dados dos contratos (número do contrato, quantidade de pessoas, número de seguranças armados, evento durante a semana, contrato para múltiplos eventos, cliente corporativo).
- Implementar a entrada de novos contratos até atingir o limite de 100 contratos.
- Implementar cálculos e apresentação dos resultados conforme descrito.
- Ordenar os contratos pelo valor total em ordem decrescente.

#### Exemplo de entrada:

|Número do Contrato|Quantidade de Pessoas|Nº de Seguranças Armados|Semana|Múltiplos Eventos|Corporativo|Valor Base|Adicional|Descontos|Valor Total|
|------------------|---------------------|------------------------|------|-----------------|-----------|----------|---------|---------|-----------|
|1                 |250                  |2                       |Sim   |Não              |Sim        |R$ 5.000,00|R$ 1.000,00|R$ 720,00 |R$ 4.680,00| ***
|2                 |150                  |1                       |Não   |Sim              |Não        |R$ 2.500,00|R$ 500,00 |R$ 450,00 |R$ 2.550,00|
|3                 |40                   |0                       |Sim   |Não              |Não        |R$ 1.000,00|R$ 0,00   |R$ 100,00 |R$ 900,00  |

#### Resultado esperado:

1. A média do valor total dos contratos: R$ 2.910,00
2. A média dos contratos de clientes corporativos: R$ 5.280,00
3. O número do contrato com maior valor total: 1
4. O percentual dos contratos de eventos grandes em relação ao número total de contratos: 33,33%
5. O total de seguranças armados contratados em todos os eventos: 3
*/
