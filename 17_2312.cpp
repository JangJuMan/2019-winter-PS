// 수 복원하기. 소인수분해
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, input, mod;   
    scanf("%d", &n);

    int prime[100001] = {0};

    for(int i=0; i<n; i++){
        scanf("%d", &input);
        mod = 2;
        while(input != 1){
            // printf("input: %d | mod : %d |\n", input, mod);
            if(input % mod == 0){
                input /= mod;
                prime[mod]++;
            }
            else{
                mod++;
            }
        }
        for(int j=2; j<=mod; j++){
            if(prime[j] > 0){
                printf("%d %d\n", j, prime[j]);
                prime[j] = 0;
            }
        }
    }
}