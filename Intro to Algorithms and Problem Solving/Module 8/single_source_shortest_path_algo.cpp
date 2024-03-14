#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int visited[N];
int level[N];

vector<int>adj_list[N];

void bfs(int src)
{
    queue <int> q;

    visited[src] = 1;
    level[src] = 0;
    q.push(src);

    while(!q.empty()){
        int head = q.front();
        q.pop();

        // cout << head << endl;

        for(int adj_node: adj_list[head]){
            if(visited[adj_node] == 0){
                visited[adj_node] = 1;
                level[adj_node] = level[head] + 1; // level added
                q.push(adj_node);
            }
        }
    }
}

/*

0 ---- 1 ---- 2 ---- 3
       |      |
       |      |
       5 ---- 4

Output -> 0 1 5 2 4 3


# of node -> 6
# of edge -> 6

list of adj_nodes ->

// node edge
6 6

0 1
2 3
1 5
2 4
5 4
1 2

*/

int main()
{

    int nodes, edges;

    cin >> nodes >> edges;

    for(int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int src = 0;

    bfs(src);

    for(int i = 0; i < nodes; i++){
        cout << "Node " << i << " -> level: " << level[i] << endl;
    }

    return 0;
}

