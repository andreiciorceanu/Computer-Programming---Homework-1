#include<stdio.h>

void puzzle();

int veriflinie(int l, int nrcol, int grid[][100], int res[][100]);

int verifcol(int c, int nrlin, int grid[][100], int res[][100]);

int main() {
    int T = 0, i;
    scanf("%d", &T);
    for (i = 0; i < T; i++) {
        puzzle();
    }
    return 0;
}

void puzzle() {
    int i, j, n, m, grid[100][100], res[200][100];
    int nrg;
    scanf("%d%d", &n, &m);
    for (i = 0; i < (n+m); i++) {
        scanf("%d", &nrg);
        res[i][0] = nrg;
        for (j = 1; j <= nrg; j++) {
            scanf("%d", &res[i][j]);
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    for (i = 0; i < n; i++) {
        if (veriflinie(i, m, grid, res) == -1) {
            printf("Eroare\n");
            return;
        }
    }
    for (i = 0; i < m; i++) {
        if (verifcol(i, n, grid, res) == -1) {
            printf("Eroare\n");
            return;
        }
    }
    printf("Corect\n");
}

int veriflinie(int l, int nrcol, int grid[][100], int res[][100]) {
    int j = 0, nrg = 0, start_index, end_index;
    while (j < nrcol) {
        if (grid[l][j] == 0) {
            j++;
            continue;
        }

        start_index = j;
        j++;
        while (j < nrcol && grid[l][j] == 1) {
           j++;
        }
        end_index = (j-1);
        nrg++;
        if (nrg > res[l][0]) {
            return -1;
        }
        if ((end_index - start_index +1) != res[l][nrg]) {
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
