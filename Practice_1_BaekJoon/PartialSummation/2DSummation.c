#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
int main() {
	int n, m; scanf("%d%d", &n, &m);
	int x[1025][1025] = { 0, };
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &x[i][j]);
			x[i][j] += x[i][j - 1] + x[i - 1][j] - x[i - 1][j - 1];
		}
	}
	for (int i = 0; i < m; i++) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
		printf("%d\n", x[y2][x2] - x[y2][x1 - 1] - x[y1 - 1][x2] + x[y1 - 1][x1 - 1]);
	}
}