// Fibonacci Prob III DP
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    // int* fibo;
    cin >> n;
    int fibo[n+1];
    // fibo = new int[n+1]; //Dynamic 

    fibo[0] = 0;
    fibo[1] = 1;
    fibo[2] = 2;

    for(int i=3; i<=n; i++){
        fibo[i] = (fibo[i-1] + fibo[i-2]) % 15746;
    }

    printf("%d", fibo[n]);
}