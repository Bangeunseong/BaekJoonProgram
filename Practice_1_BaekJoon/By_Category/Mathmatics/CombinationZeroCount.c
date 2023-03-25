//Mathematics 2004

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

long countFive(long val){
    long sum = 0;
    for(long i = 5; i <= val; i *= 5){sum += val / i;}
    return sum;
}

long countTwo(long val){
    long sum = 0;
    for(long i = 2; i <= val; i *= 2){sum += val / i;}
    return sum;
}

int main(){
    long n, k; scanf("%ld%ld",&n,&k);
    long two = 0, five = 0;

    five = countFive(n) - countFive(n - k) - countFive(k);
    two = countTwo(n) - countTwo(n - k) - countTwo(k);
    
    printf("%ld", two > five ? five : two);
}