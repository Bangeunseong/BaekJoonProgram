//StackProblem2 17298

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define SIZE 1000000

int arr[SIZE]; int stack[SIZE]; int NGE[SIZE]; int top = -1;

int isEmpty(){return top == -1;}
void push(int val){stack[++top] = val;}
int pop(){return stack[top--];}

int n;
int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {scanf("%d",&arr[i]); NGE[i] = -1;}

    for(int i = 0; i < n; i++){
        while(!isEmpty() && arr[stack[top]] < arr[i]){
            NGE[pop()] = arr[i];
        }
        push(i);
    }
    for(int i = 0; i < n; i++) printf("%d ", NGE[i]);
}