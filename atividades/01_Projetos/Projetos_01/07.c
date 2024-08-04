/*
### Sistema de Gerenciamento de Inscrições em Eventos Corporativos

A empresa EventCorp organiza uma variedade de eventos corporativos, como conferências, workshops e seminários. O sistema deve gerenciar as inscrições realizadas, calcular os custos e fornecer insights sobre as inscrições.

#### Regras de Negócio:

- **Tipos de Eventos:**
  - **Conferência:** R$ 500,00 por evento
  - **Workshop:** R$ 300,00 por evento
  - **Seminário:** R$ 200,00 por evento

- **Número de Pessoas:** 
  - **Até 5 pessoas:** Sem acréscimo
  - **De 6 a 10 pessoas:** 5% de acréscimo sobre o valor total
  - **Mais de 10 pessoas:** 10% de acréscimo sobre o valor total

- **Acréscimos:**
  - **Inscrição em mais de 2 eventos:** 10% de acréscimo sobre o valor total
  - **Evento VIP (acesso a áreas exclusivas):** 15% de acréscimo sobre o valor total

#### Funcionalidades do Sistema:

Desenvolver um programa em C que gerencie até 100 registros de inscrições utilizando vetores simples e funções.

#### Menu de Opções:

O programa deve apresentar um menu com as seguintes opções:

0. **Sair**
1. **Inserir mais registros**
2. **Apresentar resultados**
3. **Ordenar os registros pelo valor total da inscrição (decrescente)**
4. **Imprimir registros de inscrições**

#### Dados das Inscrições:

Para cada inscrição, o programa deve armazenar as seguintes informações usando vetores simples:

- Número da inscrição
- Tipo de evento (1 para Conferência, 2 para Workshop, 3 para Seminário)
- Número de eventos
- Evento VIP (1 para sim, 0 para não)
- Quantidade de pessoas

#### Resultados e Insights:

O sistema deve calcular e exibir os seguintes resultados:

1. A média do valor de todas as inscrições.
2. A média das inscrições para eventos VIP.
3. O número da inscrição com maior valor.
4. O percentual das inscrições para conferências em relação ao número total de inscrições.
5. O total geral de eventos inscritos.

#### Requisitos Adicionais:

- Utilizar vetores simples para armazenar os dados das inscrições (número da inscrição, tipo de evento, número de eventos, evento VIP e quantidade de pessoas).
- Implementar a entrada de novos registros até atingir o limite de 100 inscrições.
- Implementar cálculos e apresentação dos resultados conforme descrito.
- Ordenar os registros pelo valor total da inscrição em ordem decrescente.

#### Exemplo de entrada:

|Número da Inscrição|Tipo de Evento|Número de Eventos|Evento VIP|Quantidade de Pessoas|Valor Base|Acréscimos                                                |Valor Total|
|-------------------|---------------|------------------|-----------|----------------------|----------|----------------------------------------------------------|-----------|
|1                  |Conferência     |3                 |Sim        |8                    |R$ 1.500,00|R$ 150,00 (10%) + R$ 225,00 (15% de 1.500) + R$ 75,00 (5% de 8 x 1.500)|R$ 1.950,00|
|2                  |Workshop       |1                 |Não        |3                    |R$ 300,00 |R$ 0,00 (sem acréscimo)                                   |R$ 300,00  |
|3                  |Seminário      |4                 |Sim        |12                   |R$ 800,00 |R$ 80,00 (10%) + R$ 80,00 (10% de 800) + R$ 80,00 (10% de 12 x 800)|R$ 1.040,00|

#### Resultado esperado:

1. A média do valor de todas as inscrições: R$ 783,33
2. A média das inscrições para eventos VIP: R$ 1.395,00
3. O número da inscrição com maior valor: 1
4. O percentual das inscrições para conferências em relação ao número total de inscrições: 33,33%
5. O total geral de eventos inscritos: 10
*/