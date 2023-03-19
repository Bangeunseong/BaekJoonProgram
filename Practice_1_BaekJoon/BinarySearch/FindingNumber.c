//BinarySearch 1920 Failed

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define SIZE 100000

long H[SIZE]; int n = 0;
long x[SIZE];
void upHeap(int last){
    if(last == 1) return;
    if(H[last] < H[last/2]) return;
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
int Search(int first, int last, int val){
    if(first > last) return 0;

    int in = (first + last)/2;
    if(x[in] == val) return 1;
    else if(x[in] < val) return Search(in + 1, last, val);
    else return Search(first, in - 1, val);
}
int main(){
    int w, k;

    scanf("%d",&w);
    for (int i = 0; i < w; i++) {long key; scanf("%ld", &key); insertItem(key); }
	for(int i = 0; i < w; i++){x[w - i - 1] = removeMax();}

    /*for(int i = 0 ; i < w; i++) printf("%ld ", x[i]);
    printf("\n");*/

	scanf("%d",&k);
    for(int i = 0; i < k; i++) {
        long val; scanf("%ld",&val);
        printf("%d\n", Search(0, w - 1, val));
    }
}