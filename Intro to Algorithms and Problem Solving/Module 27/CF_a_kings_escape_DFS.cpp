#include<bits/stdc++.h>
using namespace std;

const int N = 2002;

int maze[N][N];
int visited[N][N];
int n;

int dx[] = {0, 0, -1, 1, -1, -1, 1, 1};
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};

bool is_inside(pair<int, int> coord)
{
    int x = coord.first;
    int y = coord.second;

    if(x > 0 && x <= n && y > 0 && y <= n){
        return true;
    }
    return false;
}

bool is_forbidden(pair<int, int> coord)
{
    int x = coord.first;
    int y = coord.second;

    if(maze[x][y] == -1 || maze[x][y] == 4){
        return true;
    }
    return false;

}

void dfs (pair <int, int> src)
{
    stack< pair <int, int> > st;
    visited[src.first][src.second] = 1;

    st.push(src);

    while(!st.empty()){
        pair <int, int> head = st.top();
        st.pop();
        int x = head.first;
        int y = head.second;

        for(int i = 0; i < 8; i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            pair <int, int> adj_node = {new_x, new_y};

            // 3 Check
            if(is_inside(adj_node) && !is_forbidden(adj_node) && visited[new_x][new_y] == 0){
                visited[new_x][new_y] = 1;
                st.push(adj_node);

            }
        }
    }
}

int main()
{
    cin >> n;

    pair <int, int> queen, king_src, king_dst;

    cin >> queen.first >> queen.second;
    cin >> king_src.first >> king_src.second;
    cin >> king_dst.first >> king_dst.second;

    for(int i = 0; i <= n + 1; i++){
        for(int j = 0; j <= n+1; j++){
            if( (i == 0 || i == n + 1) || (j == 0 || j == n + 1)){
                maze [i][j] = -1;
            }
        }
    }

    for(int i = 0; i < 8; i++){
        int k = queen.first;
        int l = queen.second;
        for(int j = 1; j < n + 1; j++){
            if(i == 0 && (l > 0 && l <= n) && (k > 0 && k <= n)){
                maze[k][l] = 4;
                k ++;
            }
            if(i == 1 && (l > 0 && l <= n) && (k > 0 && k <= n)){
                maze[k][l] = 4;
                k++;
                l++;
            }
            if(i == 2 && (l > 0 && l <= n) && (k > 0 && k <= n)){
                maze[k][l] = 4;
                l++;
            }
            if(i == 3 && (l > 0 && l <= n) && (k > 0 && k <= n)){
                maze[k][l] = 4;
                k--;
                l++;
            }
            if(i == 4 && (l > 0 && l <= n) && (k > 0 && k <= n)){
                maze[k][l] = 4;
                k--;
            }
            if(i == 5 && (l > 0 && l <= n) && (k > 0 && k <= n)){
                maze[k][l] = 4;
                k--;
                l--;
            }
            if(i == 6 && (l > 0 && l <= n) && (k > 0 && k <= n)){
                maze[k][l] = 4;
                l--;
            }
            if(i == 7 && (l > 0 && l <= n) && (k > 0 && k <= n)){
                maze[k][l] = 4;
                k++;
                l--;
            }
        }
    }

    // maze[queen.first][queen.second] = 5;

//    for(int i = 0; i <= n + 1; i++){
//        for(int j = 0; j <= n + 1; j++){
//            cout << maze[i][j] << "\t";
//        }
//        cout << "\n\n";
//    }

    dfs(king_src);

    if(visited[king_dst.first][king_dst.second] == 1){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }

    return 0;
}

