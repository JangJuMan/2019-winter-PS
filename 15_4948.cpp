#include <bits/stdc++.h>

#define din(a) scanf("%d", &a)
#define printd(a) printf("%d\n", a);

using namespace std;

bool isPrime[246913] = {0};
bool primeCheck(int n){
    for(int i=2; i<= sqrt(n); i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int n, result;
    
    for(int i=2; i<=246912; i++){
        if(primeCheck(i)){
            isPrime[i] = true;
        }
    }

    while(1){
        result = 0;
        din(n);
        if(n == 0){
            break;
        }
        for(int i=n+1; i<=2*n; i++){
            if(isPrime[i]){
                result++;
            }
        }
        printd(result);
    }
}