//NumberProblem 17103

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
    while(1){
        int val; scanf("%d",&val); if(val == 0) break;
        GetPrime(val*2);
        int sum = 0;
        for(int i = val + 1; i <= val *2; i++){sum = arr[i] == 1 ? sum + 1 : sum;}
        printf("%d\n",sum);
    }
}
int main(){
    
}