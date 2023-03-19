//NumberProblem 3134

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)

int isPrime(long long val){
    if(val == 0 || val == 1) return 0;
    for(long long i = 2; i < (long long)(sqrt(val)) + 1; i++){
        if(val % i == 0) return 0;
    }
    return 1;
}

int main(){
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++){
        long long val; scanf("%lld", &val);
        for(long long j = val;;j++){
            if(isPrime(j)){printf("%lld\n",j); break;}
        }
    }
}