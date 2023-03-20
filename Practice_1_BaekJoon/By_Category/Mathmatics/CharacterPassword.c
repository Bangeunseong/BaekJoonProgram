//Mathematics 1759

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

char arr[15]; int n,m;
char ans[16]; int vowel = 0, consonant = 0;
int compare(const void *p, const void *q){
    int x = *(const char *)p - 'a';
    int y = *(const char *)q - 'a';
    return (x > y) - (x < y);
}

int isVowel(char ch){
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return 1;
    return 0;
}

void printPassword(int ind, int size){
    if(size >= n){if(vowel > 0 && consonant > 1) printf("%s\n",ans); return;}
    for(int i = ind; i < m; i++){
        ans[size] = arr[i];
        if(isVowel(arr[i])) vowel++;
        else consonant++;
        printPassword(i + 1, size + 1);
        if(isVowel(arr[i])) vowel--;
        else consonant--;
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0; i < m; i++) scanf(" %c", &arr[i]);
    qsort(arr, m, sizeof(*arr), compare);
    printPassword(0,0);
}