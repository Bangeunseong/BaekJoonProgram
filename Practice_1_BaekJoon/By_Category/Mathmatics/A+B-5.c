//Mathematics 10952

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int main(){
    while(1){
        int a,b; scanf("%d%d",&a,&b); if(a == 0 && b == 0) break;
        printf("%d\n",a+b);
    }
}