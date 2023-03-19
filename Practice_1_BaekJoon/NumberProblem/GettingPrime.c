//NumberProblem 1929

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define SIZE 1000000

int arr[SIZE + 1];
void GetPrime(int m){
    arr[1] = -1;
    for(int i = 2; i <= m; i++){
        if(arr[i] == 0) arr[i] = 1;
        for(int j = 2*i; j <= m; j += i) arr[j] = -1;
    }
}
int main(){
    int n, m; scanf("%d%d",&n,&m); GetPrime(m);
    for(int i = n; i <= m; i++){
        if(arr[i] == 1) printf("%d\n",i);
    }
}