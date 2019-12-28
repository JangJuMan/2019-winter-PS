#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, _max = 0;
    cin >> n;

    int arr[n+1], DP[n+1];
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    DP[0] = 0;
    DP[1] = arr[1];
    DP[2] = DP[1] + arr[2];

    for(int i=3; i<=n; i++){
        DP[i] = max(DP[i-2] + arr[i], DP[i-3] + arr[i-1] + arr[i]);
        DP[i] = max(DP[i], DP[i-1]);
    }
    cout << DP[n];
}