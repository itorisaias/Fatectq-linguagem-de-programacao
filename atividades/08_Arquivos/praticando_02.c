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

int cadastrarPessoa(Pessoa contatos[], int *quantidade);
void imprimirPessoa(const Pessoa contatos[], int quantidade);
void salvarArquivo(const Pessoa contatos[], int quantidade);
void lerArquivo(Pessoa contatos[], int *quantidade);

// Criando variável global
#define TAMANHO 10

// Função main
int main()
{
  Pessoa contatos[TAMANHO];
  int quantidade = 0;
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
      if (!cadastrarPessoa(contatos, &quantidade))
      {
        printf("Não foi possível cadastrar a pessoa.\n");
      }
      break;
    case 2:
      imprimirPessoa(contatos, quantidade);
      break;
    case 3:
      salvarArquivo(contatos, quantidade);
      break;
    case 4:
      lerArquivo(contatos, &quantidade);
      break;
    default:
      printf("Opção inválida!\n\n");
    }
  } while (opcao != 0);

  return 0;
}

// Implementação
int cadastrarPessoa(Pessoa contatos[], int *quantidade)
{
  if (*quantidade >= TAMANHO)
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

  contatos[*quantidade] = novaPessoa;
  (*quantidade)++;

  return 1;
}

void imprimirPessoa(const Pessoa contatos[], int quantidade)
{
  for (int i = 0; i < quantidade; i++)
  {
    printf("Nome: %s\n", contatos[i].nome);
    printf("Idade: %d\n", contatos[i].idade);
    printf("Sexo: %c\n", contatos[i].sexo);
    printf("--------------------------\n");
  }
}

void salvarArquivo(const Pessoa contatos[], int quantidade)
{
  FILE *arq = fopen("contatos.txt", "w");
  if (arq == NULL)
  {
    printf("ERROR: arquivo não pode ser aberto.\n");
    return;
  }

  for (int i = 0; i < quantidade; i++)
  {
    fprintf(arq, "%s\n%d\n%c\n", contatos[i].nome, contatos[i].idade,
            contatos[i].sexo);
  }

  fclose(arq);
}

void lerArquivo(Pessoa contatos[], int *quantidade)
{
  FILE *arq = fopen("contatos.txt", "r");
  if (arq == NULL)
  {
    printf("ERROR: arquivo não pode ser aberto.\n");
    return;
  }

  Pessoa pessoa;
  while (fscanf(arq, " %[^\n] %d %c", pessoa.nome, &pessoa.idade,
                &pessoa.sexo) == 3)
  {
    if (*quantidade >= TAMANHO)
    {
      printf("ERROR: vetor de contatos cheio.\n");
      break;
    }
    contatos[*quantidade] = pessoa;
    (*quantidade)++;
  }

  fclose(arq);
}
