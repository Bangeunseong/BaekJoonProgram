//Separate N Conquer 1629

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
long power(long a, long b, long c){
    a %= c;
    if(b == 0) return 1;
    else if(b == 1) return a;
    else if(b%2 == 0){
        long tmp = power(a,b/2,c);
        return tmp*tmp%c;
    }
    else return a * power(a,b-1,c) % c;
}
int main(){
    long a, b, c; scanf("%ld%ld%ld",&a,&b,&c);
    printf("%ld", power(a,b,c));
}