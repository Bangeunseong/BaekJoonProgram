//Mathematics 10430

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int main(){
    int a,b,c; scanf("%d%d%d",&a,&b,&c);
    printf("%d\n%d\n%d\n%d",(a+b)%c,((a%c) + (b%c))%c,(a*b)%c,((a%c)*(b%c))%c);
}