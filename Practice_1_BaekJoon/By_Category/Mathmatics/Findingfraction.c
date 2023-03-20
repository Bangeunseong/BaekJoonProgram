//Mathematics 1193

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int main(){
    int i = 1, j = 1; int ind = 1, flag = 0; int n; scanf("%d",&n);
    while(1){
        if(ind == n) break;
        if(!flag){
            if(i == 1){flag = 1; j++;}
            else{i--; j++;}
        }
        else{
            if(j == 1){flag = 0; i++;}
            else{i++; j--;}
        }
        ind++;
    }
    printf("%d/%d",i,j);
}