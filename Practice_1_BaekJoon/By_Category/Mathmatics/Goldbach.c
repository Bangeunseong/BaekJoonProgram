//Mathematics 9020

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define SIZE 10000

int arr[SIZE + 1];
void Prime(){
    arr[0] = arr[1] = -1;
    for(int i = 2; i <= SIZE; i++){
        if(arr[i] == 0) arr[i] = 1;
        for(int j = i*2; j <= SIZE; j += i) arr[j] = -1;
    }
}
void print(int val){
    int a,b;
    for(int i = 2; i <= val / 2; i++){
        if(arr[i] == 1){if(arr[val - i] == 1){a = i; b = val - i;}}
    }
    printf("%d %d\n",a,b);
}
int main(){
    Prime(); int n; scanf("%d",&n);
    for(int i = 0; i < n; i++){
        int val; scanf("%d",&val);
        print(val);
    }
}