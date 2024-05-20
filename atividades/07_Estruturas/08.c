#include <stdio.h>
#include <stdlib.h>

// Estrutura para armazenar uma data
typedef struct
{
  int dia;
  int mes;
  int ano;
} Data;

// Estrutura para armazenar os dados de uma reserva
typedef struct
{
  char nome[50];
  int numeroQuarto;
  Data checkin;
  Data checkout;
} Reserva;

// Função para calcular a duração da estadia em dias
int calcularDuracao(Data checkin, Data checkout)
{
  // Calcula o número de dias considerando que todos os meses têm 31 dias
  int diasCheckin = checkin.dia + (checkin.mes - 1) * 31 + (checkin.ano - 1) * 372;
  int diasCheckout = checkout.dia + (checkout.mes - 1) * 31 + (checkout.ano - 1) * 372;
  return diasCheckout - diasCheckin;
}

// Função para ler os dados de uma reserva
void lerReserva(Reserva *reserva)
{
  printf("Nome do hóspede: ");
  scanf(" %[^\n]%*c", reserva->nome); // Lê uma linha inteira
  printf("Número do quarto: ");
  scanf("%d", &reserva->numeroQuarto);
  printf("Data de check-in (dd mm aaaa): ");
  scanf("%d %d %d", &reserva->checkin.dia, &reserva->checkin.mes, &reserva->checkin.ano);
  printf("Data de check-out (dd mm aaaa): ");
  scanf("%d %d %d", &reserva->checkout.dia, &reserva->checkout.mes, &reserva->checkout.ano);
  printf("\n");
}

// Função para imprimir os dados de uma reserva e a duração da estadia
void imprimirReserva(Reserva reserva, int duracao)
{
  printf("Nome: %s, Quarto: %d, Check-in: %02d/%02d/%d, Check-out: %02d/%02d/%d, Duração: %d dias\n",
         reserva.nome, reserva.numeroQuarto,
         reserva.checkin.dia, reserva.checkin.mes, reserva.checkin.ano,
         reserva.checkout.dia, reserva.checkout.mes, reserva.checkout.ano,
         duracao);
}

int main()
{
  int n;
  printf("Quantas reservas deseja inserir? ");
  scanf("%d", &n);

  // Alocando um array de N reservas
  Reserva *reservas = (Reserva *)malloc(n * sizeof(Reserva));

  // Lendo os dados das reservas
  for (int i = 0; i < n; ++i)
  {
    printf("Reserva %d:\n", i + 1);
    lerReserva(&reservas[i]);
  }

  // Calculando e imprimindo a duração da estadia para cada reserva
  for (int i = 0; i < n; ++i)
  {
    int duracao = calcularDuracao(reservas[i].checkin, reservas[i].checkout);
    printf("Reserva %d: ", i + 1);
    imprimirReserva(reservas[i], duracao);
    printf("\n");
  }

  // Liberando a memória alocada
  free(reservas);

  return 0;
}
