//PriorityQueue 11286

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define SIZE 100001

long H[SIZE]; int n = 0;

int isEmpty(){return n == 0;}
void upHeap(int last){
    if(last == 1) return;
    if(abs(H[last]) > abs(H[last/2])) return;
    if(abs(H[last]) == abs(H[last/2]) && H[last] > H[last/2]) return;
    long tmp = H[last]; H[last] = H[last/2]; H[last/2] = tmp;
    upHeap(last/2);
}
void insertItem(long key){
    H[++n] = key;
    upHeap(n);
}
void downHeap(int root) {
	if(n == 1) return;
	if(root >= n) return;
	int smaller = 2 * root;
    if(smaller > n) return;
	if(2 * root + 1 <= n) {
		if(abs(H[smaller]) >= abs(H[2 * root + 1])) {
            if(abs(H[smaller]) == abs(H[2 * root + 1])){
                if(H[smaller] > H[2 * root + 1]) smaller = 2 * root + 1;
            }
            else smaller = 2 * root + 1;
        }
	}
	if(abs(H[root]) < abs(H[smaller])) return;
    if(abs(H[root]) == abs(H[smaller]) && H[root] < H[smaller]) return;
	long tmp = H[smaller]; H[smaller] = H[root]; H[root] = tmp;
	downHeap(smaller);
}
long removeMin() {
    if(isEmpty()) return 0;
	long key = H[1];
	H[1] = H[n--];
	downHeap(1);
	return key;
}

int main(){
    int m; scanf("%d",&m);
    for(int i = 0; i < m; i++){
        long val; scanf("%ld",&val);
        if(!val) printf("%ld\n",removeMin());
        else insertItem(val);
    }
}