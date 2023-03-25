//Mathematics 11401

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define SIZE 4000000
long NUM = 1000000007;

long n, k;
long factorial[SIZE + 1];
void getFactorial(){
    factorial[1] = 1;
    for(int i = 2; i <= SIZE; i++){
        factorial[i] = (i * factorial[i - 1] % NUM) % NUM;
    }
}
long Power(long base, long expo){
    long num = 1;
    while(expo > 0){
        if(expo % 2 == 1){
            num *= base; num %= NUM;
        }
        expo /= 2;
        base *= base; base %= NUM;
    }
    return num;
}
int main(){
    getFactorial();
    scanf("%d%d",&n,&k);
    if(k == n || k == 0) printf("1");
    else{
        long n_fac = factorial[n], k_fac = factorial[k], n_k_fac = factorial[n - k];
        long result = ((n_fac % NUM) * (Power((k_fac * n_k_fac) % NUM, NUM - 2) % NUM)) % NUM;
        printf("%ld", result);
    }
}