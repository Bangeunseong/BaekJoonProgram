//Mathematics 8393

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int main(){
    int n; scanf("%d",&n);
    int sum = 0;
    for(int i = 1; i <= n; i++) sum += i;
    printf("%d",sum);
}