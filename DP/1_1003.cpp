// Fibonacci Prob II DP
#include <bits/stdc++.h>

using namespace std;

int main(){
    long long zero[41], one[41];
    int n, input;

    zero[0] = 1;
    zero[1] = 0;
    one[0] = 0;
    one[1] = 1;

    for (int i = 2; i <= 40; i++)
    {
        zero[i] = zero[i - 1] + zero[i - 2];
        one[i] = one[i-1] + one[i-2];
    }
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> input;
        printf("%lld %lld\n", zero[input], one[input]);
    }
}