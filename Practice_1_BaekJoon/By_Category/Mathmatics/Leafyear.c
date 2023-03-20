//Mathematics 2753

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int isLeafyear(int year){
    if(year % 4 != 0) return 0;
    if(year % 100 == 0 && year % 400 != 0) return 0;
    return 1;
}
int main(){
    int n; scanf("%d",&n);
    printf("%d",isLeafyear(n));
}