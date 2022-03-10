// 314CA_CiorceanuAndreiRazvan_Tema1
#include <stdio.h>
void sortare(int v[], int n) {
  int i, j, aux;
  for (i = 0; i < n - 1; i++) {
    for (j = i + 1; j < n; j++) {
      if (v[i] < v[j]) {
        aux = v[i];
        v[i] = v[j];
        v[j] = aux;
      }
    }
  }
}
int main() {
  int N, i, x[100], c[100], p_min, m, p = 0, aux[100], nr = 0;
  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    scanf("%d", &x[i]);
  }
  for (i = 0; i < N; i++) {
    scanf("%d", &c[i]);
  }
  scanf("%d", &p_min);
  for (i = 0; i < N; i++) {
    p = p + x[i] * c[i];
  }
  if (p > p_min) {
    printf("-1");
    return 0;
  }
  for (i = 0; i < N; i++) {
    if (x[i] != 10) {
      aux[nr] = c[i] * (10 - x[i]);
      nr++;
    }
  }
  if (nr == 0 && p < p_min) {
    printf("-1");
    return 0;
  }
  sortare(aux, nr);
  m = 0;
  while (p < p_min && m < nr) {
    p = p + aux[m];
    m++;
  }
  if (p < p_min) {
    printf("-1");
  } else {
    printf("%d", m);
  }
  return 0;
}
