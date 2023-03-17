//DynamicProgramming 11066

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int arr[501]; int n, m;
int dp[501][501];
int minMat[501][501];
int start, end;

int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d",&m);
        for(int j = 1; j <= m; j++){
            int val; scanf("%d",&val);
            arr[i] = arr[i - 1] + val;
            minMat[i][i] = i;
        }

        for(int j = 1; j < m; j++){

        }
    }
    
}