// 314CA_CiorceanuAndreiRazvan_Tema1
#include <math.h>
#include <stdio.h>

void sortarecresc(int v[], int nr) {
  int i, j, aux;
  for (i = 0; i < nr - 1; i++) {
    for (j = i + 1; j < nr; j++) {
      if (v[i] > v[j]) {
        aux = v[i];
        v[i] = v[j];
        v[j] = aux;
      }
    }
  }
}

int diferenta(int v[], int N, int nr) {
  int i = 0, j = 0, m = 0, M = 0;
  while (N != 0) {
    v[i] = N % 10;
    N /= 10;
    i++;
  }
  sortarecresc(v, nr);
  for (j = 0; j < i; j++) {
    if (v[j] != 0) {
      m = m * 10 + v[j];
    }
  }
  for (j = i - 1; j >= 0; j--) {
    M = M * 10 + v[j];
  }
  return (M - m);
}

int main() {
  int a, i = 0, v[10], nr = 0, p[100], aux1, ok = 0, j, N;
  scanf("%d", &N);
  aux1 = N;
  while (aux1 != 0) {
    aux1 /= 10;
    nr++;
  }
  p[0] = diferenta(v, N, nr);
  while (ok == 0) {
    i++;
    p[i] = diferenta(v, p[i - 1], nr);
    for (j = 0; j <= i - 1; j++) {
      if (p[j] == p[i]) {
        ok = 1;
        a = j;
      }
    }
  }
  printf("%d\n", a);
  for (j = a; j <= i - 1; j++) {
    printf("%d ", p[j]);
  }
  printf("\n");
  return 0;
}
