// (v) : 두려워서...? 이게돼?
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, maxCnt = 1, currCnt = 1;
    cin >> n;
    long long input[n];
    int cnt[n];
    for(int i=0; i<n; i++){
        cin >> input[i];
    }

    sort(input, input+n);

    long long maxV = input[0];
    
    for(int i=1; i<n; i++){
        if(input[i] == input[i-1]){
            currCnt++;
        }
        else{
            currCnt = 1;
        }
        if(maxCnt < currCnt){
            maxV = input[i];
            maxCnt = currCnt;
        }
    }
    cout << maxV;
}