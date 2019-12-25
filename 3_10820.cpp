#include <bits/stdc++.h>

using namespace std;

int main(){
    string input;

    while(getline(cin, input)){
        int lower=0, upper=0, space=0, num=0;
        for(int i=0; i<input.size(); i++){
            if(isupper(input[i])){
                upper++;
            }
            else if(islower(input[i])){
                lower++;
            }
            else if(isspace(input[i])){
                space++;
            }
            else if(isdigit(input[i])){
                num++;
            }
        }
        printf("%d %d %d %d\n", lower, upper, num, space);
    }
}