// (v) string[n] 이런식은 안되나? 
// 출력할때 string을 %s로 출력하면 이상해;;; cout 해야 돼;;
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, ans = 0;
    cin >> n >> m;
    vector<string> input_a;
    vector<string> result;
    string temp;

    input_a.resize(n);
    for(int i=0; i<n; i++){
        cin >> input_a[i];
    }

    sort(input_a.begin(), input_a.end());

    for(int i=0; i<m; i++){
        cin >> temp;
        if(binary_search(input_a.begin(), input_a.end(), temp)){
            result.push_back(temp);
            ans++;
        }
    }

    sort(result.begin(), result.end());

    cout << ans << endl;
    for(int i=0; i<result.size(); i++){
        cout << result[i] << endl;
    }
}