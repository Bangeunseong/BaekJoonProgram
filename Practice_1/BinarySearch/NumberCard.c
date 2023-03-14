//BinarySearch 10816

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define SIZE 500001

long H[SIZE]; int n = 0; int w, k;
long x[SIZE];

void upHeap(int last){
    if(last == 1) return;
    if(H[last] < H[last/2]) return;
    long tmp = H[last]; H[last] = H[last/2]; H[last/2] = tmp;
    upHeap(last/2);
}
void insertItem(long key){
    if(n >= 500000) return;
    H[++n] = key;
    upHeap(n);
}

void downHeap(int root) {
	if(n == 1) return;
	if(root >= n) return;
	int bigger = 2 * root;
    if(bigger > n) return;
	if(2 * root + 1 <= n) {
		if (H[bigger] < H[2 * root + 1]) bigger = 2 * root + 1;
	}
	if (H[root] > H[bigger]) return;
	long tmp = H[bigger]; H[bigger] = H[root]; H[root] = tmp;
	downHeap(bigger);
}
long removeMax() {
	long key = H[1];
	H[1] = H[n--];
	downHeap(1);
	return key;
}

int lowerBound(int first, int last, long val){
    if(x[first] == val && first == 0) return first;
    int in = (first + last)/2;
    if(x[in] == val){
        if(x[in - 1] != val) return in;
        else return lowerBound(first, in - 1, val);
    }
    else if(x[in] < val) return lowerBound(in + 1, last, val);
}
int upperBound(int first, int last, long val){
    if(x[last] == val && last == w - 1) return last;
    int in = (first + last)/2;
    if(x[in] == val){
        if(x[in + 1] != val) return in;
        else return upperBound(in + 1, last, val);
    }
    else if(x[in] > val) return upperBound(first, in - 1, val);
}

int Search(int first, int last, long val){
    if(first > last) return -1;

    int in = (first + last)/2;
    if(x[in] == val) return in;
    else if(x[in] < val) return Search(in + 1, last, val);
    else return Search(first, in - 1, val);
}
int CountOfNumber(long val){
    int in = Search(0, w - 1, val);
    if(in == -1) return 0;

    return upperBound(in, w - 1, val) - lowerBound(0, in, val) + 1;
}

int main(){
    scanf("%d",&w);
    for(int i = 0; i < w; i++){long val; scanf("%ld",&val); insertItem(val);}
    for(int i = 0; i < w; i++){x[w - 1 - i] = removeMax();}

    scanf("%d",&k);
    for(int i = 0; i < k; i++){
        long val; scanf("%ld",&val);
        printf("%d ",CountOfNumber(val));
    }    
}