// (v) : 집합. Union Find. cin은 느리다.
#include <bits/stdc++.h>

using namespace std;

int* parent;

int findParent(int i){
    if(parent[i] == i){
        return parent[i];
    }
    else{
        return parent[i] = findParent(parent[i]);
    }
}

void unite(int a, int b){
    int x = findParent(a);
    int y = findParent(b);

    parent[x] = y;
}

void print(int n){
    for(int i=0; i<=n; i++){
        printf("%d | ", i);
    }
    cout << endl;
    for(int i=0; i<=n; i++){
        printf("%d | ", parent[i]);
    }
    cout << endl;
}

int main(){
    int n, m, op, a, b;
    cin >> n >> m;
    parent = new int[n+1];
    for(int i=0; i<=n; i++){
        parent[i] = i;
    }
    for(int i=0; i<m; i++){
        // cin >> op >> a >> b; //: 느리다
        scanf("%d %d %d", &op, &a, &b);
        if(op == 0){
            unite(a, b);
        }
        else{
            if(findParent(a) == findParent(b)){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }
        // print(n);
    }

}