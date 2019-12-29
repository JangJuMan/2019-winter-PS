// 접미사 배열 
#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<string> st;
    string input;
    cin >> input;

    int len = input.length();

    for(int i=0; i<input.length(); i++){
        st.push_back(input.substr(i, len--));
    }

    sort(st.begin(), st.end());

    for(int i=0; i<st.size(); i++){
        cout << st[i] << "\n";
    }
}