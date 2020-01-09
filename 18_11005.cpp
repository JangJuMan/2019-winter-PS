// 진법 변환
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, b, mod_n;
    scanf("%d %d", &n, &b);
    vector<char> mod;

    while(1){
        mod_n = n % b;
        if(n >= b){
            n /= b;
            if(mod_n >= 10){
                mod_n += 'A' - 10;
            }
            else{
                mod_n += '0';
            }
            mod.push_back(mod_n);
        }
        else{
            if(n >= 10){
                n += 'A' - 10;
            }
            else{
                n += '0';
            }
            mod.push_back(n);
            break;
        }
    }

    for(int i=mod.size()-1; i>=0; i--){
        printf("%c", mod[i]);
    }


}