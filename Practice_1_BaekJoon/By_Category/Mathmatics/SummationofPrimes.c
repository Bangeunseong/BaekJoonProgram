//Mathematics 1644

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define SIZE 4000000

int prime[SIZE + 1]; int ind = 0;
int primes[SIZE + 1];
void Prime(){
    prime[0] = prime[1] = -1;
    for(int i = 2; i <= SIZE; i++){
        if(!prime[i]) {
            prime[i] = 1; primes[ind + 1] = primes[ind] + i; ind++;
            for(int j = i*2; j <= SIZE; j += i){prime[j] = -1;}
        }
    }
}
int main(){
    Prime();
    int val; scanf("%d",&val);
    int cnt = 0; int l = 0, r = 1;
    while(l < r){
        int sum = primes[r] - primes[l];
        if(sum < val) r++;
        else if(sum > val) l++;
        else {cnt++; r++;}
    }
    printf("%d",cnt);
}