//Stack 4949

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
int H[100];
int isEmpty(int *top){return *top == -1;}
int size(int *top){return *top + 1;}
int returnTop(int *top){
    if(isEmpty(top)){return -1;}
    return H[*top];
}
void push(int n, int *top){
    if(*top >= 99) return;
    H[++(*top)] = n;
}
int pop(int *top){
    if(isEmpty(top)){return 0;}
    return H[(*top)--];
}
int main(){
    char str[101];
    while(1){
        int top = -1, flag = 0;
        gets(str); int len = strlen(str);
        if(strcmp(str, ".") == 0) break;
        
        for(int j = 0; j < len; j++){
            if(str[j] == '(') push(1,&top);
            else if(str[j] == '[') push(2,&top);
            else if(str[j] == ')'){
                if(pop(&top) != 1){flag = 1; break;}
            }
            else if(str[j] == ']'){
                if(pop(&top) != 2){flag = 1; break;}
            }
        }
        if(flag) printf("no\n");
        else if(size(&top)) printf("no\n");
        else printf("yes\n");
    }
}