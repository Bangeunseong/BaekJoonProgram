//Mathematics 11021

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int main(){
    int n; scanf("%d",&n);
    for(int i = 0; i < n; i++){
        int a,b; scanf("%d%d",&a,&b);
        printf("Case #%d: %d\n",i + 1, a+b);
    }
}