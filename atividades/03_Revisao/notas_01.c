// Leia 3 notas e apresente
// a media (n1 + n2 + n3) / total_n
// a menor nota,
// a maior nota

#include <stdio.h>

int main() {
    float n1, n2, n3, media;
    float menor, maior;

    printf("Digite a primeira nota: ");
    scanf("%f", &n1);
    printf("Digite a segunda nota: ");
    scanf("%f", &n2);
    printf("Digite a terceira nota: ");
    scanf("%f", &n3);

    media = (n1 + n2 + n3) / 3;

    if (n1 < n2 && n1 < n3) {
        menor = n1;
    } else if (n2 < n3) {
        menor = n2;
    } else {
        menor = n3;
    }
    
    return 0;
}