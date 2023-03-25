//Mathematics 2225

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define NUM 1000000000

int n, k; long dp[201][201];
int main(){
    scanf("%d%d",&n,&k);
    for(int i = 1; i <= k; i++){
        for(int j = 0; j <= n; j++){
            if(j == 0) dp[i][j] = 1;
            else{dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % NUM;}
        }
    }
    printf("%ld", dp[k][n] % NUM);
}