//Queue, Deque 1021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996)
#define SIZE 50
int H[SIZE]; int f, l; int volume = 0;

//General Method
int isEmpty(){return f > l;}
int front(){if(isEmpty()) return -1; return H[f % volume];}
int back(){if(isEmpty()) return -1; return H[l % volume];}
int size(){return (l - f + 1) % volume;}

//Push Method
void push_front(int x){H[(--f) % volume] = x;}
void push_back(int x){H[(++l) % volume] = x;}

//Pop Method
int pop_front(){if(isEmpty()) return -1; return H[(f++) % volume];}
int pop_back(){if(isEmpty()) return -1; return H[(l--) % volume];}

//Search Method
int search(int val){
    int i = f;
    while(i <= l) {if(H[i % volume] == val) return i; i++;}
}

int main(){
    int n; scanf("%d%d", &volume, &n);
    f = 2*volume; l = 2*volume - 1;
    for(int i = 1; i <= volume; i++) push_back(i);

    int cnt = 0;
    for(int i = 0; i < n; i++){
        int val; scanf("%d", &val); int in = search(val);
        while(front() != val){
            if(in - f <= l - in){push_back(pop_front()); cnt++;}
            else{push_front(pop_back()); cnt++;}
        }
        pop_front();
    }
    printf("%d", cnt);
}