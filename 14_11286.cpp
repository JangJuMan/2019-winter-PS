// (v) using priority_queue
#include <bits/stdc++.h>

#define din(a) scanf("%d", &a)
#define chin(a) scanf("%c", &a)
#define prtD(a) printf("%d\n", a)

using namespace std;

int main(){
    int n, input, result;
    din(n);
    priority_queue<int> minusPQ, plusPQ;

    for(int i=0; i<n; i++){
        din(input);
        if(input == 0){
            if(!plusPQ.empty() && minusPQ.empty()){
                result = -plusPQ.top();
                plusPQ.pop();
            }
            else if(plusPQ.empty() && !minusPQ.empty()){
                result = minusPQ.top();
                minusPQ.pop();
            }
            else if(!plusPQ.empty() && !minusPQ.empty()){
                if(plusPQ.top() > minusPQ.top()){
                    result = -plusPQ.top();
                    plusPQ.pop();
                }
                else{
                    result = minusPQ.top();
                    minusPQ.pop();
                }
            }
            else{
                result = 0;
            }
            prtD(result);
        }
        else if(input > 0){
            plusPQ.push(-input);
        }
        else if(input < 0){
            minusPQ.push(input);
        }
    }
}