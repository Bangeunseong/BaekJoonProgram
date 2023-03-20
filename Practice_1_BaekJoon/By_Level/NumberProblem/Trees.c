//NumberProblem 2485

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define SIZE 100000

int cnt; int arr[SIZE];

int compare(const void *p, const void *q){
    int x = *(const int *)p;
    int y = *(const int *)q;
    return (x > y) - (x < y);
}

int gcd(int n, int k){
    int base = n, div = k;
    while(div != 0){int tmp = base % div; base = div; div = tmp;}
    return base;
}

int Calculate(){
    int min = arr[1] - arr[0];
    for(int i = 1; i < cnt - 1; i++){
        int G = gcd(min, arr[i + 1] - arr[i]);
        min = min > G ? G : min;
    }
    return min;
}

int main(){
    scanf("%d",&cnt);
    for(int i = 0; i < cnt; i++) scanf("%d", arr + i);
    qsort(arr, cnt, sizeof(*arr),compare);
    int result = (arr[cnt - 1] - arr[0]) / Calculate();
    printf("%d",result - cnt + 1);
}