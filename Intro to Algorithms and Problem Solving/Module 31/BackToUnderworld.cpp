#include<bits/stdc++.h>
using namespace std;

const int N = 20009;
int visited[N];
int color[N];
vector <int> adj_list[N];
/*
adj_list[1] -> 2, 4, 5

1 -- 2
1 -- 4
1 -- 5

*/

long long int bfs(int x)
{
    long long int lykan_num = 0, vampire_num = 0;

    queue<int>q;
    q.push(x);

    visited[x] = 1;
    color[x] = 1;
    ++lykan_num;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i = 0; i < adj_list[u].size(); i++)
        {
            int v = adj_list[u][i];
            if(visited[v] == 0)
            {
                q.push(v);
                visited[v] = 1;

                if(color[u] == 1) //assigning type to each node.
                {
                    color[v] = 0;
                    ++vampire_num;
                }
                else
                {
                    color[v] = 1;
                    ++lykan_num;
                }
            }
        }
    }

    long long int mx = max(vampire_num,lykan_num);

    return mx;
}

void clear_all()
{
    memset(visited,0,sizeof (visited));
    memset(color,0,sizeof (color));
    for(int i=0; i<20009; i++)
        adj_list[i].clear();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    cin >> t;
    int cs = 1;
    while(t --){
        clear_all();
        long long int ans = 0;
        cin >> n;
        int u, v;
        for(int i = 0; i < n; i++){
            cin >> u >> v;
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }

        for(int i = 0; i < N; i++){
            if(visited[i] == 0 && !adj_list[i].empty()){
                ans = ans + bfs(i);
            }
        }

        cout << "Case " << cs << ": " << ans << "\n";
        cs++;
    }

    return 0;
}

