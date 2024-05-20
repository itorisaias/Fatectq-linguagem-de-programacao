#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_AGENDA 100
#define MAX_OBS 100

// Definindo estruturas
typedef struct
{
  char rua[50];
  int numero;
  char complemento[30];
  char bairro[30];
  char cep[10];
  char cidade[30];
  char estado[30];
  char pais[30];
} Endereco;

typedef struct
{
  int ddd;
  char numero[15];
} Telefone;

typedef struct
{
  int dia;
  int mes;
  int ano;
} Data;

typedef struct
{
  char nome[50];
  char email[50];
  Endereco endereco;
  Telefone telefone;
  Data aniversario;
  char observacoes[MAX_OBS];
} Pessoa;

// Variável global
Pessoa agenda[MAX_AGENDA];
int totalPessoas = 0;

// Funções de apoio
void lerString(char *mensagem, char *variavel, int tamanho)
{
  printf("%s", mensagem);
  fgets(variavel, tamanho, stdin);
  variavel[strcspn(variavel, "\n")] = '\0';
}

void lerInt(char *mensagem, int *variavel)
{
  printf("%s", mensagem);
  scanf("%d", variavel);
  getchar(); // Limpar o buffer do teclado
}

void inserirPessoa()
{
  if (totalPessoas >= MAX_AGENDA)
  {
    printf("Agenda cheia!\n");
    return;
  }

  Pessoa p;
  printf("Insira os dados da pessoa:\n");

  lerString("Nome: ", p.nome, 50);
  lerString("Email: ", p.email, 50);

  printf("Endereço:\n");
  lerString("  Rua: ", p.endereco.rua, 50);
  lerInt("  Número: ", &p.endereco.numero);
  lerString("  Complemento: ", p.endereco.complemento, 30);
  lerString("  Bairro: ", p.endereco.bairro, 30);
  lerString("  CEP: ", p.endereco.cep, 10);
  lerString("  Cidade: ", p.endereco.cidade, 30);
  lerString("  Estado: ", p.endereco.estado, 30);
  lerString("  País: ", p.endereco.pais, 30);

  printf("Telefone:\n");
  lerInt("  DDD: ", &p.telefone.ddd);
  lerString("  Número: ", p.telefone.numero, 15);

  printf("Data de aniversário:\n");
  lerInt("  Dia: ", &p.aniversario.dia);
  lerInt("  Mês: ", &p.aniversario.mes);
  lerInt("  Ano: ", &p.aniversario.ano);

  lerString("Observações: ", p.observacoes, MAX_OBS);

  // Inserir na agenda em ordem alfabética
  int i;
  for (i = totalPessoas - 1; (i >= 0) && (strcmp(agenda[i].nome, p.nome) > 0); i--)
  {
    agenda[i + 1] = agenda[i];
  }
  agenda[i + 1] = p;
  totalPessoas++;
}

void imprimirPessoa(Pessoa p)
{
  printf("Nome: %s\n", p.nome);
  printf("Email: %s\n", p.email);
  printf("Endereço: %s, %d, %s, %s, %s, %s, %s, %s\n",
         p.endereco.rua, p.endereco.numero, p.endereco.complemento,
         p.endereco.bairro, p.endereco.cep, p.endereco.cidade,
         p.endereco.estado, p.endereco.pais);
  printf("Telefone: (%d) %s\n", p.telefone.ddd, p.telefone.numero);
  printf("Aniversário: %02d/%02d/%04d\n", p.aniversario.dia, p.aniversario.mes, p.aniversario.ano);
  printf("Observações: %s\n", p.observacoes);
  printf("\n");
}

void buscarPorNome()
{
  char nome[50];
  lerString("Digite o primeiro nome a ser buscado: ", nome, 50);
  int encontrado = 0;

  for (int i = 0; i < totalPessoas; i++)
  {
    if (strstr(agenda[i].nome, nome))
    {
      imprimirPessoa(agenda[i]);
      encontrado = 1;
    }
  }
  if (!encontrado)
  {
    printf("Nenhuma pessoa encontrada com o nome %s.\n", nome);
  }
}

void buscarPorMesAniversario()
{
  int mes;
  lerInt("Digite o mês de aniversário a ser buscado: ", &mes);
  int encontrado = 0;

  for (int i = 0; i < totalPessoas; i++)
  {
    if (agenda[i].aniversario.mes == mes)
    {
      imprimirPessoa(agenda[i]);
      encontrado = 1;
    }
  }
  if (!encontrado)
  {
    printf("Nenhuma pessoa encontrada com aniversário no mês %d.\n", mes);
  }
}

void buscarPorDiaMesAniversario()
{
  int dia, mes;
  lerInt("Digite o dia de aniversário a ser buscado: ", &dia);
  lerInt("Digite o mês de aniversário a ser buscado: ", &mes);
  int encontrado = 0;

  for (int i = 0; i < totalPessoas; i++)
  {
    if (agenda[i].aniversario.dia == dia && agenda[i].aniversario.mes == mes)
    {
      imprimirPessoa(agenda[i]);
      encontrado = 1;
    }
  }
  if (!encontrado)
  {
    printf("Nenhuma pessoa encontrada com aniversário em %02d/%02d.\n", dia, mes);
  }
}

void removerPessoa()
{
  char nome[50];
  lerString("Digite o primeiro nome da pessoa a ser removida: ", nome, 50);
  int encontrado = 0;

  for (int i = 0; i < totalPessoas; i++)
  {
    if (strstr(agenda[i].nome, nome))
    {
      encontrado = 1;
      for (int j = i; j < totalPessoas - 1; j++)
      {
        agenda[j] = agenda[j + 1];
      }
      totalPessoas--;
      printf("Pessoa removida com sucesso.\n");
      break;
    }
  }
  if (!encontrado)
  {
    printf("Nenhuma pessoa encontrada com o nome %s.\n", nome);
  }
}

void imprimirAgenda(int opcao)
{
  for (int i = 0; i < totalPessoas; i++)
  {
    if (opcao == 1)
    {
      printf("Nome: %s, Telefone: (%d) %s, Email: %s\n",
             agenda[i].nome, agenda[i].telefone.ddd, agenda[i].telefone.numero, agenda[i].email);
    }
    else
    {
      imprimirPessoa(agenda[i]);
    }
  }
}

void menu()
{
  int opcao;
  do
  {
    system("clear");
    printf("\nMenu:\n");
    printf("1. Inserir pessoa\n");
    printf("2. Buscar por primeiro nome\n");
    printf("3. Buscar por mês de aniversário\n");
    printf("4. Buscar por dia e mês de aniversário\n");
    printf("5. Remover pessoa\n");
    printf("6. Imprimir agenda (nome, telefone e email)\n");
    printf("7. Imprimir agenda (todos os dados)\n");
    printf("8. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    getchar(); // Limpar o buffer do teclado

    switch (opcao)
    {
    case 1:
      inserirPessoa();
      break;
    case 2:
      buscarPorNome();
      break;
    case 3:
      buscarPorMesAniversario();
      break;
    case 4:
      buscarPorDiaMesAniversario();
      break;
    case 5:
      removerPessoa();
      break;
    case 6:
      imprimirAgenda(1);
      break;
    case 7:
      imprimirAgenda(2);
      break;
    case 8:
      printf("Saindo...\n");
      break;
    default:
      printf("Opção inválida!\n");
    }
  } while (opcao != 8);
}

int main()
{
  menu();
  return 0;
}
