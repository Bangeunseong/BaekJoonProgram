#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* s) {
    char* answer = NULL; int len = strlen(s);
    if(len % 2 == 0){answer = (char*)malloc(sizeof(char)*3); answer[2] = '\0';}
    else{answer = (char*)malloc(sizeof(char)*2); answer[1] = '\0';}
    
    int i = 0, j = len - 1;
    while(i < j){i++; j--;}
    if(i == j) answer[0] = s[i];
    else {answer[0] = s[j]; answer[1] = s[i];}
    
    return answer;
}
int main(){
    char str[101]; scanf("%s",str);
    printf("%s",solution(str));
}