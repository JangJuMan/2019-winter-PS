// (v) 뭔가 모자른... dfs.. 컴과사때 풀었었는데;;;
// class version
#include <bits/stdc++.h>

using namespace std;

class Tree{
    public:
        int node, distance;
        Tree(int x, int y): node(x), distance(y){}
};

bool visited[100001];
int diameter = 0;
int farestVertex = 0;

void dfs(int n, int cost, vector<Tree> tree[]){
    int temp = 0, Max = 0;
    visited[n] = true;
    if(diameter < cost){
        farestVertex = n;
        diameter = cost;
    }
    for(int i=0; i<tree[n].size(); i++){
        if(!visited[tree[n][i].node]){
            dfs(tree[n][i].node, cost+tree[n][i].distance, tree);
        }
    }
}

int main(){
    int V, input=0, input2=0, vertex;
    scanf("%d", &V);
    vector<Tree> tree[V+1];

    for(int i=1; i<=V; i++){
        scanf("%d", &vertex);
        while(1){
            scanf("%d", &input);
            if(input == -1){
                break;
            }
            else{
                scanf("%d", &input2);
                tree[vertex].push_back(Tree(input, input2));
            }
        }
    }

    dfs(1, 0, tree);
    memset(visited, false, sizeof(visited));
    dfs(farestVertex, 0, tree);

    printf("%d\n", diameter);

}