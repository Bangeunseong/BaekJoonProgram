#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int max(int x, int y){return x > y ? x : y;}
int main(){
    int n; scanf("%d",&n);
    int *m = (int *)malloc(sizeof(int)*(n + 1));
    int *c = (int *)malloc(sizeof(int)*(n + 1));

    for(int i = 1; i <= n; i++) scanf("%d",&m[i]);

    int max = 0;
    c[0] = 0;
    c[1] = m[1];
    c[2] = m[1] + m[2];
    for(int i = 3;i <= n; i++){
        int tmp = c[i - 2] + m[i];
        if(max < tmp) max = tmp;
        tmp = c[i - 3] + m[i] + m[i - 1];
        if(max < tmp) max = tmp;
        tmp = c[i - 1];
        if(max < tmp) max = tmp;

        c[i] = max;
    }
    printf("%d",c[n]);
}