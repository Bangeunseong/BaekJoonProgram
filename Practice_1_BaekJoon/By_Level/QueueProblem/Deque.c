//Queue, Deque 10866

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define SIZE 10000
int H[SIZE]; int f = SIZE, l = SIZE - 1;

//General Method
int isEmpty(){return f > l;}
int front(){if(isEmpty()) return -1; return H[f % SIZE];}
int back(){if(isEmpty()) return -1; return H[l % SIZE];}
int size(){return (l - f + 1) % SIZE;}

//Push Method
void push_front(int x){H[(--f) % SIZE] = x;}
void push_back(int x){H[(++l) % SIZE] = x;}

//Pop Method
int pop_front(){if(isEmpty()) return -1; return H[(f++) % SIZE];}
int pop_back(){if(isEmpty()) return -1; return H[(l--) % SIZE];}

int main(){
    int n; scanf("%d", &n); char str[11];
    for(int i = 0; i < n; i++){
        scanf("%s", str);
        if(strcmp(str, "push_front") == 0){int val; scanf("%d",&val); push_front(val);}
        else if(strcmp(str, "push_back") == 0){int val; scanf("%d", &val); push_back(val);}
        else if(strcmp(str, "pop_front") == 0){printf("%d\n",pop_front());}
        else if(strcmp(str, "pop_back") == 0){printf("%d\n",pop_back());}
        else if(strcmp(str, "front") == 0){printf("%d\n",front());}
        else if(strcmp(str, "back") == 0){printf("%d\n",back());}
        else if(strcmp(str, "size") == 0){printf("%d\n",size());}
        else if(strcmp(str, "empty") == 0){printf("%d\n",isEmpty());}
    }
}