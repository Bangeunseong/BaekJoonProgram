//Mathematics 2749

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define NUM 1000000
long long F[2];
int main(){
    F[0] = 0; F[1] = 1;
    long long n; scanf("%lld", &n);
    n %= 1500000;
    for(long long i = 2; i <= n; i++){    //**피사노의 주기** 참고!!! 주기 M = 10^k일때 15 * 10^(k - 1)
        F[i % 2] = (F[(i - 1) % 2] + F[(i - 2) % 2]) % NUM;
    }
    printf("%lld", F[n % 2] % NUM);
}