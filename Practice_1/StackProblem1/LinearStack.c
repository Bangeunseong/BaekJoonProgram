//Stack 1874


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
int H[100000]; int top = -1; char Log[200000]; int in = -1;
int isEmpty(){return top == -1;}
int size(){return top + 1;}
int returnTop(){
    if(isEmpty()){return 0;}
    return H[top];
}
void push(int n){
    H[++top] = n;
}
int pop(){
    if(isEmpty()){return 0;}
    return H[top--];
}
int main(){
    int n; scanf("%d", &n); int val = 1, j = 0, flag = 0;
    int *x = (int *)malloc(sizeof(int)*n);
    for(int i = 0; i < n; i++) scanf("%d", x + i);

    while(j < n){
        if(returnTop() < x[j]) {push(val++); Log[++in] = '+';}
        else if(returnTop() == x[j]){pop(); Log[++in] = '-'; j++;}
        else{flag = 1; break;}
    }

    if(!flag){
        for(int i = 0; i <= in; i++){
            printf("%c\n", Log[i]);
        }
    }
    else printf("NO");
}