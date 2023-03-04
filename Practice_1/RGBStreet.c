#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int min(int x, int y){return x < y? x : y;}
int main(){
    int cost[1000][3];
    int n; scanf("%d",&n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++) scanf("%d",&cost[i][j]);
    }

    for(int i = 1; i < n; i++){
        cost[i][0] += min(cost[i - 1][1], cost[i - 1][2]);
        cost[i][1] += min(cost[i - 1][0], cost[i - 1][2]);
        cost[i][2] += min(cost[i - 1][0], cost[i - 1][1]);
    }

    int result = cost[n - 1][0];
    for(int i = 1; i < 3; i++){result = min(result, cost[n - 1][i]);}
    printf("%d",result);
}