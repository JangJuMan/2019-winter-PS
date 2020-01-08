// 그냥 맨땅에 부딪히는 느낌.. (prime check가 생각해보니 필요가 없음)
#include <bits/stdc++.h>

using namespace std;

int main(){
    int input, n, i=2, cnt = 0, check = 0;
    scanf("%d", &n);
    input = n;

    int isPrime[n+1] = {0};

    while(n != 1){
        if(n % i == 0){
            n /= i;
            printf("%d\n", i);
        }
        else{
            i++;
        }
    }

}