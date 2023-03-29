//GreedyAlgorithm 1789

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int main(){
    long n; long tmp = 0; scanf("%ld",&n);

    long i = 1;
    while(tmp < n){tmp += i; i++;}
    printf("%ld", tmp == n ? i - 1 : i - 2);
}