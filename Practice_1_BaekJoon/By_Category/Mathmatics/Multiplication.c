//Mathematics 2588

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int main(){
    int n, m; scanf("%d%d",&n,&m);
    int exp = 1, sum = 0;
    for(int i = 0; i < 3; i++){
        int tmp = n * (m % 10);
        printf("%d\n",tmp);
        sum += tmp * exp;
        m /= 10, exp *= 10;
    }
    printf("%d",sum);
}