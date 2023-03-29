//GreedyAlgorithm 2217

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define SIZE 100000

int arr[SIZE]; int n;

int compare(const void *p, const void *q){
    int x = *(const int *)p;
    int y = *(const int *)q;
    return (x > y) - (x < y);
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d",&arr[i]);
    qsort(arr, n, sizeof(*arr), compare);

    int max = 0;
    for(int i = 0; i < n; i++){
        max = max < arr[i] * (n - i) ? arr[i] * (n - i) : max;
    }
    printf("%d",max);
}