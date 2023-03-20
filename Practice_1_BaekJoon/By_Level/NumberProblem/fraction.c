//NumberProblem 1735

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

long Calculate(long n, long k){
    long base, div;
    if(n > k) {base = n; div = k;}
    else{base = k; div = n;}
    while(div != 0){
        long tmp = base % div;
        base = div; div = tmp;
    }
    return base;
}   
int main(){
    long arr[2][2];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++) scanf("%ld",&arr[i][j]);
    }
    long n = arr[0][0] * arr[1][1] + arr[1][0] * arr[0][1];
    long k = arr[0][1]*arr[1][1];
    long div = Calculate(n,k);
    printf("%ld %ld",n/div,k/div);
}