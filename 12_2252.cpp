// (v)
#include <bits/stdc++.h>

using namespace std;


// priority와 queue, BFS를 이용한 풀이
void bfs(vector<int> g[], int n, int priority[]){
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(!priority[i]){
            q.push(i);
        }
    }

    while(!q.empty()){
        int nowV = q.front();
        q.pop();
        printf("%d ", nowV);

        for(int i=0; i<g[nowV].size(); i++){
            if(--priority[g[nowV][i]] == 0){
                q.push(g[nowV][i]);
            }
        }
    }
}

int main(){
    int n, m, a, b;
    cin >> n >> m;
    int priority[n+1] = {0};
    vector<int> g[n+1];

    for(int i=0; i<m; i++){
        cin >> a >> b;
        priority[b]++;
        g[a].push_back(b);
    }

    bfs(g, n, priority);
}


// // vector를 이용해서 graph 만들어서 구현해봤는데 틀렸습니다;; 왜징..
// int* visited;
// vector<int> st;

// void dfs(vector<int> adj[], int n){
//     if(visited[n] == 1){
//         return;
//     }
//     visited[n] = 1;
//     if(n != 0){
//         st.push_back(n);
//     }
//     for(int i=0; i<adj[n].size(); i++){
//         dfs(adj, adj[n][i]);
//     }
// }

// int main(){
//     int n, m, a, b;
//     cin >> n >> m;
//     vector<int> adj_list[n+1];
//     int isFirst[n+1] = {0};
//     visited = new int[n+1];


//     for(int i=0; i<m; i++){
//         cin >> a >> b;
//         isFirst[a] = 1;
//         adj_list[b].push_back(a);
//     }

//     for(int i=1; i<=n; i++){
//         visited[i] = 0;
//         if(!isFirst[i]){
//             adj_list[0].push_back(i);
//         }
//     }

//     dfs(adj_list, 0);

//     for(int i=st.size()-1; i>=0; i--){
//         printf("%d ", st[i]);
//     }
// }