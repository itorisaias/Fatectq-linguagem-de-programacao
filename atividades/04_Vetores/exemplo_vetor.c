#include <stdio.h>
// guardar até 100 registgro
// 0 - sai
// 1 - cadastra - quantidade pessoa - plano (A = 50 - B = 100)
// 2 - lista - ordenado maior valor de conta (qtd p * plano)
int main() {
    int opc;
    int qtd_pessoas[100];
    char planos[100];
    int qtd = 0;
    do {
        
        printf("0 - Sai \n1 - Cadastra \n2 - Lista\nDigite a opcao: ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 0:
            printf("Saindo\n");
            break;
        case 1:
            printf("Cadastra\n");
            int quantidade_pessoa;
            char plano;
            printf("Digite a quantidade de pessoa: ");
            scanf("%d", &quantidade_pessoa);
            getchar();
            printf("Plano (A ou B): ");
            scanf("%c", &plano);

            qtd_pessoas[qtd] = quantidade_pessoa;
            planos[qtd] = plano;

            qtd++;
            break;
        case 2:
            printf("Lista\n");
            for (int i = 0; i < qtd; i++)
            {
                int taxa = 0;
                if (planos[i] == 'A') {
                    taxa = 50;
                } else {
                    taxa = 100;
                }
                printf("Indice - %d - Quantidade: %d  - Plano %c - valor total %d\n", i, qtd_pessoas[i], planos[i], qtd_pessoas[i] * taxa);
            }            
            printf("\n");
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }
    } while (opc != 0);
}