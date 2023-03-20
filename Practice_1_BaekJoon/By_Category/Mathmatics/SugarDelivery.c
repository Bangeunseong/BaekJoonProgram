//Mathematics 2839

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int Calculate(int w){
    if(w < 3) return -1;
    int cnt = 0;
    while(1){
        if(w == 0) break;
        if(w < 3) return -1;
        if(w % 5 == 0) return cnt += w / 5;
        w -= 3; cnt++;
    }
    return cnt;
}
int main(){
    int w; scanf("%d",&w);
    printf("%d",Calculate(w));
}