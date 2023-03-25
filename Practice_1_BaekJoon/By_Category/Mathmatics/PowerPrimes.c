//Mathematics 1016 Failed

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)
#define SIZE 1000000000000

long min, max; int Primes[SIZE];
void Prime(){
    for(long i = 2; i * i <= max; i++){
        long s = min % (i*i) == 0 ? min/(i*i) : min/(i*i) + 1;
        for(long j = s; i*i*j <= max; j++){
            Primes[(j*i*i) - min] = -1;
        } 
    }
}
int main(){
    scanf("%ld%ld",&min,&max);
    Prime();

    long sum = 0;
    for(long i = min; i <= max; i++){
        if(!Primes[i]) sum++;
    }
    printf("%ld",sum);
}