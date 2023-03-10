//Queue, Deque 5430

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define SIZE 100000
int H[SIZE]; int f = SIZE, l = SIZE - 1, flag = 0;

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

//Parsing to Integer array
void parseToInt(char *str, int m){
    if(m == 0) return;

    int tmp = 0; int len = strlen(str);
    for(int i = 1; i < len; i++){
        if(str[i] >= '0' && str[i] <= '9'){tmp = tmp * 10 + (str[i] - '0');}
        else{push_back(tmp); tmp = 0;}
    }
}

//Delete Method
int Delete(){
    if(flag == 0) return pop_front();
    return pop_back();
}

//Print Method
void Print(){
    printf("[");
    if(!flag){
        for(int i = f; i <= l; i++){
            printf("%d",H[i%SIZE]);
            if(i != l) printf(",");
        }
    }
    else{
        for(int i = l; i >= f; i--){
            printf("%d",H[i%SIZE]);
            if(i != f) printf(",");
        }
    }
    printf("]\n");
}

//Operation Method
int Operation(char *str){
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        if(str[i] == 'R'){
            if(flag != 0) flag = 0;
            else flag = 1;
        }
        else if(str[i] == 'D') {
            if(Delete() == -1) return 0;
        }
    }
    return 1;
}

int main(){
    int n, m; scanf("%d", &n); char str[100001]; char arr[1200000];
    for(int i = 0; i < n; i++){
        f = SIZE; l = SIZE - 1; flag = 0;
        scanf("%s",str); scanf("%d", &m); scanf("%s", arr);
        parseToInt(arr, m);
        if(Operation(str)) Print();
        else printf("error\n");
    }
}