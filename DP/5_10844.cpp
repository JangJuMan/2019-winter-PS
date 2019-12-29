// (v)
// 쉬운계단수 
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    long long DP[101][10], sum = 0;
    DP[1][0] = 0;
    for(int i=1; i<10; i++){
        DP[1][i] = 1;
    }
    for(int i=2; i<=n; i++){
        for(int j=0; j<10; j++){
            if(j == 0){
                DP[i][j] = DP[i-1][j+1] % 1000000000;
            }
            else if(j == 9){
                DP[i][j] = DP[i-1][j-1] % 1000000000;
            }
            else{
                DP[i][j] = (DP[i-1][j-1] + DP[i-1][j+1]) % 1000000000;
            }
        }
    }

    for(int i=0; i<10; i++){
        sum += DP[n][i];
        sum %= 1000000000;
    }

    cout << sum;
}