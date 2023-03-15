//BinarySearch 1300

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

long n, k;

long min(long len, long i){return len > i ? i : len;}

long Calculate(long first, long last){
    while(first <= last){
        long len = (first + last) / 2;
        long cnt = 0;
        for(int i = 1; i <= n; i++){cnt += min(len/i, n);}
        if(cnt >= k) last = len - 1;
        else first = len + 1;
    }
    return first;
}

int main(){
    scanf("%ld%ld",&n, &k);
    printf("%ld",Calculate(1, k));
}