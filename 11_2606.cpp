#include <bits/stdc++.h>

using namespace std;

int* visited;
int cnt = 0;

void printG(int n, vector<int> graph[]){
    for(int i=1; i<=n; i++){
        printf("%d. ", i);
        for(int j=0; j<graph[i].size(); j++){
            printf(" %d ", graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void dfs(vector<int> g[], int curr){
    // printf("curr : %d | visited[%d] : %d\n", curr, curr, visited[curr]);
    if(visited[curr]){
        return;
    }
    visited[curr] = 1;
    cnt++;
    for(int i=0; i<g[curr].size(); i++){
        dfs(g, g[curr][i]);
    }
}

int main(){
    int n, m, a, b;
    scanf("%d %d", &n, &m);

    vector<int> graph[n+1];
    visited = new int[n+1];

    for(int i=0; i<=n; i++){
        visited[i] = 0;
    }

    for(int i=1; i<=m; i++){
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // printG(n, graph);

    dfs(graph, 1);

    printf("%d", cnt-1);

}