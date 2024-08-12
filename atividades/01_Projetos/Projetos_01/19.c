/*
### Sistema de Gerenciamento de Construção Civil

Este sistema será desenvolvido para uma empresa fictícia chamada **Construtora Exemplar**, que se especializa em projetos de construção civil. O sistema ajudará a gerenciar contratos de construção, calcular custos baseados em critérios específicos e fornecer relatórios sobre os projetos.

#### Regras de Negócio:

- **Tipo de Projeto:**
  - **Residencial:** R$ 1.000,00 por metro quadrado
  - **Comercial:** R$ 1.500,00 por metro quadrado
  - **Industrial:** R$ 2.000,00 por metro quadrado

- **Desconto por Tamanho do Projeto:**
  - **Até 100 metros quadrados:** Sem desconto
  - **De 101 a 500 metros quadrados:** 5% de desconto sobre o valor total
  - **Acima de 500 metros quadrados:** 10% de desconto sobre o valor total

- **Adicional por Complexidade:**
  - **Baixa Complexidade:** R$ 500,00 por projeto
  - **Média Complexidade:** R$ 1.000,00 por projeto
  - **Alta Complexidade:** R$ 2.000,00 por projeto

- **Desconto Adicional para Clientes Corporativos:**
  - **Clientes Corporativos:** 5% de desconto adicional sobre o valor total

#### Funcionalidades do Sistema:

Desenvolver um programa em C que gerencie até 100 contratos de construção civil utilizando vetores simples e funções.

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
- Tipo de projeto (1 para Residencial, 2 para Comercial, 3 para Industrial)
- Área do projeto (em metros quadrados)
- Complexidade (1 para Baixa, 2 para Média, 3 para Alta)
- Cliente corporativo (1 para sim, 0 para não)

#### Resultados e Insights:

O sistema deve calcular e exibir os seguintes resultados:

1. A média do valor total dos contratos.
2. A média dos contratos para clientes corporativos.
3. O número do contrato com maior valor total.
4. O percentual dos contratos com mais de 500 metros quadrados em relação ao número total de contratos.
5. O total de projetos de cada tipo (Residencial, Comercial, Industrial).

#### Requisitos Adicionais:

- Utilizar vetores simples para armazenar os dados dos contratos (número do contrato, tipo de projeto, área do projeto, complexidade, cliente corporativo).
- Implementar a entrada de novos contratos até atingir o limite de 100 contratos.
- Implementar cálculos e apresentação dos resultados conforme descrito.
- Ordenar os contratos pelo valor total em ordem decrescente.

#### Exemplo de entrada e processamento:

|Número do Contrato|Tipo de Projeto|Área do Projeto (m²)|Complexidade|Cliente Corporativo|Valor Base|Desconto por Tamanho|Desconto Adicional|Adicionais|Valor Total|
|------------------|----------------|--------------------|-------------|-------------------|-----------|---------------------|-------------------|----------|-----------|
|1                 |Residencial     |120                 |Média        |Sim                |R$ 120.000,00|R$ 6.000,00           |R$ 6.000,00        |R$ 1.000,00|R$ 109.000,00|
|2                 |Comercial       |300                 |Alta         |Não                |R$ 450.000,00|R$ 22.500,00          |R$ 0,00            |R$ 2.000,00|R$ 425.500,00|
|3                 |Industrial      |600                 |Baixa        |Sim                |R$ 1.200.000,00|R$ 120.000,00        |R$ 60.000,00        |R$ 500,00 |R$ 1.119.500,00|

#### Resultado esperado:

1. A média do valor total dos contratos: R$ 551.666,67
2. A média dos contratos para clientes corporativos: R$ 688.250,00
3. O número do contrato com maior valor total: 3
4. O percentual dos contratos com mais de 500 metros quadrados em relação ao número total de contratos: 33,33%
5. Total de projetos de cada tipo:
   - Projetos Residenciais: 1
   - Projetos Comerciais: 1
   - Projetos Industriais: 1
*/