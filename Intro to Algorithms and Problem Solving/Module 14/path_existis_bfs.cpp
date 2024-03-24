#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
int visited[N];
vector <int> adj_list[N];

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

int main()
{
    int node, edges;
    cin >> node >> edges;

    for(int i = 0; i < edges; i++){
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int src = 1, dst = node;

    bfs(src);

    if(visited[dst] == 1){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }

    return 0;
}
