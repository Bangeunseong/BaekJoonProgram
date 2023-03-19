//Greedy Algorithm 13305

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int main(){
    int n; scanf("%d",&n);
    int *road = (int *)malloc(sizeof(int)*(n - 1));
    long *gas = (long *)malloc(sizeof(long)*n);
    for(int i = 0; i < n - 1; i++){scanf("%d",road + i);}
    for(int i = 0; i < n; i++){scanf("%d",gas + i);}

    long Loadgas = gas[0]; long totalgas = 0;
    for(int i = 0; i < n - 1; i++){
        if(Loadgas > gas[i]){
            Loadgas = gas[i];
            totalgas += Loadgas * road[i];
        }
        else totalgas += Loadgas * road[i];
    }
    printf("%ld",totalgas);
}