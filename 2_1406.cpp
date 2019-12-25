#include <bits/stdc++.h>

using namespace std;

// stack으로 짜보기 : 112ms
int main(){
	string input;
	stack<char> l, r;
	cin >> input;

	int n;
	cin >> n;

	for(int i=0; i<input.length(); i++){
		l.push(input[i]);
	}

	char op, ch;
	for(int i=0; i<n; i++){
		cin >> op;
		if(op == 'L'){
			if(!l.empty()){
				r.push(l.top());
				l.pop();
			}
		}
		else if(op == 'D'){
			if(!r.empty()){
				l.push(r.top());
				r.pop();
			}
		}
		else if(op == 'B'){
			if(!l.empty()){
				l.pop();
			}
		}
		else if(op == 'P'){
			cin >> ch;
			l.push(ch);
		}
	}

	while(!l.empty()){
		r.push(l.top());
		l.pop();
	}

	while(!r.empty()){
		cout << r.top();
		r.pop();
	}
}




// // list로 짜보기 : 148ms
// int main(){
// 	string input;
// 	cin >> input;

// 	list<char> text(input.begin(), input.end());

// 	int n;
// 	list<char>::iterator curser = text.end();
// 	char op, ch;
// 	cin >> n;
// 	for(int i=0; i<n; i++){
// 		cin >> op;
// 		if(op == 'L'){
// 			if(curser != text.begin()){
// 				curser--;
// 			}
// 		}
// 		else if(op == 'D'){
// 			if(curser != text.end()){
// 				curser++;
// 			}
// 		}
// 		else if(op == 'B'){
// 			if(curser != text.begin()){
// 				curser--;
// 				text.erase(curser++);
// 			}
// 		}
// 		else if(op == 'P'){
// 			cin >> ch;
// 			text.insert(curser, ch);
// 		}
// 	}
// 	for(auto &x : text){
// 		cout << x;
// 	}
// 	return 0;
// }


// // vector : TIMEOUT
// void print(list<char> t, int len){
//    for (auto &x : t)
//    {
//       cout << x;
//    }
// }

// int main(){
//     string text;
//    list<char> text_2;
//     int n, curser = 0, len, B;
//     char op, ch;
//     cin >> text;
//     cin >> n;
//     curser = len = text.length();
//    for(int i=0; i<=len; i++){
//       text_2.push_back(text[i]);
//    }

//     for(int i = 0; i < n; i++){
//       // printf(">> len : %d\n", len);
//       // print(text_2, len);
//       cin >> op;
//       if(op == 'L'){
//          curser = (curser - 1 >= 0) ? curser - 1 : 0;
//       }
//       else if(op == 'D'){
//          curser  = (curser + 1 < len) ? curser + 1 : len - 1;
//       }
//       else if(op == 'B'){
//          if(curser - 1 >= 0){
//             curser -= 1;
//             text_2.erase(text_2.begin() + curser);
//             len--;
//          }
//       }
//       else if(op == 'P'){
//          cin >> ch;
//          text_2.insert(text_2.begin() + curser++, ch);
//          len++;
//       }
//     }
//     print(text_2, len);
//     // print(text_2, len);
//     return 0;
// }