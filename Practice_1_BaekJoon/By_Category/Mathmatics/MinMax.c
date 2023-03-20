//Mathematics 10818

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int main(){
    int n; scanf("%d",&n);
    int min,max;
    for(int i = 0; i < n; i++){
        int val; scanf("%d",&val);
        if(i == 0) min = max = val;
        else{
            min = min > val ? val : min;
            max = max < val ? val : max;
        }
    }
    printf("%d %d",min,max);
}