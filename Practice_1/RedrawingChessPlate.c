#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int main(){
    int n, m, k; scanf("%d%d%d", &n, &m, &k);
    int **x = (int **)malloc(sizeof(int)*n);
    for(int i = 0; i < n; i++) x[i] = (int *)malloc(sizeof(int)*m);
    
}