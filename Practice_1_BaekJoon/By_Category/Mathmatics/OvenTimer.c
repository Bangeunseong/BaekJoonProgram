//Mathematics 2525

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int main(){
    int h, m; scanf("%d%d",&h,&m);
    int t; scanf("%d",&t);
    h += (m+t)/60;
    m = (m + t) % 60;
    printf("%d %d",h % 24, m % 60);
}