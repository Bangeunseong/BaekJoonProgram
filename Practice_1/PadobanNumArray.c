#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int main(){
    int m; scanf("%d",&m);
    long *x = (long *)malloc(sizeof(long)*100);
    for(int i = 0; i < 3; i++) x[i] = 1;

    for(int j = 0; j < m; j++){
        int n; scanf("%d", &n);
        for(int i = 3; i < n; i++){
            x[i] = x[i - 2] + x[i - 3];
        }
        printf("%ld\n",x[n - 1]);
    }
}