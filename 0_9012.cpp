// Stack Prob : 괄호 
#include<bits/stdc++.h>

using namespace std;

bool checked(string str){
    stack<char> st;
    for(int i=0; i<(int)str.length(); i++){
        if(str[i] == '('){
            st.push(str[i]);
        }
        else{
            if(!st.empty()){
                st.pop();
            }
            else{
                return false;
            }
        }
    }

    return st.empty();
}

int main(){
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        if(checked(str)){
            cout << "YES" <<endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}