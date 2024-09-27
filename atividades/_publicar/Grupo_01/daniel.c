#include <stdio.h>

#define MAX_RESERVAS 100

//PRECOS DOS TRANSPORTESS
#define ONIBUS 500
#define VAN 300
#define CARRO 150

//DECLARA FUNCOES
int inserirRegistros(int num_reserva[],int tipo_transporte[], int dias[], int num_pessoas[], int feriado[], int total);
void resultados(int num_reserva[],int tipo_transporte[], int dias[], int num_pessoas[], int feriado[], int total);
void ordenar(int num_reserva[], int tipo_transporte[], int dias[], int num_pessoas[], int feriado[], int total);
void imprimir(int num_reserva[], int tipo_transporte[], int dias[], int num_pessoas[], int feriado[], int total);
float calculo(int tipo_transporte, int dias, int num_pessoas, int feriado);

int main(){
    int num_reserva[MAX_RESERVAS], tipo_transporte[MAX_RESERVAS], dias[MAX_RESERVAS], num_pessoas[MAX_RESERVAS], feriado[MAX_RESERVAS];
    int total = 0, opc;

    do{
        printf("1 - INSERIR\n");
        printf("2 - RESULTADOS\n");
        printf("3 - ORDENAR\n");
        printf("4 - LISTAR\n");
        printf("0 - SAIR\n");

        printf("\nESCOLHA UMA OPCAO: ");
        scanf("%d", &opc);

        switch(opc){
            case 1:
                total = inserirRegistros(num_reserva,tipo_transporte,dias,num_pessoas,feriado,total);
            break;

            case 2:
                resultados(num_reserva,tipo_transporte,dias,num_pessoas,feriado,total);
            break;

            case 3:
                ordenar(num_reserva,tipo_transporte,dias,num_pessoas,feriado,total);
            break;

            case 4:
                imprimir(num_reserva,tipo_transporte,dias,num_pessoas,feriado,total);
            break;

            case 0:
                printf("SAINDO.");
            break;

            default:
                printf("OPCAO INVALIDA.");
        }

    }while(opc != 0);

    return 0;
}

int inserirRegistros(int num_reserva[],int tipo_transporte[], int dias[], int num_pessoas[], int feriado[], int total){
    int qnt_reservas;
    system("cls");
    printf("INFORME QUANTAS RESERVAS DESEJA RESGISTRAR: ");
    scanf("%d", &qnt_reservas);

    for(int i = 0; i < qnt_reservas; i++){
        if(total >= MAX_RESERVAS){
            printf("MAXIMO DE RESERVAS ATINGIDO\n");
            break;
        }
        printf("INFORME O NUMERO DA RESERVA: ");
        scanf("%d", &num_reserva[total]);
        printf("INFORME O TIPO DE VEICULO(1-ONIBUS/2-VAN/3-CARRO): ");
        scanf("%d", &tipo_transporte[total]);
        printf("INFORME O NUMERO DE DIAS: ");
        scanf("%d", &dias[total]);
        printf("INFORME O NUMERO DE PESSOAS: ");
        scanf("%d", &num_pessoas[total]);
        printf("INFORME SE A VIAGEM E EM UM FERIADO(1-SIM/2-NAO): ");
        scanf("%d", &feriado[total]);

        total++;
    }
    return total;
}

float calculo(int tipo_transporte, int dias, int num_pessoas, int feriado){
    float base, desconto = 0.0, acrecimo = 0.0, valor_total;

    //CALCULO DO VALOR BASE
    if(tipo_transporte == 1){
        base = dias * ONIBUS;
    }else if(tipo_transporte == 2){
        base = dias * VAN;
    }else{
        base = dias * CARRO;
    }

    //DESCONTO ACIMA DE 7 DIAS
    if(dias > 7){
        desconto += 0.10 * base;
    }

    //DESCONTO PARA GRUPOS MAIORES QUE 20 PESSOAS
    if(num_pessoas > 20){
        desconto += 0.05 * base;
    }

    //AUMENTO DE VALOR CASO SEJA FERIADO
    if(feriado == 1){
        acrecimo = 0.15 * base;
    }

    //SOMA O VALOR TOTAL COM O ACRECIMO E OS DESCONTOS
    valor_total = base - desconto + acrecimo;
    return valor_total;
}

void resultados(int num_reserva[],int tipo_transporte[], int dias[], int num_pessoas[], int feriado[], int total){
    if(total == 0){
        printf("NAO EXISTEM REGISTROS.\n");
        return;
    }

    float soma_valores = 0, soma_grupos = 0;
    int maior_reserva = 0, total_dias = 0, num_grupos = 0, num_onibus = 0;
    float maior_valor = 0;

    for(int i = 0; i < total; i ++){
        float valor_total = calculo(tipo_transporte[i], dias[i], num_pessoas[i], feriado[i]);

        soma_valores += valor_total;
        total_dias += dias[i];

        if(tipo_transporte[i] == 1){
            num_onibus++;
        }

        if(num_pessoas[i] > 20){
            soma_grupos += valor_total;
            num_grupos++;
        }

        if(valor_total > maior_valor){
            maior_valor = valor_total;
            maior_reserva = num_reserva[i];
        }
    }

    float media_val = soma_valores / total;
    float media_grupos = num_grupos ? soma_grupos / num_grupos : 0;
    float percentual = (num_onibus / (float)total)*100;

    system("cls");
    printf("1 - MEDIA DO VALOR TOTAL DAS RESERVAS: R$ %.2f\n", media_val);
    printf("2 - MEDIA DAS RESERVAS PARA GRUPOS MAIORES QUE 20 PESSOAS: R$ %.2f\n", media_grupos);
    printf("3 - NUMERO DA RESERVA COM MAIOR VALOR: %d\n", maior_reserva);
    printf("4 - PERCENTUAL DE RESERVAS PARA ONIBUS: %.2f%%\n", percentual);
    printf("5 - TOTAL DE DIAS RESERVADOS: %d dias\n\n", total_dias);

}

void ordenar(int num_reserva[], int tipo_transporte[], int dias[], int num_pessoas[], int feriado[], int total){
    for(int i = 0; i < total; i++){
        for(int j = i + 1; j < total; j++){
            //TROCA OS REGISTROS
            if(num_reserva[i] < num_reserva[j]){
                //temp_num ARMAZENA TEMPORARIAMENTE O VALOR DA RESERVA PARA SER TROCADA
                int temp_num = num_reserva[i];
                num_reserva[i] = num_reserva[j];
                num_reserva[j] = temp_num;

                int temp_trans = tipo_transporte[i];
                tipo_transporte[i] = tipo_transporte [j];
                tipo_transporte[j] = temp_trans;

                int temp_dias = dias[i];
                dias[i] = dias[j];
                dias[j] = temp_dias;

                int temp_pessoas = num_pessoas[i];
                num_pessoas[i] = num_pessoas[j];
                num_pessoas[j] = temp_pessoas;

                int temp_feriado = feriado[i];
                feriado[i] = feriado[j];
                feriado[j] = temp_feriado;
            }
        }
    }

    printf("RESERVAS ORDENADAS.\n");

}

void imprimir(int num_reserva[], int tipo_transporte[], int dias[], int num_pessoas[], int feriado[], int total){
    if(total == 0){
        printf("NAO EXISTEM REGISTROS.\n");
        return;
    }
    system("cls");
    printf("\n REGISTROS \n");
    for(int i = 0; i < total; i++){
        printf("NUMERO DA RESERVA: %d\n", num_reserva[i]);
        printf("TIPO DE TRANSPORTE: %s\n", tipo_transporte[i] == 1 ? "ONIBUS" : (tipo_transporte[i] == 2 ? "VAN" : "CARRO"));
        printf("NUMERO DE DIAS: %d\n", dias[i]);
        printf("NUMERO DE PESSOAS: %d\n", num_pessoas[i]);
        printf("FERIADO: %s\n", feriado[i] == 1 ? "SIM" : "NAO");
        printf("VALOR TOTAL: R$%.2f\n\n", calculo(tipo_transporte[i],dias[i],num_pessoas[i],feriado[i]));
    }
}
