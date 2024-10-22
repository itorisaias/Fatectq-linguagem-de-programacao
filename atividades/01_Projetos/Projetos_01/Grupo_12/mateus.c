#include <stdio.h>
#define cem 100

void OrdenarDecrescente(float *des, int cmm, float *tot, int *contrat, int *taman, int *durac, int *frequen);

int main()
{
    int cemm = 0;
    int contratos[cem], tamanho[cem], duracao[cem], frequente[cem], prectamanho, maiorValor = 0, TotalGeral = 0;
    float total[cem], totalP, totalF = 0, desconto, soma = 0, QntAnual = 0, valorBase, maior;
    int opcao, aux, auxDur, descS[cem], QtdF = 0;

    printf("bem vindo ao menu SafeStore! \n");

    while (1)
    {
        printf("\n----------------- MENU ----------------\n");
        printf("0 = SAIR\n");
        printf("1 = NOVO CONTRATO\n");
        printf("2 = RESULTADOS ATUAIS\n");
        printf("3 = ORDENAR CLIENTES ($$$ -> $$ -> $)\n");
        printf("4 = IMPRIMIR REGISTROS DE CONTRATOS\n");
        scanf("%d", &opcao);
        while (opcao != 0 && opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4){
            printf("Opcao Invalida, tente novamente. (obs.: Opcoes 0, 1, 2, 3 ou 4.)\n");
            scanf("%d", &opcao);
        }

        if (opcao == 0){
            break;
        }

        switch (opcao)
        {
        case 1:
            if (cemm < cem)
            {

                printf("\n");
                printf("|  NOVO CONTRATO  |\n");
                printf("\n");

                printf("Etapa 1:\n");
                printf("\nQual o VOLUME desejado?: (Nivel 1 = Pequeno(ate 1m³), Nivel 2 = Medio(de 1 a 3m³), Nivel 3 = Grande(+ que 3m³)) ou 0 para cancelar a operacao.\n");
                scanf("%d", &aux);

                if (aux != 0 && aux != 1 && aux != 2 && aux != 3){
                    printf("Tamanho Invalido, tente novamente. (obs.: Opcoes 1, 2 ou 3)\n)");
                    printf("Digite 0 para CANCELAR/SAIR da operacao.");
                    scanf("%d", &aux);
                }
                if (aux == 0){
                    break;
                }
                tamanho[cemm] = aux;

                contratos[cemm] = cemm + 1;

                printf("Etapa 2.1:\n");
                printf("Voce deseja fazer parte das promocoes de contratos trimestrais e anuais?. 1/SIM - 2/NAO:");
                scanf("%d", &aux);
                if (aux == 1)
                {
                    printf("Etapa 2.2:\n");
                    printf("Qual a promocao desejada, trimestral ou anual? 0/CANCELAR - 1/TRIMESTRAL - 2/ANUAL:");
                    scanf("%d", &aux);

                    if (aux == 1){
                        duracao[cemm] = 3;
                        descS[cemm] = 1;
                    } else if (aux == 2){
                        duracao[cemm] = 12;
                        descS[cemm] = 1;
                    } else {
                        printf("Etapa 2.2:\n");
                        printf("\nQual sera a extensao do contrato em meses?: \n");
                        scanf("%d", &aux);
                        duracao[cemm] = aux ;
                        descS[cemm] = 0;
                    }
                } else {

                    printf("Etapa 2.2:\n");
                    printf("\nQual sera a extensao do contrato em meses?: \n");
                    scanf("%d", &aux);
                    duracao[cemm] = aux;
                    descS[cemm] = 0;
                }

                printf("Etapa 3:\n");
                printf("\nQuantas vezes nos contratou no ultimo ano?\n (Digite 0 caso essa seja sua primeira experiencia Safe!) ");
                scanf("%d", &aux);
                auxDur = aux;

                printf("\n");
                printf("Contrato Realizado com Sucesso!");

                if (aux > 2){
                    frequente[cemm] = 1;
                } else {
                    frequente[cemm] = 0;
                }
                cemm++;
            } else {
                printf("Desculpe, armazens lotados! (ツ)_/¯ \nTente novamente em breve.");
            }
            break;
        case 2:
            soma = 0;
            QtdF = 0;
            totalF = 0;
            QntAnual = 0;
            TotalGeral = 0;
            
            for (int i = 0; i < cemm; i++)
            {
                desconto = 0;
                if (tamanho[i] == 1){ 
                    prectamanho = 50;

                } else if (tamanho[i] == 2){
                    prectamanho = 100;

                } else if (tamanho[i] == 3){
                    prectamanho = 200;
                }

                if (descS[i] == 1){
                    if (duracao[i] == 12){
                        desconto += 0.1;
                    } else if (duracao[i] == 3){
                        desconto += 0.05;
                    }
                }

                if (frequente[i] == 1){
                    desconto += 0.08;
                    QtdF++;
                }

                totalP = (prectamanho * duracao[i]) * (1 - desconto);

                if (frequente[i] == 1){
                    totalF += totalP;
                } 
                soma += totalP;
                total[i] = totalP;
                printf("%d ", descS[i]);
            }
            

            printf("\n");
            printf("|  RESULTADOS ATUAIS  |\n");
            printf("\n");    
            
            if (cemm != 0){
                printf("Media de precos por contratos fechados: %.2f\n", soma / cemm);
            }

            if (QtdF != 0){
            printf("Media de contratos por clientes frequentes: %.2f\n", totalF / QtdF);
            }

            maior = total[0];
            for (int i = 0; i < cemm; i++){
                if (total[i] > maior){
                    maior = total[i];
                    maiorValor = i;
                }
            }

            printf("Contrato de maior valor: ID = %d, no total de %.2f\nCom duracao de %d meses. \nContratou armazem de Nivel %d. \n", maiorValor + 1, total[maiorValor], duracao[maiorValor], tamanho[maiorValor]);
            if (frequente[maiorValor] == 1){
                printf("Esta contratando pela %dº vez.\n", auxDur + 1);
            
            } else {
                printf("Primeiro contrato Safe.\n");
            }

            for (int i = 0; i < cemm; i++){
                if (duracao[i] == 12){
                    QntAnual++;
                }
            }
            printf("Percentual de contratos anuais em relacao ao total: %.2f\n", (QntAnual / cemm) * 100);

            for (int i = 0; i < cemm; i++){
                TotalGeral += duracao[i];
            }
            printf("Total geral de meses contratados: %d\n", TotalGeral);

            for (int i = 0; i < cemm; i++){
                printf("%.2f  ", total[i]);
            }
            
            break;
        case 3:
            OrdenarDecrescente(descS, cemm, total, contratos, tamanho, duracao, frequente);
           
            printf("\n");
            printf("  |  CLIENTES ORDENADOS COM SUCESSO!  |\n");
            printf("|  **pressione 4 para ver o resultado**  |\n");
            
            break;
        case 4:

            printf("\n");
            printf("|  RESGISTROS DE CONTRATOS  |\n");
            printf("\n");
            printf("|  ID de Contrato  |  Nivel do Volume  |  Duracao (meses)  |  Cliente Frequente  |  Valor Base  |  Descontos  |  Valor Total  |\n");

            QtdF = 0;

            for (int i = 0; i < cemm; i++)
            {
                desconto = 0;
                if (tamanho[i] == 1){ 
                    prectamanho = 50;

                } else if (tamanho[i] == 2){
                    prectamanho = 100;

                } else if (tamanho[i] == 3){
                    prectamanho = 200;
                }

                if (descS[i] == 1){
                    if (duracao[i] == 12){
                        desconto += 0.1;
                    } else if (duracao[i] == 3){
                        desconto += 0.05;
                    }
                }

                if (frequente[i] == 1){
                    desconto += 0.08;
                }
                printf("%.2f \n",desconto);
                printf("%d ", descS[i]);
                valorBase = (prectamanho * duracao[i]);
                totalP = (prectamanho * duracao[i]) * (1 - desconto);

                if (frequente[i] == 1){
                    printf("|         %d                  %d                   %02d                Sim               %05.2f         %04.2f          %05.2f      \n", contratos[i], tamanho[i], duracao[i], valorBase, valorBase - totalP, totalP);
                } else {
                    printf("|         %d                  %d                   %02d                Nao               %05.2f         %04.2f          %05.2f      \n", contratos[i], tamanho[i], duracao[i], valorBase, valorBase - totalP, totalP);
                }
            }
            break;
        }
    }    
    return 0;
}

void OrdenarDecrescente(float *des, int cmm, float *tot, int *contrat, int *taman, int *durac, int *frequen){
    for (int j = 0; j < cmm-1; j++)
            {
                for (int i = 0; i < cmm - 1; i++)
                {
                    if (tot[i] < tot[i + 1])
                    {
                        float aux30 = tot[i + 1];
                        tot[i + 1] = tot[i];
                        tot[i] = aux30; /*ordenando a pasta pelo total(valor)*/
                        int aux20 = contrat[i + 1];
                        contrat[i + 1] = contrat[i];
                        contrat[i] = aux20; /*mudando posição dos contratos*/
                        aux20 = taman[i + 1];
                        taman[i + 1] = taman[i];
                        taman[i] = aux20; /*mudando posição dos tamanhos*/
                        aux20 = des[i + 1];
                        des[i + 1] = des[i];
                        des[i] = aux20; /*mudando posição do descS*/
                        aux20 = durac[i + 1];
                        durac[i + 1] = durac[i];
                        durac[i] = aux20; /*mudando posição da duração*/
                        aux20 = frequen[i + 1];
                        frequen[i + 1] = frequen[i];
                        frequen[i] = aux20; /*mudando posição dos "frequente"*/
                    }
                }
            }
}