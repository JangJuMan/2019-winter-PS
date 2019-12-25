#include <bits/stdc++.h>

using namespace std;

int main(){
    queue<int> q, ans;
    int n, k, len = 0, temp, i=1;
    cin >> n >> k;

    for(int i=1; i<=n; i++){
        q.push(i);
    }

    cout << "<";
    while(q.size()){
        if(q.size() == 1){
            cout << q.front() << ">";
            q.pop();
            break;
        }
        for(int i=1; i<k; i++){
            
            q.push(q.front());
            q.pop();
        }
        ans.push(q.front());
        cout << q.front() << ", ";
        q.pop();
    }


    // 채점서버가 인식 ㄴㄴ
    // cout << "<";
    // while(!ans.empty()){
    //     cout << ans.front() << ", ";
    //     ans.pop();
    // }
    // cout << "\b\b>\n";
}