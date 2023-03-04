#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int main(){
    int n; scanf("%d",&n);
    int *x = (int *)malloc(sizeof(int)*n);
    for(int i = 0; i < n; i++){scanf("%d",x+i);}

    int max = x[0], tmp = x[0];
    for(int i = 1; i < n; i++){
        tmp += x[i];
        if(tmp < x[i]) tmp = x[i];
        if(tmp > max) max = tmp;
        if(x[i] > max) max = tmp = x[i];
    }
    printf("%d",max);
}