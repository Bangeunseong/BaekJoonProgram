//SeparateNConquer 2630

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
int w = 0, b = 0;

void Calculate(int **board, int len, int x, int y){
    int sum = 0;
    for(int i = y; i < y + len; i++){
        for(int j = x; j < x + len; j++){
            sum += board[i][j];
        }
    }
    if(sum == len*len){b++; return;}
    if(sum == 0){w++; return;}

    Calculate(board, len/2, x, y);
    Calculate(board, len/2, x + len/2, y);
    Calculate(board, len/2, x, y + len/2);
    Calculate(board, len/2, x + len/2, y + len/2);
}

int main(){
    int n; scanf("%d", &n);
    int **board = (int **)malloc(sizeof(int*)*n);
    for(int i = 0; i < n; i++) board[i] = (int *)malloc(sizeof(int)*n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) scanf("%d",&board[i][j]);
    }
    Calculate(board,n,0,0);
    printf("%d\n%d",w,b);
}