//Greedy Algorithm 11399

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
void sort(int *table, int n){
    for (int i = 2; i <= n; i++) {
		int val = table[i];
		int j = i - 1;
		while (j >= 0 && table[j] >= val){table[j + 1] = table[j]; j--;}
		table[j + 1] = val;
	}
}
int main(){
    int n; scanf("%d",&n);
    int *x = (int *)malloc(sizeof(int)*(n + 1));
    x[0] = 0; for(int i = 1; i <= n; i++) scanf("%d",x + i);
    
    sort(x, n);

    int sum = 0;
    for(int i = 1; i <= n; i++){
        x[i] += x[i - 1]; sum += x[i];
    }
    printf("%d",sum);
    free(x);
}