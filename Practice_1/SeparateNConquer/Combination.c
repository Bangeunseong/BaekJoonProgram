//Separate N Conquer 11401 Failed!!

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define NUM 1000000007
long long factorial(int n){
    long long result = 1;
    for(int i = 2; i <= n; i++) {result *= i; result %= NUM;}
    return result;
}
unsigned long long power(long a, long b){
    if(b == 0) return 1;
    else if(b == 1) return a;
    
    unsigned long long tmp = power(a, b/2);
    if(b % 2 == 0) return tmp * tmp % NUM;
    return tmp * tmp * a % NUM;
}

int main(){
    int n, k; scanf("%d%d",&n,&k);
    long long nFac = factorial(n);
    long long kFac = factorial(n-k) * factorial(k) % NUM;
    printf("%lld", nFac * power(kFac, NUM - 2) % NUM);
}