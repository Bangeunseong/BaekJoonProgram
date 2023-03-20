//Mathematics 4344

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int arr[1000];
int main(){
    int n; scanf("%d",&n);
    for(int i = 0; i < n; i++){
        int m, sum = 0, cnt = 0; scanf("%d",&m);
        for(int j = 0; j < m; j++){
            scanf("%d",&arr[j]); sum += arr[j];
        }
        double avg = (double)sum / m;
        for(int j = 0; j < m; j++){
            if(arr[j] > avg) cnt++;
        }
        printf("%.3lf%%\n",((double)cnt / m)*100);
    }
}