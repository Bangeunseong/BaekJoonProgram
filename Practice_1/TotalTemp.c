#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int main(){
    int n, m; scanf("%d%d", &n, &m);
    int *x = (int *)malloc(sizeof(int)*n);
    int c[100000] = {0,};

    int max = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", x + i);
        if(i < m){c[0] += x[i]; max = c[0];}
        else{
            c[i - m + 1] = c[i - m] + (x[i] - x[i - m]);
            if(c[i - m + 1] > max) max = c[i - m + 1];
        }
    }
    
    printf("%d",max);
}