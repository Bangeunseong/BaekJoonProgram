//Separate N Conquer 10830

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int A[5][5]; int Origin[5][5]; int n; long long k;

void Multiply(int Origin[5][5]){
    int B[5][5];
    for(long i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            B[i][j] = 0;
            for(int w = 0; w < n; w++){
                B[i][j] += Origin[i][w] % 1000 * A[w][j] % 1000;
                B[i][j] %= 1000;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) A[i][j] = B[i][j]; 
    }
}

void Calculate(long long exp){
    if(exp == 1) return;
    Calculate(exp/2);
    Multiply(A);
    if(exp % 2 != 0) Multiply(Origin);
}

int main(){
    scanf("%d%ld",&n,&k);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            scanf("%d",&A[i][j]);
            A[i][j] %= 1000; Origin[i][j] = A[i][j];
        }
    }

    Calculate(k);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) printf("%d ",A[i][j]);
        printf("\n");
    }
}