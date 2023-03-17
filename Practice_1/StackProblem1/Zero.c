//Stack 10773

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
int H[100000]; int top = -1;
int isEmpty(){return top == -1;}
int size(){return top + 1;}
int returnTop(){
    if(isEmpty()){return -1;}
    return H[top];
}
void push(int n){
    if(top >= 99999) return;
    H[++top] = n;
}
int pop(){
    if(isEmpty()){return -1;}
    return H[top--];
}
int main(){
    int n; scanf("%d", &n);

    long sum = 0; int val;
    for(int i = 0; i < n; i++){
        scanf("%d",&val);
        if(val != 0){push(val);}
        else pop();
    }

    for(int i = 0; i <= top; i++){sum += H[i];}
    printf("%ld", sum);
}