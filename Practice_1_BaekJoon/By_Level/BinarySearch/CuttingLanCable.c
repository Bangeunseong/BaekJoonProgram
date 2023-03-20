//BinarySearch 1654

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

long arr[10000]; int n, k;

int Count(long len){
    int sum = 0;
    for(int i = 0; i < n; i++){sum += arr[i] / len;}
    return sum;
}

long Search(long first, long last){
    while(first <= last){
        long len = (first + last)/2;
        int cnt = Count(len);
        if(k <= cnt) {first = len + 1;}
        else last = len - 1;
    }
    return last;
}

int main(){
    scanf("%d%d",&n,&k);

    long maxLength = 0;
    for(int i = 0; i < n; i++){
        scanf("%ld", &arr[i]);
        if(i == 0) maxLength = arr[i];
        else maxLength = maxLength < arr[i] ? arr[i] : maxLength;
    }
    printf("%ld", Search(1, maxLength));
}