// (v) 수 정렬하기 3 : 메모리 조심 
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, input;
    cin >> n;
    int number[10001];

    memset(number, 0, sizeof(number));

    for(int i=0; i<n; i++){
        scanf("%d", &input);
        number[input]++;
    }

    for(int i=1; i<=10000; i++){
        for(int j=0; j<number[i]; j++){
            printf("%d\n", i);
        }
    }
    return 0;
}