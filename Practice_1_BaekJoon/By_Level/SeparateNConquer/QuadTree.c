//Separate N Conquer 1992

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int Check(int **board, int len, int x, int y){
    int offset = board[y][x];
    for(int i = y; i < y + len; i++){
        for(int j = x; j < x + len; j++){
            if(board[i][j] != offset) return 0;
        }
    }
    return 1;
}

void QuadTree(int **board, int len, int x, int y){
    int offset = board[y][x];
    if(Check(board, len, x, y)) {printf("%d",offset); return;}

    printf("(");
    QuadTree(board, len/2, x, y);
    QuadTree(board, len/2, x + len/2, y);
    QuadTree(board, len/2, x, y + len/2);
    QuadTree(board, len/2, x + len/2, y + len/2);
    printf(")");
}
int main(){
    int n; scanf("%d", &n);
    int **Tree = (int **)malloc(sizeof(int*)*n);
    for(int i = 0; i < n; i++){
        Tree[i] = (int *)malloc(sizeof(int)*n);
        char tmp[65]; scanf("%s",tmp); int len = strlen(tmp);
        for(int j = 0; j < len; j++) Tree[i][j] = tmp[j] - '0';
    }

    QuadTree(Tree,n,0,0);
}