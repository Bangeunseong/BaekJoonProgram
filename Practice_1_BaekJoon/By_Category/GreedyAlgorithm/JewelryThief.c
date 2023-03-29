//GreedyAlgorithm 1202 Efficiency Problem

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define SIZE 300000

typedef struct Jewel{
    int mass, value;
}Jewel;

int compareJewel(const void *p, const void *q){
    Jewel x = *(const Jewel *)p;
    Jewel y = *(const Jewel *)q;
    
    if(x.mass == y.mass) return (x.value > y.value) - (x.value < y.value);
    else return (x.mass > y.mass) - (x.mass < y.mass);
}

int compareJewel_value(const void *p, const void *q){
    Jewel x = *(const Jewel *)p;
    Jewel y = *(const Jewel *)q;
    return (x.value > y.value) - (x.value < y.value);
}

int compareBag(const void *p, const void *q){
    long x = *(const long *)p;
    long y = *(const long *)q;
    return (x > y) - (x < y);
}

Jewel j_list[SIZE]; long w_list[SIZE]; int n, k;
Jewel stack[SIZE]; int top = -1;

int isEmpty(){return top == -1;}
void push(Jewel val){
    stack[++top] = val;
}
Jewel pop(){return stack[top--];}

int main(){
    scanf("%d%d",&n,&k);
    for(int i = 0; i < n; i++){scanf("%d%d",&j_list[i].mass,&j_list[i].value);}
    qsort(j_list, n, sizeof(*j_list), compareJewel);
    for(int i = 0; i < k; i++){scanf("%ld",&w_list[i]);}
    qsort(w_list, k, sizeof(*w_list), compareBag);

    //for(int i = 0; i < n; i++) printf("%d %d\n",j_list[i].mass,j_list[i].value);
    //for(int i = 0; i < k; i++) printf("%d\n",w_list[i]);
    
    long long result = 0; int ind = 0;
    for(int i = 0; i < k; i++){
        while(ind < n && j_list[ind].mass <= w_list[i]){
            push(j_list[ind++]);
        }
        qsort(stack, top + 1, sizeof(*stack),compareJewel_value);
        if(!isEmpty()){
            Jewel j = pop();
            result += j.value;
        }
    }
    printf("%lld", result);
}