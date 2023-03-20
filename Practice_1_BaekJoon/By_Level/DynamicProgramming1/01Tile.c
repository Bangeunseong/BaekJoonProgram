#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int main(){
    int n; scanf("%d",&n);

    int *m = (int *)malloc(sizeof(int)*(n + 1));
    m[0] = 0; m[1] = 1; m[2] = 2;
    for(int i = 3; i <= n; i++){
        m[i] = (m[i - 1] + m[i - 2]) % 15746;
    }
    printf("%d",m[n] % 15746);
}