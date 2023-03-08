//Greedy Algorithm 1931

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
typedef struct Schedule{
    int start, end;
}Schedule;
void sort(Schedule *table, int n){
    for (int i = 1; i < n; i++) {
		Schedule val = table[i];
		int j = i - 1;
		while (j >= 0 && table[j].end >= val.end) {
            if(table[j].end == val.end && table[j].start > val.start){table[j + 1] = table[j]; j--;}
            else{table[j + 1] = table[j]; j--;}
        }
		table[j + 1] = val;
	}
}
int main(){
    int n; scanf("%d",&n);
    Schedule *table = (Schedule *)malloc(sizeof(Schedule)*n);
    for(int i = 0; i < n; i++){scanf("%d%d",&table[i].start, &table[i].end);}

    sort(table, n);

    int deadline = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        if(table[i].start >= deadline){
            deadline = table[i].end;
            cnt++;
        }
    }
    printf("%d",cnt);
}