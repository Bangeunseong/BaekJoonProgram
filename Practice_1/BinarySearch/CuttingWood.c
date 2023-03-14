//BinarySearch 2805

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define SIZE 1000000

long arr[SIZE]; int n, k;

long Count(int len){
    long sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i] - len > 0 ? arr[i] - len : 0;
    }
    return sum;
}

long Calculate(long first, long last){
    
}

int main(){
    scanf("%d%d",&n,&k);

    long maxLength = 0;
    for(int i = 0; i < n; i++){
        scanf("%ld", &arr[i]);
        if(i == 0) maxLength = arr[i];
        else maxLength = maxLength < arr[i] ? arr[i] : maxLength;
    }
}