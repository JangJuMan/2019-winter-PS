// Combination(n, k) = n! / (k! * (n-k)!) : 0의 개수
#include<bits/stdc++.h>

using namespace std;

int HowManyZero_Five(int n){
    int five_cnt = n/5;
    int temp = n/5;
    while(temp/5 != 0){
        temp /= 5;
        five_cnt += temp;
    }
    return five_cnt;
}

int HowManyZero_Two(int n){
    int two_cnt = n/2;
    int temp = n/2;
    while(temp/2 != 0){
        temp /= 2;
        two_cnt += temp;
    }
    return two_cnt;
}

int main(){
    int n, m;
    int result;

    scanf("%d %d", &n, &m);

    result = min(HowManyZero_Five(n) - HowManyZero_Five(m) - HowManyZero_Five(n-m),
                    HowManyZero_Two(n) - HowManyZero_Two(m) - HowManyZero_Two(n-m));

    printf("%d\n", result);
}