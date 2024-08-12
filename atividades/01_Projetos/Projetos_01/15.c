/*
### Sistema de Gerenciamento de Contratos para Administração de Prédios

Este sistema será desenvolvido para uma empresa fictícia chamada **AdminPred**, especializada na administração de prédios residenciais e comerciais. O sistema ajudará a gerenciar contratos de serviços de administração, calcular valores baseados em critérios específicos, aplicar descontos, e fornecer relatórios sobre as operações.

#### Regras de Negócio:

- **Tipo de Prédio (Baseado na Quantidade de Unidades):**
  - **Até 10 unidades:** R$ 2.000,00 por mês
  - **De 11 a 30 unidades:** R$ 4.000,00 por mês
  - **Acima de 30 unidades:** R$ 6.000,00 por mês

- **Adicional por Serviços Especiais:**
  - R$ 500,00 por mês para serviços de manutenção preventiva
  - R$ 300,00 por mês para serviços de jardinagem

- **Descontos:**
  - **Contratos anuais:** Desconto de 10% sobre o valor total
  - **Contratos de prédios com mais de 30 unidades:** Desconto de 5% sobre o valor total
  - **Cliente fidelidade (mais de 3 anos de contrato):** Desconto de 15% sobre o valor total

#### Funcionalidades do Sistema:

Desenvolver um programa em C que gerencie até 100 contratos de administração de prédios utilizando vetores simples e funções.

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
- Quantidade de unidades no prédio
- Serviços de manutenção preventiva (1 para sim, 0 para não)
- Serviços de jardinagem (1 para sim, 0 para não)
- Contrato anual (1 para sim, 0 para não)
- Cliente fidelidade (1 para sim, 0 para não)

#### Resultados e Insights:

O sistema deve calcular e exibir os seguintes resultados:

1. A média do valor total dos contratos.
2. A média dos contratos de prédios com mais de 30 unidades.
3. O número do contrato com maior valor total.
4. O percentual dos contratos anuais em relação ao número total de contratos.
5. O total de prédios que incluem serviços de manutenção preventiva.

#### Requisitos Adicionais:

- Utilizar vetores simples para armazenar os dados dos contratos (número do contrato, quantidade de unidades no prédio, serviços de manutenção preventiva, serviços de jardinagem, contrato anual, cliente fidelidade).
- Implementar a entrada de novos contratos até atingir o limite de 100 contratos.
- Implementar cálculos e apresentação dos resultados conforme descrito.
- Ordenar os contratos pelo valor total em ordem decrescente.

#### Exemplo de entrada:

|Número do Contrato|Quantidade de Unidades|Manutenção Preventiva|Jardinagem|Anual|Fidelidade|Valor Base|Adicional|Descontos|Valor Total|
|------------------|----------------------|---------------------|----------|------|----------|----------|---------|---------|-----------|
|1                 |35                    |Sim                  |Sim       |Sim   |Sim       |R$ 6.000,00|R$ 800,00|R$ 1.020,00|R$ 5.780,00|
|2                 |15                    |Não                  |Sim       |Não   |Não       |R$ 4.000,00|R$ 300,00|R$ 0,00  |R$ 4.300,00|
|3                 |8                     |Sim                  |Não       |Sim   |Sim       |R$ 2.000,00|R$ 500,00|R$ 375,00|R$ 2.125,00|

#### Resultado esperado:

1. A média do valor total dos contratos: R$ 4.068,33
2. A média dos contratos de prédios com mais de 30 unidades: R$ 5.780,00
3. O número do contrato com maior valor total: 1
4. O percentual dos contratos anuais em relação ao número total de contratos: 66,67%
5. O total de prédios que incluem serviços de manutenção preventiva: 2
*/