#include<bits/stdc++.h>
using namespace std;

/*

5 8

########
#..#...#
####.#.#
#..#...#
########

# -> -1
. -> 0

(x, y) -> right (x, y+1)
       -> left (x, y-1)
       -> up (x - 1, y)
       -> down (x + 1, y)

While there exists an empty cell
    -find an empty unvisited cell
    -run bfs() from that cell

x  y
-  -        dx[] = {0, 0, -1, 1}
0  1        dy[] = {1, -1, 0, 0}
0  -1       for(int i = 0; i < 4; i++){
-1  0           int new_x = x + dx[i];
1  0            int nex_y = y + dy[i];
            }
*/

const int N = 2002;

int maze[N][N];
int visited[N][N];
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

    if(maze[x][y] == -1){
        return true;
    }
    return false;

}

void bfs (pair <int, int> src)
{
    queue< pair <int, int> > q;
    visited[src.first][src.second] = 1;

    q.push(src);

    while(!q.empty()){
        pair <int, int> head = q.front();
        q.pop();
        int x = head.first;
        int y = head.second;

        for(int i = 0; i < 4; i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            pair <int, int> adj_node = {new_x, new_y};

            // 3 Check
            if(is_inside(adj_node) && !is_forbidden(adj_node) && visited[new_x][new_y] == 0){
                visited[new_x][new_y] = 1;
                q.push(adj_node);
            }
        }
    }
}

pair <int, int> find_unvisited()
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(visited[i][j] == 0 && maze[i][j] == 0){
                return {i, j};
            }
        }
    }

    return {-1, -1};
}

int main()
{
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        string input;
        cin >> input;

        for(int j = 0; j < m; j++){
            if(input[j] == '#'){
                maze[i][j] = -1;
            }
        }
    }

//    for(int i = 0; i < n; i++){
//        for(int j = 0; j < m; j++){
//            cout << maze[i][j] << "\t";
//        }
//        cout << "\n";
//    }


    // bfs(src);

    int room_count = 0;

    while(true){
        pair <int, int> unvisited_pos = find_unvisited();
        if(unvisited_pos == pair<int, int>(-1, -1)){
            break;
        }
        else{
            bfs(unvisited_pos);
            room_count ++;
        }
    }

    cout << "Room Count: " << room_count << "\n";

    return 0;
}
