#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nregistro[100], tcarro[100], ndias[100], seguro[100];

void inserirdados(int numerodovetor) {

    printf("Digite o numero do aluguel:\n");
    scanf_s("%d", &nregistro[numerodovetor]);

    printf("Digite o tipo do carro:\n");
    scanf_s("%d", &tcarro[numerodovetor]);

    printf("Digite o numero de dias que o carro sera alugado:\n");
    scanf_s("%d", &ndias[numerodovetor]);

    printf("O carro tera seguro? 0 para nao ou 1 para sim:\n");
    scanf_s("%d", &seguro[numerodovetor]);


}


void ordenaregistro() {

    int i, j;
    float total = 0, aluguel[100];

    for(i = 0;  i < 100; i++) {
        switch (tcarro[i])
        {
        case 1: {
            total = total + 80 * ndias[i];
            if (ndias[i] >=5) {
                total = total * 0.90;
            }
            if (seguro[i] == 1) {
                total = total + 8 * ndias[i];
            }
            break;
        }
        case 2: {
            total = total + 150 * ndias[i];
            if (ndias[i] >= 5) {
                total = total * 0.90;
            }
            if (seguro[i] == 1) {
                total = total + 15 * ndias[i];
            }
            break;
        }
        case 3: {
            total = total + 250 * ndias[i];
            if (ndias[i] >= 5) {
                total = total * 0.90;
            }
            if (seguro[i] == 1) {
                total = total + 25 * ndias[i];
            }
            break;
        }
        }
        aluguel[i] = total;
        total = 0;
    }
    total = 0;
    j = 0; i = 0;
    for (i = 0; i < 100; i++) {
        for (j = 0; j < 100; j++) {
            if (nregistro[j] != 0 && nregistro[j + 1] != 0) {
                if (aluguel[j] < aluguel[j + 1]) {

                    total = aluguel[j];
                    aluguel[j] = aluguel[j + 1];
                    aluguel[j + 1] = total;

                    total = nregistro[j];
                    nregistro[j] = nregistro[j + 1];
                    nregistro[j + 1] = total;

                    total = ndias[j];
                    ndias[j] = ndias[j + 1];
                    ndias[j + 1] = total;

                    total = seguro[j];
                    seguro[j] = seguro[j + 1];
                    seguro[j + 1] = total;

                    total = tcarro[j];
                    tcarro[j] = tcarro[j + 1];
                    tcarro[j + 1] = total;
                }
            }
        }
    }
}


void resultados() {

    int i, j = 0, k = 0, tdias = 0, maiorreg = 0;
    float mediat = 0, media = 0,mst = 0, mseguro = 0, mvalor = 0, paluguel = 0, contluxo = 0;

    for (i = 0; i < 100; i++) {

        switch (tcarro[i])
        {
            case 1: {
                media = media + 80 * ndias[i];
                if(ndias[i]  >= 5) {
                    media = media * 0.90;
                }
                if (seguro[i] == 1) {
                    media = media + 8 * ndias[i];
                    mseguro = mseguro + media;
                    k++;
                }
                j++;
                break;
            }
            case 2: {
                media = media + 150 * ndias[i];
                if (ndias[i] >= 5) {
                    media = media * 0.90;
                }
                if (seguro[i] == 1) {
                    media = media + 15 * ndias[i];
                    mseguro = mseguro + media;
                    k++;
                }
                j++ ;
                break;
            }
            case 3: {
                media = media + 250 * ndias[i];
                if (ndias[i] >= 5) {
                    media = media * 0.90;
                    
                }
                if (seguro[i] == 1) {
                    media = media + 25 * ndias[i];
                    mseguro = mseguro + media;
                    k++;
                }
                j++; contluxo ++;
                break;
            }
        }
    if(mvalor < media){
        mvalor = media;
        maiorreg = nregistro[i];       
    }

    mediat = mediat + media;
    media = 0;
    mst = mst + mseguro;
    mseguro = 0;
    tdias = tdias + ndias[i];
    }
    contluxo = contluxo / j * 100;

    printf("Media do valor total dos alugueis: %.2f\n", mediat / j);
    printf("Media dos alugueis com seguro do veiculo: %.2f\n", mst / k);
    printf("numero do aluguel com maior valor: %d\n", maiorreg);
    printf("porcentagem de carros de luxo alugado: %.2f %%\n", contluxo);
    printf("total geral de dias alugados %d \n\n", tdias);
}

void imprimirresuldato() {


    printf("Numero do aluguel | Tipo de carro | Dias | seguro do veiculo \n");

    for (int i = 0; i < 100; i++) {
        if (nregistro[i] > 0) {
            if (seguro[i] == 1) {
                printf("%-17d | %-13d | %-4d | sim \n", nregistro[i], tcarro[i], ndias[i]);
            }
            else {
                printf("%-17d | %-13d | %-4d | nao \n", nregistro[i], tcarro[i], ndias[i]);
            }
        }
    }
}

void tela(int escolha) {
    
    int i = 0;

    while (escolha != 0) {

        printf("Escolha uma opcao abaixo:\n");
        printf("0 - Sair\n");
        printf("1 - Inserir mais registros\n");
        printf("2 - Apresentar resultados\n");
        printf("3 - Ordenar os registros pelo valor total do aluguel (decrescente)\n");
        printf("4 - Imprimir registros de alugueis\n");
        scanf_s("%d", &escolha);

        switch (escolha) {
            
        case 1:{
            inserirdados(i);
            i++;
            break;
         }
        case 2: {
            resultados();
            break;
        }
        case 3: {
            ordenaregistro();
            break;
        }
        case 4: {
            imprimirresuldato();
            break;
        }
        }
    }
    
}




int main() {

    int escolha = 1;
    tela(escolha);
    
    return 0;
}