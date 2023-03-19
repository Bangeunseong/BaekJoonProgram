//NumberProblem 13241

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

long long Calculate(long long n, long long k){
    long long base, div;
    if(n > k) {base = n; div = k;}
    else{base = k; div = n;}
    while(div != 0){
        long long tmp = base % div;
        base = div; div = tmp;
    }
    return n * k / base;
}   
int main(){
    long long n, k; scanf("%lld%lld",&n,&k);
    printf("%lld",Calculate(n,k));
}