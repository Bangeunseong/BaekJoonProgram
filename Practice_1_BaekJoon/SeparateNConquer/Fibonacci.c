//Separate N Conquer 11444 Failed

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define NUM 1000000007
#define SIZE 1000000000000000000

long long Count[SIZE] = {0,};
long long F[SIZE];
long long Calculate(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 1;
    if(Count[n] > 0) return F[n];
    if(n % 2 == 0){
        long long m = n/2;
        long long tmp1 = Calculate(m);
        long long tmp2 = Calculate(m - 1);
        F[n] = (tmp2*2LL + tmp1) * tmp1;
    }
    else{
        long long m = (n + 1) / 2;
        long long tmp1 = Calculate(m);
        long long tmp2 = Calculate(m - 1);
        F[n] = tmp1*tmp1 + tmp2*tmp2;
    }
    F[n] %= NUM; Count[n] = 1;
    return F[n];
}

int main(){
    long long n; scanf("%lld", &n);
    F[0] = 0; F[1] = 1; F[2] = 1;
    printf("%lld", Calculate(n));
}