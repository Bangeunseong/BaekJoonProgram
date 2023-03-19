#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
int main(){
    char str[200001]; scanf("%s", str);
    int cnt[200001][26] = {0,};

    int len = strlen(str);
    for(int i = 0; i < len; i++){
        if(i > 0){
            for(int j = 0; j < 26; j++){cnt[i][j] = cnt[i - 1][j];}
            cnt[i][(int)(str[i] - 'a')]++;
            continue;
        }
        cnt[i][(int)(str[i] - 'a')]++;
    }

    int n; scanf("%d",&n); getchar();
    for(int i = 0; i < n; i++){
        char ch; int f, l; scanf("%c %d %d", &ch, &f, &l); getchar();
        if(f > 0)
            printf("%d\n", cnt[l][(int)(ch - 'a')] - cnt[f - 1][(int)(ch - 'a')]);
        else
            printf("%d\n", cnt[l][(int)(ch - 'a')]);
    }
}