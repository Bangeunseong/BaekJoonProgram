//GreedyAlgorithm 1931

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define SIZE 100001

typedef struct Time{
    long start, end;
}Time;
Time schedule[SIZE];

int compare(const void *p, const void *q){
    Time x = *(const Time *)p;
    Time y = *(const Time *)q;
    if(x.end == y.end) return (x.start > y.start) - (x.start < y.start);
    return (x.end > y.end) - (x.end < y.end);
}

int main(){
    int n; scanf("%d",&n);
    for(int i = 0; i < n; i++){scanf("%ld%ld",&schedule[i].start, &schedule[i].end);}
    qsort(schedule, n, sizeof(*schedule), compare);
    long offset = schedule[0].end; int cnt = 1;
    for(int i = 1; i < n; i++){
        if(offset <= schedule[i].start) {offset = schedule[i].end; cnt++;}
    }
    printf("%d",cnt);
}