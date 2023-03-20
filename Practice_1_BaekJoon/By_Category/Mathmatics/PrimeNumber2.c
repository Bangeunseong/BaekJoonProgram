//Mathematics 2581

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define SIZE 10000

int arr[10001];

void Prime(){
    arr[0] = arr[1] = -1;
    for(int i = 2; i <= SIZE; i++){
        if(arr[i] == 0) {
            arr[i] = 1;
            for(int j = i*2; j <= SIZE; j += i) arr[j] = -1;
        }
    }
}
int main(){
    Prime(); int n, m, min = SIZE + 1, sum = 0; scanf("%d%d",&n,&m);
    for(int i = n; i <= m; i++){
        if(arr[i] == 1){sum += i; min = min > i ? i : min;}
    }
    if(sum)
        printf("%d\n%d",sum,min);
    else
        printf("-1");
}