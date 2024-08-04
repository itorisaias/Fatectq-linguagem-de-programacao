/*
### Sistema de Gerenciamento de Reservas de Hotel

O Hotel Luxor deseja automatizar o gerenciamento de suas reservas. O sistema deve registrar as reservas feitas pelos clientes, calcular os custos e oferecer insights sobre as estadias.

#### Regras de Negócio:

- **Tipos de Quarto:**
  - **Simples:** R$ 100,00 por noite
  - **Duplo:** R$ 150,00 por noite
  - **Suíte:** R$ 250,00 por noite

- **Custos Adicionais:**
  - **Café da manhã:** R$ 20,00 por pessoa por dia
  - **Estacionamento:** R$ 30,00 por dia

#### Funcionalidades do Sistema:

Desenvolver um programa em C que gerencie até 100 reservas utilizando vetores simples e funções.

#### Menu de Opções:

O programa deve apresentar um menu com as seguintes opções:

0. **Sair**
1. **Inserir mais registros**
2. **Apresentar resultados**
3. **Ordenar os registros pelo valor total da reserva (decrescente)**
4. **Imprimir registros de reservas**

#### Dados das Reservas:

Para cada reserva, o programa deve armazenar as seguintes informações usando vetores simples:

- Número da reserva
- Tipo de quarto (1 para Simples, 2 para Duplo, 3 para Suíte)
- Número de noites
- Número de pessoas para café da manhã
- Estacionamento (1 para sim, 0 para não)

#### Resultados e Insights:

O sistema deve calcular e exibir os seguintes resultados:

1. A média do valor de todas as reservas.
2. A média das reservas com café da manhã incluído.
3. O número da reserva com maior valor.
4. O percentual das reservas com estacionamento em relação ao número total de reservas.
5. O total geral de noites reservadas.

#### Requisitos Adicionais:

- Utilizar vetores simples para armazenar os dados das reservas (número da reserva, tipo de quarto, número de noites, número de pessoas para café da manhã e estacionamento).
- Implementar a entrada de novos registros até atingir o limite de 100 reservas.
- Implementar cálculos e apresentação dos resultados conforme descrito.
- Ordenar os registros pelo valor total da reserva em ordem decrescente.

#### Exemplo de entrada:

|Número da Reserva|Tipo de Quarto|Noites|Café da Manhã (pessoas)|Estacionamento|Valor Base|Custos Adicionais|Valor Total|
|-----------------|--------------|------|----------------------|--------------|----------|-----------------|-----------|
|1                |Simples       |2     |1                     |Sim           |R$ 200,00 |R$ 100,00        |R$ 300,00  |
|2                |Suíte         |3     |2                     |Não           |R$ 750,00 |R$ 120,00        |R$ 870,00  |
|3                |Duplo         |1     |0                     |Sim           |R$ 150,00 |R$ 30,00         |R$ 180,00  |

#### Resultado esperado:

1. A média do valor de todas as reservas: R$ 450,00
2. A média das reservas com café da manhã incluído: R$ 585,00
3. O número da reserva com maior valor: 2
4. O percentual das reservas com estacionamento em relação ao número total de reservas: 66,67%
5. O total geral de noites reservadas: 6
*/