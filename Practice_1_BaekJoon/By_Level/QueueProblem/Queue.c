//Queue, Deck 18258

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

#define SIZE 2000000
int H[SIZE]; int f = 0, l = -1;
int isEmpty(){return f > l;}
int size(){return (l - f + 1) % SIZE;}
int front(){
    if(isEmpty()){return -1;}
    return H[f%SIZE];
}
int back(){
    if(isEmpty()){return -1;}
    return H[l%SIZE];
}
void push(int n){H[(++l)%SIZE] = n;}
int pop(){
    if(isEmpty()){return -1;}
    return H[(f++)%SIZE];
}
int main(){
    int n; scanf("%d", &n); char str[6];
    for(int i = 0; i < n; i++){
        scanf("%s",str);
        if(strcmp("push", str) == 0){int val; scanf("%d",&val); push(val);}
        else if(strcmp("pop", str) == 0){printf("%d\n",pop());}
        else if(strcmp("front", str) == 0){printf("%d\n",front());}
        else if(strcmp("back", str) == 0){printf("%d\n",back());}
        else if(strcmp("size", str) == 0){printf("%d\n",size());}
        else if(strcmp("empty", str) == 0){printf("%d\n",isEmpty());}
    }
}