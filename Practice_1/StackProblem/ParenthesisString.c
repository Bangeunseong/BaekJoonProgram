//Stack 9012

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
int H[50];
int isEmpty(int *top){return *top == -1;}
int size(int *top){return *top + 1;}
int returnTop(int *top){
    if(isEmpty(top)){return -1;}
    return H[*top];
}
void push(int n, int *top){
    if(*top >= 49) return;
    H[++(*top)] = n;
}
int pop(int *top){
    if(isEmpty(top)){return 0;}
    return H[(*top)--];
}
int main(){
    int n; scanf("%d", &n); char str[51];
    for(int i = 0; i < n; i++){
        int top = -1, flag = 0;
        scanf("%s",str); int len = strlen(str);
        for(int j = 0; j < len; j++){
            if(str[j] == '(') push(1,&top);
            else{if(!pop(&top)){flag = 1; break;}}
        }
        if(flag) printf("NO\n");
        else if(size(&top)) printf("NO\n");
        else printf("YES\n");
    }
}