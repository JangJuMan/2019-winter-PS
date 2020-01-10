// 펙토리얼 뒤의 0의 개수
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, cnt = 0;
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        int temp = i;
        if(temp % 5 == 0){
            while(temp % 5 == 0){
                cnt++;
                temp /= 5;
            }
        }
    }

    printf("%d\n", cnt);
}