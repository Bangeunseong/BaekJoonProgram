//Greedy Algorithm 11047

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int main(){
    int n, val; scanf("%d%d",&n, &val);
    int *coin = (int *)malloc(sizeof(int)*n);
    for(int i = 0; i < n; i++){scanf("%d",coin + i);}

    int min = 0;
    while(val != 0){
        int f = 0, l = n - 1;
        while(1){
            if(f == l || l - f == 1){
                if(coin[l] <= val) val -= coin[l];
                else val -= coin[f];
                break;
            }
            else{
                int v = (f + l) / 2;
                if(val > coin[v]) f = v;
                else l = new;
            }
        }
        min++;
    }
    printf("%d",min);
}