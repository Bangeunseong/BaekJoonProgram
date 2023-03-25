//Mathematics 1292

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int main(){
    int a, b; scanf("%d%d",&a,&b);

    int cnt = 0, sum = 0;
    for(int i = 1;;i++){
        for(int j = 1; j <= i; j++){
            cnt++;
            if(cnt > b){printf("%d",sum); return 0;}
            if(cnt >= a && cnt <= b) sum += i;
        }
    }
}