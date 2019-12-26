// (v)
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, three, two, one;
    cin >> n;
    int DP[n+1];
    DP[1] = 0;
    DP[2] = 1;
    DP[3] = 1;
    for(int i=4; i<=n; i++){
        three = two = one = INT_MAX;
        if(i % 3 == 0){
            three = DP[i/3] + 1;
        }
        if(i % 2 == 0){
            two = DP[i/2] + 1;
        }
        one = DP[i-1] + 1;
        DP[i] = min(three, min(two, one));
    }

    cout << DP[n];
}