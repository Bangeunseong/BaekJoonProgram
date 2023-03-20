//BinarySearch 2110

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define SIZE 200000

long arr[SIZE]; int n, k;


int compare_ints(const void *p, const void *q){
    long x = *(const long *)p;
    long y = *(const long *)q;

    return (x > y) - (x < y);
}

long Calculate(long first, long last){
    while(first <= last){
        int cnt = 1; int in = 0;
        int len = (first + last) / 2;
        for(int i = 1; i < n; i++){
            if(arr[i] - arr[in] >= len){in = i; cnt++;}
        }
        if(cnt >= k) first = len + 1;
        else last = len - 1;
    }
    return last;
}

int main(){
    scanf("%d%d",&n,&k);

    for(int i = 0; i < n; i++){
        scanf("%ld",&arr[i]);
    }
    qsort(arr, n, sizeof(*arr), compare_ints);
    printf("%ld",Calculate(1, arr[n - 1] - arr[0]));
}