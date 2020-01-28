// (v) : LCA & typedef pair<int, int>
#include <bits/stdc++.h>

#define MAX_NODE 40001
#define swap(a, b){int t = a; a = b; b = t;}

using namespace std;

// depth : 노드의 깊이(레벨)
// ac[x][y] : x의 2^y번째 조상 
int depth[MAX_NODE];
int ac[MAX_NODE][20];
int max_level;

// root(1) 에서 x까지의 거리
long long dist[MAX_NODE];

typedef pair<int, int> pii;
vector<pii> graph[MAX_NODE];

// DP(ac)배열 만드는 과정
void getTree(int here, int parent, int val){
    // here의 깊이는 부모노드 깊이 + 1
    depth[here] = depth[parent] + 1;

    // here이 1인 경우에는 dist[1] = 0
    // 그 외의 경우에는 root에서 자신의 부모와의 거리 + 자신의 부모와 자신과의 거리.
    if(here == 1){
        dist[here] = 0;
    }
    else{
        dist[here] = dist[parent] + val;
    }

    // here의 1번째 조상은 부모노드.
    ac[here][0] = parent;

    // MAX_NODE에 log2를 씌어 내림을 해준다.
    max_level = (int)floor(log2(MAX_NODE));

    for(int i = 1; i <= max_level; i++){
        // tmp : here의 2^(i-1)번째 조상
        int tmp = ac[here][i-1];
        ac[here][i] = ac[tmp][i-1];
        // printf("%d(i), %d(tmp), %d(here), ac[tmp][i-1] : %d\n", i, tmp, here, ac[tmp][i-1]);
    }

    // dfs
    for(int i=0; i<graph[here].size(); i++){
        int there = graph[here][i].first;
        if(there != parent){
            getTree(there, here, graph[here][i].second);
        }
    }
}

int main(){
    int n, m;
    scanf("%d", & n);

    // tree 생성.
    for(int i=1; i<n; i++){
        int from, to, val;
        scanf("%d %d %d", &from, &to, &val);
        graph[from].push_back(pii(to, val));
        graph[to].push_back(pii(from, val));
        // graph[to].push_back(pair<int, int>(to, val));   // 위에꺼랑 같은말 아님!!!!!!!! (개고생했네)
    }

    // make_tree에 1, 0이 들어가기 때문에 0은 -1로 지정.
    depth[0] = -1;

    // 루트 노드인 1번 노드부터 트리 형성.
    getTree(1, 0, 0);

    scanf("%d", &m);

    while(m--){
        int a, b;
        scanf("%d %d", &a, &b);

        // tempA와 tempB는 a와 b의 원래 모습을 가지고 있는다.
        int tempA = a;
        int tempB = b;

        // depth가 다르면 같게하라
        if(depth[a] != depth[b]){
            // depth[b] >= depth[a]가 되도록 swap
            if(depth[a] > depth[b]){
                swap(a, b);
            }

            // b를 올려서 depth를 맞춰준다.
            int j = 0;
            for(int i = max_level; i >= 0; i--){
                if(depth[a] <= depth[ac[b][i]]){
                    b = ac[b][i];
                }
            }
        }

        int lca = a;

        if(a != b){
            for(int i = max_level; i >= 0; i--){
                if(ac[a][i] != ac[b][i]){
                    a = ac[a][i];
                    b = ac[b][i];
                }
                lca = ac[a][i];
            }
        }
        // 루트노드와 tempA와의 거리 - 루트노드와 lca 와의 거리
        //                                          +
        // 루트노드와 tempB와의 거리 - 루트노드와 lca 와의 거리
        // -------------------------------------------
        printf("%lld\n", dist[tempA] + dist[tempB] - 2*dist[lca]);
    }

    return 0;
}




// // T.L... dfs version failed...
// int N, M;
// bool isVisited[40001] = {0};
// bool done = false;

// class Tree{
//     public:
//     int node, distance;
//     Tree(int x, int y): node(x), distance(y){}
// };

// int dfs(int start, int end, vector<Tree> t[], int accum, int col){
//     if(isVisited[start]){
//         return 0;
//     }
//     // printf("(%d, %d, t, %d, %d) \n>> return : %d\n\n", start, end, accum, col, accum+t[start][col].distance);
//     if(start == end){
//         done = true;
//         return accum;
//     }
//     int ans = 0;
//     isVisited[start] = true;
//     for(int i=0; i<t[start].size(); i++){
//         ans = dfs(t[start][i].node, end, t, accum + t[start][i].distance, i);
//         if(done){
//             return ans;
//         }
//     }
//     return ans;
// }

// void print(vector<Tree> t[]){
//     for(int i=1; i<= N; i++){
//         printf("%d : ", i);
//         for(int j=0; j< t[i].size(); j++){
//             printf("(%d | %d)\t", t[i][j].node, t[i][j].distance);
//         }
//         printf("\n");
//     }
// }

// int main(){
//     int vertex, a, b;
//     scanf("%d", &N);
//     vector<Tree> tree[N+1];
//     for(int i=1; i<N; i++){
//         scanf("%d %d %d", &vertex, &a, &b);
//         tree[vertex].push_back(Tree(a, b));
//         tree[a].push_back(Tree(vertex, b));
//     }
//     // print(tree);

//     scanf("%d", &M);
//     for(int i=1; i<=M; i++){
//         scanf("%d %d", &a, &b);
//         printf("%d\n", dfs(a, b, tree, 0, 0));
//         memset(isVisited, 0, sizeof(isVisited));
//         done = false;
//     }

// }