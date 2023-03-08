//Stack 10828

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
int H[10000]; int top = -1;
int isEmpty(){return top == -1;}
int size(){return top + 1;}
int returnTop(){
    if(isEmpty()){return -1;}
    return H[top];
}
void push(int n){
    if(top >= 9999) return;
    H[++top] = n;
}
int pop(){
    if(isEmpty()){return -1;}
    return H[top--];
}
int main(){
    int n; scanf("%d",&n); getchar();
    char Order[6]; int val;
    for(int i = 0; i < n; i++){
        scanf("%s", Order);
        if(strcmp("push", Order) == 0){scanf("%d",&val); push(val);}
        else if(strcmp("pop", Order) == 0){printf("%d\n",pop());}
        else if(strcmp("top", Order) == 0){printf("%d\n",returnTop());}
        else if(strcmp("size", Order) == 0){printf("%d\n",size());}
        else if(strcmp("empty", Order) == 0){printf("%d\n",isEmpty());}
    }
}