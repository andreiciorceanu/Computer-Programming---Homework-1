#include <stdio.h>

void puzzle();

int verif1(int l, int nrcol, int a[][100], int v[][100]);

int verif2(int c, int nrlin, int a[][100], int v[][100]);

int main() {
  int T = 0, i;
  scanf("%d", &T);
  for (i = 0; i < T; i++) {
    puzzle();
  }
  return 0;
}

void puzzle() {
  int i, j, n, m, a[100][100], v[200][100];
  int nr;
  scanf("%d", &n);
  scanf("%d", &m);
    for (i = 0; i < (n + m); i++) {
      scanf("%d", &nr);
      v[i][0] = nr;
      for (j = 1; j <= nr; j++) {
        scanf("%d", &v[i][j]);
      }
    }
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    for (i = 0; i < n; i++) {
      if (verif1(i, m, a, v) == -1) {
        printf("Eroare\n");
        return;
      }
    }
    for (i = 0; i < m; i++) {
      if (verif2(i, n, a, v) == -1) {
        printf("Eroare\n");
        return;
      }
    }
    printf("Corect\n");
  }

int verif2(int c, int nrlin, int a[][100], int v[][100]) {
  int i = 0, x, y, nr = 0;
  while (i < nrlin) {
    if (a[i][c] == 0) {
      i++;
      continue;
    }
    x = i;
    i++;
    while (i < nrlin && a[i][c] == 1) {
      i++;
    }
    y = i - 1;
    nr++;
    if (nr > v[nrlin + c][0]) {
      return -1;
    }
    if ((y - x + 1) != v[c + nrlin][nr]) {
      return -1;
    }
  }
  return 1;
}

int verif1(int c, int nrlin, int grid[][100], int res[][100]) {
    int i = 0, nrg = 0, start_index, end_index;
    while (i < nrlin) {
        if (grid[i][c] == 0) {
            i++;
            continue;
        }
        start_index = i;
        i++;
        while (i < nrlin && grid[i][c] == 1) {
          i++;
        }
        end_index = (i-1);
        nrg++;
        if (nrg > res[nrlin+c][0]) {
            return -1;
        }
        if ((end_index - start_index + 1) != res[c+nrlin][nrg]) {
            return -1;
        }
    }
    return 1;
}



