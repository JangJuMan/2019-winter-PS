// 벡터로 대충 풀었는데, 알고보니 map 활용문제였음.
#include <bits/stdc++.h>

using namespace std;

// map으로 풀기 (216 ms)
int main(){

    int n;
    scanf("%d", &n);

    map<string, bool> remain;
    vector<string> v;

    for(int i=0; i<n; i++){
        string name, status;
        cin >> name >> status;
        if(remain.count(name)){ //is element(=name) in map(=remain)?
            if(status == "enter"){
                remain[name] = true;
            }
            else{
                remain[name] = false;
            }
        }
        else{
            v.push_back(name);
            remain[name] = true;
        }
    }

    sort(v.begin(), v.end(), greater<string>());

    for(int i=0; i<v.size(); i++){
        if(remain[v[i]] == true){
            cout << v[i] << "\n";
        }
    }
}

// // vector로 풀기 (104 ms)
// int main(){
//     int n;
//     scanf("%d", &n);

//     vector<string> remain, result;
//     string name, status, prev = "";

//     for(int i=0; i<n; i++){
//         cin >> name >> status;
//         remain.push_back(name);
//     }

//     sort(remain.begin(), remain.end(), greater<string>());


//     for(int i=0; i<remain.size(); i++){
//         // cout << remain[i] << " vs " << prev << endl;
//         result.push_back(remain[i]);
//         if(!prev.compare(remain[i])){
//             // cout << ">> " << remain[i] << " same " << prev << endl;
//             result.pop_back();
//             result.pop_back();
//             prev = "";
//         }
//         else{
//             prev = remain[i];
//         }
//     }

//     for(int i=0; i<result.size(); i++){
//         cout << result[i] << "\n";
//     }
// }

