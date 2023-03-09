//Queue, Deck 1966

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define SIZE 100
int H[SIZE]; int f, l; int volume = 0;
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
int isExist(int key){
    for(int i = f; i <= l; i++) if(H[i%volume] == key) return 1;
    return 0;
}
int main(){
    int n; scanf("%d", &n);
    for(int i = 0; i < n ; i++){
        int k; scanf("%d%d",&volume, &k);
        f = volume; l = volume - 1;

        int max = 0; int exist[9];
        for(int j = 0; j < volume; j++){
            int val; scanf("%d",&val); exist[val - 1] = 1; if(max < val) max = val; push(val);
        }
        
        int cnt = 0, target = H[k];
        for(int j = 9; j >= 1;){
            if(isExist(j)){
                int val = front();
                if(val == j){
                    cnt++;
                    if(k % volume == f % volume && target == val) break;
                    pop();
                }
                else{
                    push(pop());
                }
                if(k % volume == (f - 1) % volume) k = l;
            }
            else j--;
        }
        printf("%d\n",cnt);
    }
}