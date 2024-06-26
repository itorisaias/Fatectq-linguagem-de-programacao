#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo estrutura e funções
typedef struct
{
  char nome[100];
  int idade;
  char sexo;
} Pessoa;

int cadastrarPessoa();
void imprimirPessoa();
void salvarArquivo();
void lerArquivo();

// Criando variável global
#define TAMANHO 10
Pessoa contatos[TAMANHO];
int quantidade = 0;

// Função main
int main()
{
  int opcao;

  do
  {
    printf("0 - Sair\n");
    printf("1 - Cadastrar pessoa\n");
    printf("2 - Listar pessoas\n");
    printf("3 - Salvar no arquivo\n");
    printf("4 - Ler do arquivo\n");
    printf("Digite a opção: ");
    scanf("%d", &opcao);
    getchar(); // Limpar o buffer do teclado

    switch (opcao)
    {
    case 0:
      printf("Bye!\n");
      break;
    case 1:
      if (!cadastrarPessoa())
      {
        printf("Não foi possível cadastrar a pessoa.\n");
      }
      break;
    case 2:
      imprimirPessoa();
      break;
    case 3:
      salvarArquivo();
      break;
    case 4:
      lerArquivo();
      break;
    default:
      printf("Opção inválida!\n\n");
    }
  } while (opcao != 0);

  return 0;
}

// Implementação
int cadastrarPessoa()
{
  if (quantidade >= TAMANHO)
  {
    printf("ERROR: vetor de contatos cheio.\n");
    return 0;
  }

  Pessoa novaPessoa;

  printf("Nome: ");
  fgets(novaPessoa.nome, sizeof(novaPessoa.nome), stdin);
  novaPessoa.nome[strcspn(novaPessoa.nome, "\n")] = '\0'; // Remover nova linha

  printf("Idade: ");
  if (scanf("%d", &novaPessoa.idade) != 1)
  {
    printf("Entrada inválida para idade.\n");
    return 0;
  }

  printf("Sexo (m ou f): ");
  getchar(); // Limpar o buffer do teclado
  novaPessoa.sexo = getchar();
  getchar(); // Limpar o buffer do teclado

  contatos[quantidade] = novaPessoa;
  (quantidade)++;

  return 1;
}

void imprimirPessoa()
{
  for (int i = 0; i < quantidade; i++)
  {
    printf("Nome: %s\n", contatos[i].nome);
    printf("Idade: %d\n", contatos[i].idade);
    printf("Sexo: %c\n", contatos[i].sexo);
    printf("--------------------------\n");
  }
}

void salvarArquivo()
{
  FILE *arq = fopen("contatos.txt", "w");
  if (arq == NULL)
  {
    printf("ERROR: arquivo não pode ser aberto.\n");
    return;
  }

  fprintf(arq, "%d\n", quantidade);

  for (int i = 0; i < quantidade; i++)
  {
    fprintf(arq, "%s\n", contatos[i].nome);
    fprintf(arq, "%d\n", contatos[i].idade);
    fprintf(arq, "%c\n", contatos[i].sexo);
  }

  fclose(arq);
}

void lerArquivo()
{
  FILE *arq = fopen("contatos.txt", "r");
  if (arq == NULL)
  {
    printf("ERROR: arquivo não pode ser aberto.\n");
    return;
  }

  fscanf(arq, "%d\n", &quantidade);

  for (int i = 0; i < quantidade; i++)
  {
    Pessoa pessoa;

    fscanf(arq, "%[^\n]", pessoa.nome);
    fscanf(arq, "%d\n", &pessoa.idade);
    fscanf(arq, "%c\n", &pessoa.sexo);
    contatos[i] = pessoa;
  }

  fclose(arq);
}
