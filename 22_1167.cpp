// (v) 뭔가 모자른... dfs.. 컴과사때 풀었었는데;;;
#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > tree[100001];
bool visited[100001];
int diameter = 0;
int farestVertex = 0;

void dfs(int n, int cost){
    int temp = 0, Max = 0;
    visited[n] = true;
    if(diameter < cost){
        farestVertex = n;
        diameter = cost;
    }
    for(int i=0; i<tree[n].size(); i++){
        if(!visited[tree[n][i].first]){
            dfs(tree[n][i].first, cost+tree[n][i].second);
        }
    }
}

int main(){
    int V, input=0, input2=0, vertex;
    scanf("%d", &V);

    for(int i=1; i<=V; i++){
        scanf("%d", &vertex);
        while(1){
            scanf("%d", &input);
            if(input == -1){
                break;
            }
            else{
                scanf("%d", &input2);
                tree[vertex].push_back(make_pair(input, input2));
            }
        }
    }

    dfs(1, 0);
    memset(visited, false, sizeof(visited));
    dfs(farestVertex, 0);

    printf("%d\n", diameter);

}