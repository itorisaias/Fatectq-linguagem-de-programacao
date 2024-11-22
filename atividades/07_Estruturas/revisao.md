Esse exercício ajudará a fixar os conceitos de **structs**, **arrays**, manipulação de **strings**, e uso de **arquivos**.

### Enunciado: Sistema Bancário em C

Você deverá implementar um **sistema bancário simples** utilizando **structs** e **arrays** em linguagem C. Esse sistema permitirá a criação e manipulação de contas bancárias através de um menu interativo.

#### Funcionalidades a implementar:

1. **Criar Conta:**
   - O usuário poderá criar uma nova conta fornecendo o número da conta, o nome do cliente e o saldo inicial.
   - Cada conta terá um histórico de transações (depósitos e saques).

2. **Consultar Saldo:**
   - O sistema deverá exibir o saldo atual de uma conta específica, considerando todas as transações realizadas.

3. **Depositar:**
   - Permitir que o usuário insira um valor em uma conta específica.

3. **Sacar:**
   - Permitir que o usuário retire um valor de uma conta, desde que tenha saldo suficiente.

4. **Excluir Conta:**
   - Excluir uma conta, caso ela esteja com saldo zerado.

5. **Listar Contas:**
   - Exibir todas as contas ativas, com o saldo atualizado de cada uma.

6. **Exportar Contas:**
   - Salvar os dados de todas as contas ativas em um arquivo no formato CSV.

7. **Importar Contas:**
   - Ler um arquivo no formato CSV e importar as contas para o sistema.

#### Regras e Orientações:
1. Cada conta é representada por uma **struct** chamada `Conta`, contendo:
   - Número da conta (inteiro).
   - Nome do cliente (string).
   - Status da conta (ativa ou inativa).
   - Histórico de transações (array de structs `Transacao`).
2. Cada transação (depósito ou saque) é representada por uma **struct** chamada `Transacao`, contendo:
   - Tipo da transação (`Depósito` ou `Saque`).
   - Valor da transação.
3. O sistema deverá armazenar no máximo **50 contas bancárias** e cada conta poderá ter até **100 transações**.
3. Utilize um menu interativo para navegar entre as funcionalidades.

#### Exemplo de Menu:

```
=== Banco Simples ===
1. Sair
2. Criar Conta
3. Consultar Saldo
4. Depositar
5. Sacar
6. Excluir Conta
6. Listar Contas
7. Exportar
8. Importar
Escolha uma opção:
```

#### Desafios Extras:
- Valide entradas do usuário, como valores negativos em saques e depósitos.
- Garanta que cada número de conta seja único.
- Implemente a função para exportar e importar contas usando arquivos no formato CSV.
