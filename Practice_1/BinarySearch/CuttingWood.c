//BinarySearch 2805

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define SIZE 1000000

long long arr[SIZE]; long long n; long long k;

long long Count(long long len){
    long long sum = 0;
    for(int i = 0; i < n; i++){
        sum += (arr[i] - len > 0 ? arr[i] - len : 0);
    }
    return sum;
}

long long Calculate(long long first, long long last){
    while(first <= last){
        long long len = (first + last)/2;
        long long leftover = Count(len);
        if(leftover < k) last = len - 1;
        else first = len + 1;
    }
    return last;
}

int main(){
    scanf("%lld%lld",&n,&k);

    long long maxLength = 0;
    for(int i = 0; i < n; i++){
        scanf("%lld", &arr[i]);
        if(i == 0) maxLength = arr[i];
        else maxLength = (maxLength < arr[i] ? arr[i] : maxLength);
    }

    printf("%lld",Calculate(0,maxLength));
}