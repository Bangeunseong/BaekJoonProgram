//Separate N Conquer 1780

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int minus = 0, zero = 0, plus = 0;

int Check(int **board, int len, int x, int y){
    int offset = board[y][x];
    for(int i = y; i < y + len; i++){
        for(int j = x; j < x + len; j++)
            if(offset != board[i][j]) return 0;
    }
    return 1;
}

void Calculate(int **board, int len, int x, int y){
    int offset = board[y][x];
    if(Check(board, len, x, y)){
        if(offset == -1) minus++;
        else if(offset == 0) zero++;
        else plus++;
        return;
    }

    int maniplen = len/3;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            Calculate(board, maniplen, x + maniplen * j, y + maniplen * i);
        }
    }

}

int main(){
    int n; scanf("%d", &n);
    int **board = (int **)malloc(sizeof(int*)*n);
    for(int i = 0 ; i < n; i++){
        board[i] = (int *)malloc(sizeof(int)*n);
        for(int j = 0; j < n; j++) scanf("%d",&board[i][j]);
    }

    Calculate(board,n,0,0);
    printf("%d\n%d\n%d",minus,zero,plus);
}