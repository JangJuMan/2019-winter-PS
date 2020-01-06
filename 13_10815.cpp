#include <bits/stdc++.h>

using namespace std;

int *arr1;

int main(){
    int n, m, curser = 0, input;
    scanf("%d", &n);
    arr1 = new int[n];

    for(int i=0; i<n; i++){
        scanf("%d", &arr1[i]);
    }
    sort(arr1, arr1+n);

    scanf("%d", &m);

    for(int i=0; i<m; i++){
        scanf("%d", &input);
        if(binary_search(arr1, arr1+n, input)){
            printf("1 ");
        }
        else{
            printf("0 ");
        }
    }
}