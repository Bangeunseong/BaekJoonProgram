#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int min(int x, int y){return x < y ? x : y;}
int main() {
	int n, m, k; scanf("%d%d%d", &n, &m, &k); getchar();
	int **B = (int **)malloc(sizeof(int *)*(n + 1));
	int **W = (int **)malloc(sizeof(int *)*(n + 1));
	for (int i = 0; i <= n; i++) {
		B[i] = (int *)malloc(sizeof(int)*(m + 1));
		W[i] = (int *)malloc(sizeof(int)*(m + 1));
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i != 0 && j != 0) {
				char ch; scanf(" %c", &ch);
				if ((i + j) % 2 == 0) {
					if (ch == 'B') {
						B[i][j] = B[i - 1][j] + B[i][j - 1] - B[i - 1][j - 1];
						W[i][j] = W[i - 1][j] + W[i][j - 1] - W[i - 1][j - 1] + 1;
					}
					else {
						B[i][j] = B[i - 1][j] + B[i][j - 1] - B[i - 1][j - 1] + 1;
						W[i][j] = W[i - 1][j] + W[i][j - 1] - W[i - 1][j - 1];
					}
				}
				else {
					if (ch == 'B') {
						B[i][j] = B[i - 1][j] + B[i][j - 1] - B[i - 1][j - 1] + 1;
						W[i][j] = W[i - 1][j] + W[i][j - 1] - W[i - 1][j - 1];
					}
					else {
						B[i][j] = B[i - 1][j] + B[i][j - 1] - B[i - 1][j - 1];
						W[i][j] = W[i - 1][j] + W[i][j - 1] - W[i - 1][j - 1] + 1;
					}
				}
			}
			else { B[i][j] = W[i][j] = 0; }
		}
	}

    int minimum = n*m, tmpB = 0, tmpW = 0, small;
    for(int i = 0; i <= n - k; i++){
        for(int j = 0; j <= m - k; j++){
            tmpB = B[i + k][j + k] - B[i][j + k] - B[i + k][j] + B[i][j];
            tmpW = W[i + k][j + k] - W[i][j + k] - W[i + k][j] + W[i][j];
            small = min(tmpB, tmpW);
            if(minimum > small) minimum = small;
        }
    }
    printf("%d",minimum);
}