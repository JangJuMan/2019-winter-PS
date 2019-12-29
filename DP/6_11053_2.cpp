#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, input, back = 0, storeSize = 0, _max = 0; 
    cin >> n;
    int LIS[n];
    vector<int> store;
    vector<int>::iterator iter;

    for(int i=0; i<n; i++){
        cin >> input;
        if(back < input){
            store.push_back(input);
            LIS[i] = ++storeSize;
        }
        else{
            iter = lower_bound(store.begin(), store.end(), input);
            store[iter - store.begin()] = input;
            LIS[i] = iter - store.begin() + 1;
        }
        if(_max < LIS[i]){
            _max = LIS[i];
        }
        back = store.back();
    }

    cout << _max;
}