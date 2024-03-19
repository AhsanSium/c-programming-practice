#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int visited[N];

vector<int>adj_list[N];

void bfs(int src)
{
    queue <int> q;

    visited[src] = 1;
    q.push(src);

    while(!q.empty()){
        int head = q.front();
        q.pop();

        for(int adj_node: adj_list[head]){
            if(visited[adj_node] == 0){
                visited[adj_node] = 1;
                q.push(adj_node);
            }
        }
    }
}

/*


# of node -> 5
# of edge -> 3

list of adj_nodes ->
// node edge
5 3

0 1
1 2
2 0

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

    int components = 0;
    for(int i = 0; i < nodes; i++){
        if(visited[i] == 0){
            int src = 0;
            bfs(src);
            components ++;
        }
    }

    cout << components << "\n";

    return 0;
}
