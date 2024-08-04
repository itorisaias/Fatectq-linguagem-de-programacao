/*
### Sistema de Gerenciamento de Aluguéis de Ferramentas

A FerramentaMax oferece uma variedade de ferramentas para aluguel. O sistema deve gerenciar os aluguéis realizados, calcular os custos e fornecer insights sobre os aluguéis.

#### Regras de Negócio:

- **Categorias de Ferramentas:**
  - **Ferramentas Manuais:** R$ 15,00 por dia
  - **Ferramentas Elétricas:** R$ 40,00 por dia
  - **Equipamentos Pesados:** R$ 100,00 por dia

- **Descontos:**
  - **Aluguel acima de 7 dias:** 10% de desconto sobre o valor total
  - **Clientes Frequentes:** 15% de desconto sobre o valor total

#### Funcionalidades do Sistema:

Desenvolver um programa em C que gerencie até 100 registros de aluguéis utilizando vetores simples e funções.

#### Menu de Opções:

O programa deve apresentar um menu com as seguintes opções:

0. **Sair**
1. **Inserir mais registros**
2. **Apresentar resultados**
3. **Ordenar os registros pelo valor total do aluguel (decrescente)**
4. **Imprimir registros de aluguéis**

#### Dados dos Aluguéis:

Para cada aluguel, o programa deve armazenar as seguintes informações usando vetores simples:

- Número do aluguel
- Categoria da ferramenta (1 para Ferramentas Manuais, 2 para Ferramentas Elétricas, 3 para Equipamentos Pesados)
- Número de dias
- Cliente Frequente (1 para sim, 0 para não)

#### Resultados e Insights:

O sistema deve calcular e exibir os seguintes resultados:

1. A média do valor de todos os aluguéis.
2. A média dos aluguéis para clientes frequentes.
3. O número do aluguel com maior valor.
4. O percentual dos aluguéis com duração acima de 7 dias em relação ao número total de aluguéis.
5. O total geral de dias alugados.

#### Requisitos Adicionais:

- Utilizar vetores simples para armazenar os dados dos aluguéis (número do aluguel, categoria da ferramenta, número de dias e cliente frequente).
- Implementar a entrada de novos registros até atingir o limite de 100 aluguéis.
- Implementar cálculos e apresentação dos resultados conforme descrito.
- Ordenar os registros pelo valor total do aluguel em ordem decrescente.

#### Exemplo de entrada:

|Número do Aluguel|Categoria da Ferramenta|Dias|Cliente Frequente|Valor Base|Descontos        |Valor Total|
|-----------------|------------------------|----|------------------|----------|-----------------|-----------|
|1                |Ferramentas Manuais     |5   |Sim               |R$ 75,00  |R$ 11,25         |R$ 63,75   |
|2                |Ferramentas Elétricas   |10  |Não               |R$ 400,00 |R$ 40,00         |R$ 360,00  |
|3                |Equipamentos Pesados    |3   |Sim               |R$ 300,00 |R$ 0,00          |R$ 300,00  |

#### Resultado esperado:

1. A média do valor de todos os aluguéis: R$ 241,25
2. A média dos aluguéis para clientes frequentes: R$ 181,25
3. O número do aluguel com maior valor: 2
4. O percentual dos aluguéis com duração acima de 7 dias em relação ao número total de aluguéis: 33,33%
5. O total geral de dias alugados: 18
*/