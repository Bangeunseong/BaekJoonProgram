#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int main(){
    int n, m; scanf("%d%d", &n, &m);
    long *x = (long *)malloc(sizeof(long)*(n + 1)); x[0] = 0;
    long *cnt = (long *)malloc(sizeof(long)*(m + 1));

    for(int i = 1; i <= n; i++){
        int s; scanf("%d", &s);
        x[i] = (s + x[i - 1]) % m;
        cnt[x[i]]++;
    }

    long ans = cnt[0];
    for(int i = 0; i < m; i++){
        ans += (cnt[i] * (cnt[i] - 1)) / 2;
    }
    printf("%ld", ans);
}