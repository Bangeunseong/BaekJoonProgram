//StackProblem2 9935

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define SIZE 1000000

char str[SIZE + 1]; char elem[37];
char stack[SIZE]; int top = -1;

int isEmpty(){return top == -1;}
void push(char val){stack[++top] = val;}
char pop(){return stack[top--];}

int main(){
    scanf("%s",str); scanf("%s",elem);
    
    int ind = 0, len1 = strlen(str), len2 = strlen(elem), flag = 0;
    for(int i = 0; i < len1; i++){
        push(str[i]);
        if(stack[top] != elem[len2 - 1]) continue;
        if(top < len2 - 1) continue;
        if(strncmp(stack + top - len2 + 1, elem, len2) == 0){
            for(int j = 0; j < len2; j++) pop();
        }
    }

    if(!isEmpty()){for(int i = 0; i <= top; i++){printf("%c",stack[i]);}}
    else printf("FRULA");
}