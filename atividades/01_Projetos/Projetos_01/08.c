/*
### Sistema de Gerenciamento de Inscrições para Buffet de Eventos

A empresa Buffet Gourmet organiza serviços de buffet para diversos tipos de eventos, como casamentos, festas corporativas e eventos familiares. O sistema deve gerenciar as inscrições para os eventos, calcular os custos e fornecer insights sobre as inscrições.

#### Regras de Negócio:

- **Tipos de Buffet:**
  - **Buffet Básico:** R$ 50,00 por pessoa
  - **Buffet Premium:** R$ 80,00 por pessoa
  - **Buffet Deluxe:** R$ 120,00 por pessoa

- **Número de Pessoas:**
  - **Até 20 pessoas:** Sem desconto
  - **De 21 a 50 pessoas:** 10% de desconto sobre o valor total
  - **Mais de 50 pessoas:** 15% de desconto sobre o valor total

- **Acréscimos:**
  - **Serviço de Bebidas Exclusivas:** 10% de acréscimo sobre o valor total

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
- Tipo de buffet (1 para Básico, 2 para Premium, 3 para Deluxe)
- Valor por pessoa
- Quantidade de pessoas
- Serviço de bebidas exclusivas (1 para sim, 0 para não)

#### Resultados e Insights:

O sistema deve calcular e exibir os seguintes resultados:

1. A média do valor de todas as inscrições.
2. A média das inscrições que incluem serviço de bebidas exclusivas.
3. O número da inscrição com maior valor.
4. O percentual das inscrições para o buffet Deluxe em relação ao número total de inscrições.
5. O total geral de pessoas inscritas.

#### Requisitos Adicionais:

- Utilizar vetores simples para armazenar os dados das inscrições (número da inscrição, tipo de buffet, valor por pessoa, quantidade de pessoas e serviço de bebidas exclusivas).
- Implementar a entrada de novos registros até atingir o limite de 100 inscrições.
- Implementar cálculos e apresentação dos resultados conforme descrito.
- Ordenar os registros pelo valor total da inscrição em ordem decrescente.

#### Exemplo de entrada:

|Número da Inscrição|Tipo de Buffet|Valor por Pessoa|Quantidade de Pessoas|Serviço de Bebidas Exclusivas|Valor Base|Acréscimos                                                |Valor Total|
|-------------------|---------------|----------------|----------------------|------------------------------|----------|----------------------------------------------------------|-----------|
|1                  |Premium        |R$ 80,00        |30                   |Sim                           |R$ 2.400,00|R$ 240,00 (10%) + R$ 240,00 (10% de 2.400)               |R$ 2.880,00|
|2                  |Básico         |R$ 50,00        |15                   |Não                           |R$ 750,00  |R$ 0,00                                                    |R$ 750,00  |
|3                  |Deluxe         |R$ 120,00       |60                   |Sim                           |R$ 7.200,00|R$ 1.080,00 (15%) + R$ 1.080,00 (10% de 7.200)           |R$ 8.280,00|

#### Resultado esperado:

1. A média do valor de todas as inscrições: R$ 6.938,00
2. A média das inscrições que incluem serviço de bebidas exclusivas: R$ 5.580,00
3. O número da inscrição com maior valor: 3
4. O percentual das inscrições para o buffet Deluxe em relação ao número total de inscrições: 66,67%
5. O total geral de pessoas inscritas: 105
*/