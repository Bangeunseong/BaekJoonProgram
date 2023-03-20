//Mathematics 1011

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)
int main(){
    int n; scanf("%d",&n);
    for(int i = 0; i < n; i++){
        long s,e; scanf("%ld%ld",&s,&e);
        long distance = e - s; long cnt = 0;
        while(1){
            if(pow(cnt,2) <= distance && distance < pow(cnt + 1, 2)) break;
            cnt++;
        }
        if(pow(cnt, 2) == distance) printf("%ld\n", cnt*2 - 1);
        else if(pow(cnt, 2) < distance && distance <= pow(cnt, 2) + cnt) printf("%ld\n", cnt*2);
        else printf("%ld\n", cnt*2 + 1);
    }
}