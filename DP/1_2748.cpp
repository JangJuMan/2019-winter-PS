// Fibonacci Prob I DP
#include <bits/stdc++.h>

using namespace std;

int main(){
    long long fibo[91];
    int n;

    fibo[0] = 0;
    fibo[1] = 1;
    for(int i=2; i<=90; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    cin >> n;

    printf("%lld", fibo[n]);
}