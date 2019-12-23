#include <bits/stdc++.h>

using namespace std;

int main(){
    char curr, prev;
    int nowV = 0, accumV = 0, cut = 0, result = 0;

    while(scanf("%c",&curr) != EOF){
        if(curr == '('){
            accumV++;
        }
        else if(curr == ')'){
            accumV--;
            if(prev == '('){ // this is 절단선
                cut = 1;
            }
            else{
                nowV++;
            }
        }
        // printf("prev : %c | curr : %c | accumV : %d | nowV : %d | result : %d | cut : %d\n", prev, curr, accumV, nowV, result, cut);
        if(cut){
            result += nowV + accumV;
            nowV = 0;
            cut = 0;
        }
        prev = curr;
    }
    result += nowV + accumV;

    // printf("%d %d %d\n", result, nowV, accumV);
    printf("%d", result);
}