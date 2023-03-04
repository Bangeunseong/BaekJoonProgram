#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int main(){
    int n, m; scanf("%d%d",&n,&m);
    int *x = (int *)malloc(sizeof(int)*(n + 1)); x[0] = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d",x + i);
        x[i] += x[i - 1];
    }

    for(int i = 0; i < m; i++){
        int f, l; scanf("%d%d", &f, &l);
        printf("%d\n", x[l] - x[f - 1]);
    }
    free(x);
}