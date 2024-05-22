#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO 10
#define ARQUIVO "contatos.bin"

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

Pessoa contatos[TAMANHO];
int quantidade = 0;

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
  quantidade++;

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
  FILE *arq = fopen(ARQUIVO, "w");
  if (arq == NULL)
  {
    printf("ERROR: arquivo não pode ser aberto.\n");
    return;
  }

  fprintf(arq, "%d\n", quantidade);
  fwrite(contatos, sizeof(Pessoa), quantidade, arq);
  fclose(arq);

  printf("Arquivo salvo!\n");
}

void lerArquivo()
{
  FILE *arq = fopen(ARQUIVO, "r");
  if (arq == NULL)
  {
    printf("ERROR: arquivo não pode ser aberto.\n");
    return;
  }

  fscanf(arq, "%d\n", &quantidade);
  fread(contatos, sizeof(Pessoa), quantidade, arq);
  fclose(arq);

  printf("Arquivo carregado!\n");
}
