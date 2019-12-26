// (v)
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, i, r, g, b;
    cin >> n;
    int rgb[3][n+1], cost[3][n+1];
    for(i=1; i<=n; i++){
        cin >> rgb[0][i] >> rgb[1][i] >> rgb[2][i];
    }

    cost[0][1] = rgb[0][1];
    cost[1][1] = rgb[1][1];
    cost[2][1] = rgb[2][1];

    for(i=2; i<=n; i++){
        cost[0][i] = min(cost[1][i-1], cost[2][i-1]) + rgb[0][i];
        cost[1][i] = min(cost[0][i-1], cost[2][i-1]) + rgb[1][i];
        cost[2][i] = min(cost[0][i-1], cost[1][i-1]) + rgb[2][i];
    }

    cout << min(cost[0][n], min(cost[1][n], cost[2][n]));

}