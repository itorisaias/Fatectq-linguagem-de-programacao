#include<stdio.h>
void imprimir(int n) {
  if (n == 0) {
    printf("%d ", n);
  } else {
    imprimir(n - 1);
    printf("%d ", n);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  imprimir(n);
}
