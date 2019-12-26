#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, i, j, _max=0;
    cin >> n;
    int input[n+1][n+1], result[n+1][n+1];
    for(i=1; i<=n; i++){
        for(j=1; j<=i; j++){
            cin >> input[i][j];
            result[i][j] = 0;
        }
    }

    result[1][1] = input[1][1];
    for(i=2; i<=n; i++){
        for(j=1; j<=i; j++){
            result[i][j] += max(result[i-1][(j-1 < 1) ? 1 : j-1], result[i-1][(j == i) ? j-1 : j]) + input[i][j];
            if(i == n){
                if(_max < result[i][j]){
                    _max = result[i][j];
                }
            }
        }
    }

    cout << _max;
}