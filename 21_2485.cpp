// 가로수 몇개 들어갈까 문제
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, curr, prev = 0, gap, Min = INT_MAX, first, end;
    scanf("%d", &n);
    vector<int> distance;
    for(int i=0; i<n; i++){
        scanf("%d", &curr);
        if(i > 0){
            gap = curr - prev;
            distance.push_back(gap);
            if(Min > gap){
                Min = gap;
            }
        }
        if(i == 0){
            first = curr;
        }
        else if(i == n-1){
            end = curr;
        }
        prev = curr;
    }

    for(int i=Min; i>=1; i--){
        int check = 0;
        for(int j=0; j<distance.size(); j++){
            if(distance[j] % i != 0){
                check = 1;
                break;
            }
        }
        if(check == 0){
            gap = i;
            break;
        }
    }

    printf("%d\n", (end-first)/gap - (n-1));
}