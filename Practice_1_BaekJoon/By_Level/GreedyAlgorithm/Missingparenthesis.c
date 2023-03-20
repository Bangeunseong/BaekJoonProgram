//Greedy Algorithm 1541

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
int main(){
    char str[51]; scanf("%s",str);
    int Sum = 0;

    int len = strlen(str); int tmp = 0, flag = 0;

    for(int i = 0; i <= len; i++){
        if(str[i] == '\0'){
            if(!flag){Sum += tmp; tmp = 0;}
            else{Sum -= tmp; tmp = 0;}
        }
        else if(str[i] >= '0' && str[i] <= '9'){
            tmp = tmp * 10 + (str[i] - '0');
        }
        else{
            if(str[i] == '+'){
                if(!flag){Sum += tmp;}
                else{Sum -= tmp;}
                tmp = 0;
            }
            else{
                if(!flag)Sum += tmp;
                else Sum -= tmp;
                tmp = 0; flag = 1;
            }
        }
    }
    printf("%d",Sum);
}