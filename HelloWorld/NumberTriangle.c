#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int max(int x, int y){return x>y?x:y;}
int main(){
    int n; scanf("%d",&n);
    int **triangle = (int **)malloc(sizeof(int*)*n);
    for(int i = 0; i < n; i++){
        triangle[i] = (int *)malloc(sizeof(int)*(i+1));
    }

    scanf("%d",&triangle[0][0]);
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= i; j++){
            scanf("%d",&triangle[i][j]);
            if(j == 0){triangle[i][j] += triangle[i - 1][j];}
            else if(j == i){triangle[i][j] += triangle[i - 1][j - 1];}
            else{triangle[i][j] += max(triangle[i - 1][j], triangle[i - 1][j - 1]);}
        }
    }

    int maximum = 0;
    for(int i = 0; i < n; i++) maximum = max(maximum, triangle[n - 1][i]);
    printf("%d",maximum);
}