#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, input;
    cin >> n;

    vector<int> LIS;
    LIS.push_back(1000);

    for(int i=0; i<n; i++){
        cin >> input;
        if(LIS.back() < input){
            LIS.push_back(input);
        }
        else{
            for(int j=0; j<LIS.size(); j++){
                if(LIS[j] >= input){
                    LIS[j] = input;
                    break;
                }
            }
        }
    }

    cout << LIS.size();
}