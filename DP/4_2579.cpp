// (v)
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n+1], stair[n+1];
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    stair[0] = 0;
    stair[1] = arr[1];
    stair[2] = stair[1] + arr[2];
    for(int i=3; i<=n; i++){
        stair[i] = max(stair[i-2] + arr[i], stair[i-3] + arr[i-1] + arr[i]);
    }
    cout << stair[n];
}