#include<bits/stdc++.h>
using namespace std;

const int N = 1001;
int visited[N][N];
int cell[N][N];
int n, m;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool is_inside(pair<int, int> coord)
{
    int x = coord.first;
    int y = coord.second;

    if(x >= 0 && x < n && y >= 0 && y < m){
        return true;
    }
    return false;
}

bool is_forbidden(pair<int, int> coord)
{
    int x = coord.first;
    int y = coord.second;

    if(cell[x][y] == -1 || cell[x][y] == 0){
        return true;
    }
    return false;

}

int bfs (int i, int j)
{
    queue< pair <int, int> > q;
    visited[i][j] = 1;
    pair <int, int> src(i, j);
    q.push(src);
    int total = cell[i][j];

    while(!q.empty()){
        // cout << "BFS 1\n";
        pair <int, int> head = q.front();
        q.pop();
        int x = head.first;
        int y = head.second;

        for(int i = 0; i < 4; i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            pair <int, int> adj_node = {new_x, new_y};

            // 3 Check
            if(is_inside(adj_node) && !is_forbidden(adj_node) && visited[new_x][new_y] == -1){
                //cout << "BFS 2 \n";
                visited[new_x][new_y] = 1;
                total = total + cell[new_x][new_y];
                q.push(adj_node);
            }
        }
    }

    return total;
}

int main()
{
    int t;
    cin >> t;
    while(t > 0){
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> cell[i][j];
                visited[i][j] = -1;
            }
        }

        int max_lake = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(visited[i][j] == -1 && cell[i][j] != 0){
                    // cout << bfs(i, j) << " ";
                    max_lake = max(max_lake, bfs(i, j));
                }
            }
        }

        cout << max_lake << "\n";

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                visited[i][j] = -1;
                cell[i][j] = 0;
            }
        }
        t--;
    }
    return 0;
}
