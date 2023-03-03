#include <stdio.h>
#pragma warning(disable:4996)
int max(int x, int y){x > y ? x : y;}
int main(){
    int n; scanf("%d",&n);
    int max = 1;
    int m[1000] = {0,}, c[1000] = {0,};

    for(int i = 0; i < n; i++){
        scanf("%d",m + i);
        c[i] = 1;

        for(int j = 0; j < i; j++){
            if(m[i] > m[j] && c[i] < c[j] + 1) c[i] = c[j] + 1;
        }
        if(c[i] > max) max = c[i];
    }
    printf("%d", max);
}