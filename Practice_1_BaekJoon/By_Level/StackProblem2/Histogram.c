//StackProblem2 1725

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define SIZE 100000
long long arr[SIZE + 2] = {0,}; int stack[SIZE + 2] = {0,}; int n; int top = -1;
long long max = 0; int ind = 0; int len = 0;

int isEmpty(){return top == -1;}
int returnTop(){return stack[top];}
void push(int val){stack[++top] = val;}
int pop(){return stack[top--];}

int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%lld",&arr[i]);
        if(arr[i] >= 1) len++;
        else {max = max < len ? len : max; len = 0;}
    }

    push(0);
    for(int i = 1; i <= n + 1; i++){
        while(!isEmpty() && arr[returnTop()] > arr[i]){
            int ind = pop();
            max = max < (arr[ind] * (i - ind)) ? (arr[ind] * (i - ind)) : max;
        }
        push(i);
    }
    printf("%lld",max);
}