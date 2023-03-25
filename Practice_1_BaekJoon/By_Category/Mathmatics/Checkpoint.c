//Mathematics 2981

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)
#define SIZE 100

long arr[SIZE + 1]; int n;

int main(){
    long max; scanf("%d",&n); 
    for(int i = 0; i < n; i++) {
        scanf("%ld",&arr[i]);
        if(i == 0) max = arr[i];
        else max = max < arr[i] ? arr[i] : max;
    }

    for(int i = 2; i <= sqrt(max); i++){
        int flag = 0; long offset = max % i;
        for(int j = 0; j < n; j++){
            if(arr[j] % i != offset){flag = 1; break;}
        }
        if(!flag) printf("%d ", i);
    }
}