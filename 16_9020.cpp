// 골드바흐의 추측. n = l(소수) + r(소수)로 쓸 수 있다.
#include <bits/stdc++.h>

#define din(a) scanf("%d", &a)
#define printd(a, b) printf("%d %d\n", a, b)

using namespace std;

bool isPrime[10001] = {0};

bool primeCheck(int n){
    for(int i=2; i<= sqrt(n); i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
void goldPartition(int n){
    int l, r;
    if(n % 2 == 0){
        l = r = n/2;
    }
    else{
        l = n/2;
        r = n/2 + 1;
    }
    for(int i=0; i<n/2; i++){
        if(isPrime[l] && isPrime[r]){
            printd(l, r);
            break;
        }
        else{
            l--;
            r++;
        }
    }
}

int main(){
    int n, input;
    din(n);

    for(int i=2; i<10001; i++){
        if(primeCheck(i)){
            isPrime[i] = true;
        }
    }

    for(int i=0; i<n; i++){
        din(input);
        goldPartition(input);
    }
}