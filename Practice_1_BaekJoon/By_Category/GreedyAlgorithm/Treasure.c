//GreedyAlgorithm 1026

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int A[50], B[50]; int n;
int compare(const void *p, const void *q){
    int x = *(const int *)p;
    int y = *(const int *)q;
    return (x > y) - (x < y);
}
int main(){
    scanf("%d",&n); 
    for(int i = 0; i < n; i++) scanf("%d",&A[i]);
    qsort(A, n, sizeof(*A), compare);
    for(int i = 0; i < n; i++) scanf("%d",&B[i]);
    qsort(B, n, sizeof(*B), compare);

    int sum = 0;
    for(int i = 0; i < n; i++){sum += A[i] * B[n - i - 1];}
    printf("%d",sum);
}