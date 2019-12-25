#include <bits/stdc++.h>

using namespace std;

int main(){
    long long P[101], k, n;
    P[1] = 1;
    P[2] = 1;
    P[3] = 1;
    P[4] = 2;
    P[5] = 2;
    P[6] = 3;
    P[7] = 4;
    P[8] = 5;
    P[9] = 7;
    P[10] = 9;

    cin >> k;
    int i = 11;
    for(int j=0; j<k; j++){
        cin >> n;
        for(; i<=n; i++){
            P[i] = P[i-1] + P[i-5];
        }
        printf("%lld\n", P[n]);

    }

}