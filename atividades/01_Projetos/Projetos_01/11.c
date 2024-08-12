/*
### Sistema de Gerenciamento de Serviços de Limpeza Doméstica

Este sistema será desenvolvido para uma empresa fictícia de limpeza doméstica, chamada **CleanHome**, que oferece serviços de limpeza para residências com diferentes pacotes e opções personalizadas. O sistema ajudará a gerenciar os pedidos de serviço, aplicar descontos e fornecer relatórios sobre as operações.

#### Regras de Negócio:

- **Pacotes de Limpeza:**
  - **Pacote Básico:** R$ 100,00 por visita (limpeza geral de até 2 horas)
  - **Pacote Completo:** R$ 180,00 por visita (limpeza detalhada de até 4 horas)
  - **Pacote Premium:** R$ 250,00 por visita (limpeza completa + organização e higienização de até 6 horas)

- **Adicionais:**
  - **Limpeza de Janelas:** Acréscimo de 15% sobre o valor total do pacote
  - **Limpeza de Tapetes:** Acréscimo de 10% sobre o valor total do pacote
  - **Limpeza de Áreas Externas:** Acréscimo de 20% sobre o valor total do pacote

- **Descontos:**
  - **Clientes Recorrentes:** Desconto de 10% sobre o valor total para clientes com 4 ou mais visitas mensais
  - **Pacotes Anuais:** Desconto de 15% sobre o valor total do pacote para clientes que contratam o serviço por 12 meses

#### Funcionalidades do Sistema:

Desenvolver um programa em C que gerencie até 100 pedidos de serviço utilizando vetores simples e funções.

#### Menu de Opções:

O programa deve apresentar um menu com as seguintes opções:

0. **Sair**
1. **Inserir mais pedidos**
2. **Apresentar resultados**
3. **Ordenar os pedidos pelo valor total (decrescente)**
4. **Imprimir registros de pedidos**

#### Dados dos Pedidos:

Para cada pedido, o programa deve armazenar as seguintes informações usando vetores simples:

- Número do pedido
- Tipo de pacote (1 para Básico, 2 para Completo, 3 para Premium)
- Adicional (1 para Limpeza de Janelas, 2 para Limpeza de Tapetes, 3 para Limpeza de Áreas Externas, 0 para Nenhum)
- Frequência do serviço (1 para visita única, 4 para 4 vezes por mês, 12 para mensal por 12 meses)
- Cliente recorrente (1 para sim, 0 para não)

#### Resultados e Insights:

O sistema deve calcular e exibir os seguintes resultados:

1. A média do valor de todos os pedidos.
2. A média dos pedidos de clientes recorrentes.
3. O número do pedido com maior valor.
4. O percentual dos pedidos com pacotes anuais em relação ao número total de pedidos.
5. O total geral de visitas contratadas.

#### Requisitos Adicionais:

- Utilizar vetores simples para armazenar os dados dos pedidos (número do pedido, tipo de pacote, adicional, frequência do serviço, cliente recorrente).
- Implementar a entrada de novos pedidos até atingir o limite de 100 pedidos.
- Implementar cálculos e apresentação dos resultados conforme descrito.
- Ordenar os pedidos pelo valor total em ordem decrescente.

#### Exemplo de entrada:

|Número do Pedido|Tipo de Pacote |Adicional              |Frequência|Cliente Recorrente|Valor Base |Acréscimos |Descontos |Valor Total|
|----------------|---------------|-----------------------|----------|------------------|-----------|-----------|----------|-----------|
|1               |Completo       |Limpeza de Janelas      |4         |Sim               |R$ 720,00  |R$ 108,00  |R$ 82,80  |R$ 745,20  |
|2               |Básico         |Nenhum                  |1         |Não               |R$ 100,00  |R$ 0,00    |R$ 0,00   |R$ 100,00  |
|3               |Premium        |Limpeza de Áreas Externas|12        |Sim               |R$ 3.000,00|R$ 600,00  |R$ 540,00 |R$ 3.060,00|

#### Resultado esperado:

1. A média do valor de todos os pedidos: R$ 1.301,73
2. A média dos pedidos de clientes recorrentes: R$ 1.902,60
3. O número do pedido com maior valor: 3
4. O percentual dos pedidos com pacotes anuais em relação ao número total de pedidos: 33,33%
5. O total geral de visitas contratadas: 17 visitas
*/