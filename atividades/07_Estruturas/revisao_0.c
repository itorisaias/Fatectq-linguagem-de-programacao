/*
### **Enunciado: Sistema Simples de Banco**

Você deverá desenvolver um programa em C que simule um sistema simples de gerenciamento de contas bancárias utilizando **structs**, **arrays** e **menu interativo**.
O programa deverá permitir ao usuário realizar as seguintes operações:

1. **Criar Conta**  
   - Solicitar ao usuário o nome do cliente, o número da conta (único) e o saldo inicial.  
   - Armazenar os dados em uma estrutura apropriada.

2. **Consultar Saldo**  
   - Permitir ao usuário consultar o saldo de uma conta informando o número da conta.  

3. **Depositar**  
   - Permitir ao usuário adicionar um valor ao saldo de uma conta existente.  

4. **Sacar**  
   - Permitir ao usuário retirar um valor de uma conta existente.  
   - Validar se há saldo suficiente antes de realizar o saque.

5. **Excluir Conta**  
   - Permitir ao usuário excluir uma conta existente pelo número da conta.  

6. **Listar Contas**  
   - Exibir todas as contas cadastradas com seus respectivos dados: número da conta, nome do cliente e saldo.

7. **Sair do Programa**  
   - Encerrar a execução do programa.

---

### **Detalhes Técnicos**

- Utilize um **array de structs** para armazenar as contas bancárias.  
- Defina uma capacidade máxima (ex.: 50 contas) para o array.  
- Crie uma estrutura `Conta` (struct) com os campos necessários para armazenar os dados de uma conta.
- Implemente um **menu interativo** para navegar entre as opções.

---

### **Regras e Validações**

- O número da conta deve ser único. Caso o usuário tente cadastrar um número já existente, exiba uma mensagem de erro.  
- O saldo inicial na criação da conta deve ser maior ou igual a zero.  
- O valor de saque não pode ser maior que o saldo disponível.  
- Caso o número da conta não seja encontrado para operações (consulta, depósito, saque ou exclusão), exiba uma mensagem de erro.

---

### **Exemplo de Execução**

#### **Menu Principal**
```
=== Banco Simples ===
1. Criar Conta
2. Consultar Saldo
3. Depositar
4. Sacar
5. Excluir Conta
6. Listar Contas
7. Sair
Escolha uma opção: 
```

- **Criar Conta:**  
  ```
  Nome do Cliente: João Silva  
  Número da Conta: 1001  
  Saldo Inicial: 500.00  
  Conta criada com sucesso!
  ```

- **Depositar:**  
  ```
  Número da Conta: 1001  
  Valor do Depósito: 200.00  
  Depósito realizado! Novo saldo: 700.00
  ```

- **Sacar:**  
  ```
  Número da Conta: 1001  
  Valor do Saque: 300.00  
  Saque realizado! Novo saldo: 400.00
  ```

- **Excluir Conta:**  
  ```
  Número da Conta: 1001  
  Conta excluída com sucesso!
  ```

- **Listar Contas:**  
  ```
  === Contas Cadastradas ===
  Número: 1001 | Nome: João Silva | Saldo: 400.00
  Número: 1002 | Nome: Maria Oliveira | Saldo: 1500.00
  ```

---

### **Desafios Extras (Opcional)**

1. **Ordenar Contas por Nome:**  
   - Permitir que o sistema liste as contas em ordem alfabética pelo nome do cliente.

2. **Transferência entre Contas:**  
   - Adicionar a opção de transferir um valor entre duas contas existentes.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTAS 50

typedef struct {
    int numeroConta;
    float valor;
    char tipo[10];
} Transacao;
typedef struct {
    int numero;
    char nome[50];
    int ativa;
    int quantidade_transacoes;
    Transacao transacoes[100];
} Conta;

Conta contas[MAX_CONTAS];
int quantidade_conta = 0;

void menu();
void criarConta();
void listarContas();
void consultarSaldo();
void depositar();
void sacar();
void excluirConta();

// Função Principal
void main () {
    menu();
}

// Funções Auxiliares
void limparBuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void pausar() {
    printf("\n\nPressione ENTER para continuar...");
    limparBuffer();
    getchar();
}
void limparTela() {
    system("clear");
}

// Funções de Conta
float calcularSaldo(Conta conta) {
    float saldo = 0;
    for (int i = 0; i < conta.quantidade_transacoes; i++)
    {
        Transacao transacao = conta.transacoes[i];
        
        if (strcmp(transacao.tipo, "Depósito") == 0) {
            saldo += transacao.valor;
        } else {
            saldo -= transacao.valor;
        }
    }
    return saldo;
}

// Sistema de Banco
void menu() {
    int opcao;
    do {
        limparTela();
        printf("\n=== Banco Simples ===\n");
        printf("1. Criar Conta\n");
        printf("2. Consultar Saldo\n");
        printf("3. Depositar\n");
        printf("4. Sacar\n");
        printf("5. Excluir Conta\n");
        printf("6. Listar Contas\n");
        printf("7. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparTela();

        switch (opcao) {
            case 1:
                criarConta();
                break;
            case 2:
                consultarSaldo();
                break;
            case 3:
                depositar();
                break;
            case 4:
                sacar();
                break;
            case 5:
                excluirConta();
                break;
            case 6:
                listarContas();
                break;
            case 7:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 7);
}
void criarConta() {
    if (quantidade_conta >= MAX_CONTAS) {
        printf("Número máximo de contas atingido!\n");
        return;
    }

    printf("> Criar Conta\n");

    Conta novaConta;

    limparBuffer();
    printf("Informe o nome do cliente: ");
    fgets(novaConta.nome, sizeof(novaConta.nome), stdin);
    novaConta.nome[strcspn(novaConta.nome, "\n")] = '\0';

    printf("Informe o número da conta: ");
    scanf("%d", &novaConta.numero);

    printf("Informe o saldo inicial: ");
    scanf("%f", &novaConta.transacoes[0].valor);
    strcpy(novaConta.transacoes[0].tipo, "Depósito");

    novaConta.ativa = 1;
    novaConta.quantidade_transacoes = 1;

    contas[quantidade_conta] = novaConta;
    quantidade_conta++;

    printf("\nConta criada com sucesso!\n");
    pausar();
}
void listarContas() {
    printf("> Listar Contas\n\n");

    if (quantidade_conta == 0) {
        printf("Nenhuma conta cadastrada!\n");
        pausar();
        return;
    }

    printf("=== Contas Cadastradas ===\n");
    for (int i = 0; i < quantidade_conta; i++) {
        if (contas[i].ativa) {
            printf("Número: %d | Nome: %s | Saldo: %.2f\n", contas[i].numero, contas[i].nome, calcularSaldo(contas[i]));
        }
    }

    pausar();
}
void consultarSaldo() {
    printf("> Consultar Saldo\n");

    Conta conta;
    int numeroConta, encontrou = 0;
    float saldo = 0;
    printf("Informe o número da conta: ");
    scanf("%d", &numeroConta);

    for (int i = 0; i < quantidade_conta; i++) {
        if (contas[i].numero == numeroConta && contas[i].ativa) {
            encontrou = 1;
            conta = contas[i];
        }
    }

    if (!encontrou) {
        printf("Conta não encontrada!\n");
        pausar();
        return;
    }

    printf("Saldo da conta %d: %.2f\n", conta.numero, calcularSaldo(conta));
    pausar();
}
void depositar() {
    printf("> Depositar\n");

    int numeroConta;
    printf("Informe o número da conta: ");
    scanf("%d", &numeroConta);

    for (int i = 0; i < quantidade_conta; i++) {
        if (contas[i].numero == numeroConta && contas[i].ativa) {
            float valor;
            int quantidade_transacoes = contas[i].quantidade_transacoes;
            printf("Informe o valor do depósito: ");
            scanf("%f", &valor);

            Transacao deposito;
            deposito.valor = valor;
            strcpy(deposito.tipo, "Depósito");

            contas[i].transacoes[quantidade_transacoes] = deposito;
            contas[i].quantidade_transacoes++;

            float novoSaldo = calcularSaldo(contas[i]);
            
            printf("\nDepósito realizado com sucesso!\n");
            printf("Novo saldo: %.2f\n", novoSaldo);
            pausar();
            return;
        }
    }

    printf("Conta não encontrada!\n");
    pausar();
}
void sacar() {
    printf("> Sacar\n");

    int numeroConta;
    printf("Informe o número da conta: ");
    scanf("%d", &numeroConta);

    for (int i = 0; i < quantidade_conta; i++) {
        if (contas[i].numero == numeroConta && contas[i].ativa) {
            float valor;
            int quantidade_transacoes = contas[i].quantidade_transacoes;

            printf("Informe o valor do saque: ");
            scanf("%f", &valor);

            if (valor > calcularSaldo(contas[i])) {
                printf("Saldo insuficiente!\n");
                pausar();
                return;
            }

            Transacao saque;
            saque.valor = valor;
            strcpy(saque.tipo, "Saque");

            contas[i].transacoes[quantidade_transacoes] = saque;
            contas[i].quantidade_transacoes++;

            float novoSaldo = calcularSaldo(contas[i]);

            printf("\nSaque realizado com sucesso!\n");
            printf("Novo saldo: %.2f\n", novoSaldo);

            pausar();
            return;
        }
    }

    printf("Conta não encontrada!\n");
    pausar();
}
void excluirConta() {
    printf("> Excluir Conta\n");

    int numeroConta;
    printf("Informe o número da conta: ");
    scanf("%d", &numeroConta);

    for (int i = 0; i < quantidade_conta; i++) {
        if (contas[i].numero == numeroConta && contas[i].ativa) {
            if (calcularSaldo(contas[i]) > 0) {
                printf("\nA conta possui saldo! Realize o saque antes de excluí-la.\n");
                pausar();
                return;
            }

            contas[i].ativa = 0;
            printf("Conta excluída com sucesso!\n");
            pausar();
            return;
        }
    }

    printf("Conta não encontrada!\n");
    pausar();
}