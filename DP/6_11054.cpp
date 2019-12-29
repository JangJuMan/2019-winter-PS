// (v)
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, input, back = 0, storeSize = 0, _max = 0;
    cin >> n;
    vector<int> store;
    vector<int>::iterator iter;
    int left[n], right[n], data[n];


    for(int i=0; i<n; i++){
        cin >> input;
        data[i] = input;
    }


    for(int i=0; i<n; i++){
        if(back < data[i]){
            store.push_back(data[i]);
            left[i] = ++storeSize;
        }
        else{
            iter = lower_bound(store.begin(), store.end(), data[i]);
            store[iter - store.begin()] = data[i];
            left[i] = iter - store.begin() + 1;
        }
        back = store.back();
    }
    store.clear();
    back = 0;
    storeSize = 0;

    for(int i=n-1; i>=0; i--){
        if(back < data[i]){
            store.push_back(data[i]);
            right[i] = ++storeSize;
        }
        else{
            iter = lower_bound(store.begin(), store.end(), data[i]);
            store[iter - store.begin()] = data[i];
            right[i] = iter - store.begin() + 1;
        }
        back = store.back();
    }

    for(int i=0; i<n; i++){
        if(_max < left[i] + right[i]){
            _max = left[i] + right[i];
        }
    }

    cout << _max - 1;
}