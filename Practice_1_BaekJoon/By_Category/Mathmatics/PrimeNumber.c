//Mathematics 1978

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define SIZE 1000
int arr[SIZE + 1];
void Prime(){
    for(int i = 2; i <= SIZE; i++){
        if(arr[i] == 0) {
            arr[i] = 1;
            for(int j = i*2; j <= SIZE; j += i)
                arr[j] = -1;
        }
    }
}
int main(){
    Prime();
    int n; scanf("%d",&n); int cnt = 0;
    for(int i = 0; i < n; i++){
        int val; scanf("%d",&val);
        if(arr[val] == 1) cnt++;
    }
    printf("%d",cnt);
}