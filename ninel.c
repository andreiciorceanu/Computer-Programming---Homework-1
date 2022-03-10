// 314CA_CiorceanuAndreiRazvan_Tema1
#include <math.h>
#include <stdio.h>
int special(int a, int b, int c) {
  if (a < b && b > c) {
    return 1;
  } else {
    return 0;
  }
}
int main() {
  int N, i, xmax_impar = 0, xmin_par = 10000000, a, b, c, nr = 0, nrpar = 0;
  long long int S = 0;
  double m_a = 0;
  scanf("%d\n", &N);
  if (N < 3) {
    xmin_par = 0;
    printf("%lld\n", S);
    printf("%lf\n", m_a);
    printf("%d\n", xmax_impar);
    printf("%d\n", xmin_par);
  }
  scanf("%d\n", &a);
  scanf("%d\n", &b);
  for (i = 1; i <= N - 2; i++) {
    scanf("%d\n", &c);
    if (special(a, b, c) == 1) {
      S = S + b;
      nr++;
      if (i % 2 == 1) {
        if (b > xmax_impar) {
          xmax_impar = b;
        }
      }
      if (i % 2 == 0) {
        nrpar++;
        if (b < xmin_par) {
          xmin_par = b;
        }
      }
    }
    a = b;
    b = c;
  }
  if (N == 0) {
    m_a = 0;
  }
  if (nrpar == 0) {
    xmin_par = -1;
  }
  m_a = (double)S / nr;
  printf("%lld\n", S);
  printf("%.7lf\n", m_a);
  printf("%d\n", xmax_impar);
  printf("%d\n", xmin_par);
  return 0;
}




