#include <bits/stdc++.h>

using namespace std;

int main(){
    string text;
    int n, curser = 0, len;
    char op, ch;
    cin >> text;
    cin >> n;
    curser = len = text.length() - 1;

    for(int i = 0; i < n; i++){
	cin >> op;
	if(op == 'L'){
	    curser = (curser - 1 >= 0) ? curser - 1 : 0;
	}
	else if(op == 'D'){
	    curser  = (curser + 1 <= len) ? curser + 1 : len;
	}
	else if(op == 'B'){

	}
	else if(op == 'P'){
	    cin >> ch;
	}	
    }    
    
    cout << text;
    return 0;
}
