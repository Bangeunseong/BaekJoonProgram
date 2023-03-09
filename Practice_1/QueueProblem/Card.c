//Queue, Deck 2164

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define SIZE 5000000
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
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; i++){push(i);}
    
    int j = 0;
    while(size() > 1){
        if(j % 2 == 0) pop();
        else{
            int val = pop();
            push(val);
        }
        j++;
    }
    printf("%d",pop());
}