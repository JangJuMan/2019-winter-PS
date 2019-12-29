// ROT13 : 암호화 
#include <bits/stdc++.h>

using namespace std;

int main(){
    string text;
    getline(cin, text);

    for(int i=0; i<text.length(); i++){
        if(isupper(text[i])){

            text[i] = (text[i] + 13 > 90) ? 'A' - 1 + (text[i] + 13) % 90 : text[i] + 13;
        }
        else if(islower(text[i])){
            text[i] = (text[i] + 13 > 122) ? 'a' - 1 + (text[i] + 13) % 122 : text[i] + 13;
        }
    }

    cout << text;
}