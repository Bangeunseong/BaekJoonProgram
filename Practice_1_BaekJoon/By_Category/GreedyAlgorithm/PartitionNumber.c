//GreedyAlgorithm 1744

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int compare(const void *p, const void *q){
    int x = *(const int *)p;
    int y = *(const int *)q;
    if(x <= 0 && y <= 0) return (x > y) - (x < y);
    return (x < y) - (x > y);
}

int arr[50]; int n, flag = 0; long long result = 0;
int arr_pos[50], arr_neg[50]; int pos = 0, neg = 0;
int main(){
    scanf("%d",&n);
    for(int i = 0;i < n; i++) scanf("%d",&arr[i]);
    qsort(arr,n,sizeof(*arr),compare);
    for(int i = 0; i < n; i++){
        if(arr[i] > 0) arr_pos[pos++] = arr[i];
        else arr_neg[neg++] = arr[i];
    }

    for(int i = 0; i < pos; i++){
        if(i + 1 < pos){
            if(arr_pos[i] * arr_pos[i + 1] > arr[i] + arr[i + 1]){result += arr_pos[i] * arr_pos[i + 1]; i++;}
            else result += arr_pos[i];
        }
        else result += arr_pos[i];
    }

    for(int i = 0; i < neg; i++){
        if(i + 1 < neg){
            if(arr_neg[i] * arr_neg[i + 1] > arr_neg[i] + arr_neg[i + 1]){result += arr_neg[i] * arr_neg[i + 1]; i++;}
            else result += arr_neg[i];
        }
        else result += arr_neg[i];
    }

    printf("%lld", result);
}