//Separate N Conquer 2740

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int n, m, k;
unsigned long long A[100][100], B[100][100], C[100][100];

void Calculate(int x, int y){
    if(y >= n) return;
    for(int w = 0; w < m; w++){
        C[y][x % k] += A[y][w] * B[w][x % k];
    }
    if((x + 1) % k == 0) Calculate(x + 1, y + 1);
    else Calculate(x + 1, y);
}

int main(){
    
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) scanf("%ld",&A[i][j]);
    }
    scanf("%d%d",&m,&k);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < k; j++) scanf("%ld",&B[i][j]);
    }
    
    Calculate(0, 0);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++) {
            printf("%ld", C[i][j]);
            if(j != k - 1) printf(" ");
            else printf("\n");
        }
    }
}