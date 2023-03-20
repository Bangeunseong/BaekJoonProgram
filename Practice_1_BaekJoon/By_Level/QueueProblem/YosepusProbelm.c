//Queue, Deck 11866

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define SIZE 1000
int H[SIZE]; int f = 0, l = -1; int volume = 0;
int isEmpty(){return f > l;}
int size(){return (l - f + 1) % volume;}
int front(){
    if(isEmpty()){return -1;}
    return H[f % volume];
}
int back(){
    if(isEmpty()){return -1;}
    return H[l % volume];
}
void push(int n){H[(++l) % volume] = n;}
int pop(){
    if(isEmpty()){return -1;}
    return H[(f++) % volume];
}
int main(){
    int k; scanf("%d%d", &volume, &k);
    for(int i = 1; i <= volume; i++){push(i);}

    int j = 1;
    printf("<");
    while(!isEmpty()){
        if(j % k == 0){
            printf("%d", pop());
            if(isEmpty()) printf(">");
            else printf(", ");
        }
        else{int val = pop(); push(val);}
        j++;
        
    }
}