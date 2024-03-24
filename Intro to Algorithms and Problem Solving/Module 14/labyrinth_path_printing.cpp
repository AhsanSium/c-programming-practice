#include<bits/stdc++.h>
using namespace std;

/*

5 8

########
#.A#...#
#.##.#B#
#......#
########

# -> -1
. -> 0

(x, y) -> right (x, y+1)
       -> left (x, y-1)
       -> up (x - 1, y)
       -> down (x + 1, y)
check,
1. is the cell within maze
2. is the cell forbidden/wall
3. is the cell visited

x  y
-  -        dx[] = {0, 0, -1, 1}
0  1        dy[] = {1, -1, 0, 0}
0  -1       for(int i = 0; i < 4; i++){
-1  0           int new_x = x + dx[i];
1  0            int nex_y = y + dy[i];
            }
00 01 02

10 11 12

20 21 22

*/

const int N = 2002;

int maze[N][N];
int level[N][N];
pair <int, int> parent[N][N];
vector <pair <int, int>> path;
int visited[N][N];
int n, m;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool is_inside(pair<int, int> coord)
{
    int x = coord.first;
    int y = coord.second;

    if(x >= 1 && x <= n && y >= 1 && y <= m){
        return true;
    }
    return false;
}

bool is_forbidden(pair<int, int> coord)
{
    int x = coord.first;
    int y = coord.second;

    if(maze[x][y] == -2 || maze[x][y] == -1 || maze[x][y] == -3){
        return true;
    }
    return false;

}

bool is_monster(pair<int, int> coord, int cycle)
{
    for(int j = 0; j < cycle; j++){

        for(int i = 0; i < 4; i++){
            int new_x = coord.first + dx[i];
            int new_y = coord.second + dy[i];

            if(maze[new_x][new_y] == -3){
                return true;
            }
        }
    }


     return false;

//     if(maze[new_x][new_y] == -3){
//        return true;
//     }
//
//     return false;
}

pair <int, int> bfs (pair <int, int> src)
{
    queue< pair <int, int> > q;

    pair <int, int> found = {-3, -3};

    int cycle = 1;

    // pair <int, int> found = src;

    visited[src.first][src.second] = 1;
    level[src.first][src.second] = 0;
    parent[src.first][src.second] = {-4, -4};
    // cout << "SRC Node: "<< maze[src.first][src.second] <<"\n";

    if(n < 2){
        bool is_src_monster = is_monster(src, cycle);
        if(is_src_monster){
            pair <int, int> monster = {-3, -3};
            return monster;
        }

        for(int i = 0; i < 4; i++){
            int src_adj_x = src.first + dx[i];
            int src_adj_y = src.second + dy[i];

            if(maze[src_adj_x][src_adj_y] == 0){
                found.first = src_adj_x;
                found.second = src_adj_y;
                return found;
            }
        }
    }

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

            // bool is_adj_monster = is_monster(adj_node);



            // 3 Check
            if(is_inside(adj_node) && !is_forbidden(adj_node) && visited[new_x][new_y] == 0 && is_monster(adj_node, cycle)){

//                if(is_adj_monster){
//                    pair <int, int> monster = {-3, -3};
//                    return monster;
//                }

                visited[new_x][new_y] = 1;
                level[new_x][new_y] = level[x][y] + 1;
                parent[adj_node.first][adj_node.second] = head;
                q.push(adj_node);

                // cout << "Node: "<< maze[adj_node.first][adj_node.second] <<"\n";

                for(int i = 0; i < 4; i++){

                    int new_adj_x = new_x + dx[i];
                    int new_adj_y = new_y + dy[i];

                    // cout << "Inside: "<< maze[new_adj_x][new_adj_y] <<"\n";

//                    if(maze[new_adj_x][new_adj_y] == -3){
//                        pair <int, int> monster = {-3, -3};
//                        return monster;
//                    }

                    if(maze[new_adj_x][new_adj_y] == 0){
                        found.first = adj_node.first;
                        found.second = adj_node.second;

                        // cout << "Found at : "<< new_adj_x << new_adj_y <<" \n";

                        return found;
                    }

                }
                cycle ++;
            }
        }
    }

    return found;
}

int main()
{
    cin >> n >> m;

    pair <int, int> src, dst;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            level[i][j] = -1;
        }
    }

    for(int i = 0; i < n; i++){
        string input;
        cin >> input;

        for(int j = 0; j < m; j++){
            if(input[j] == '#'){
                maze[i+1][j+1] = -2;
            }
            else if(input[j] == 'M'){
                maze[i+1][j+1] = -3;
            }
            else if(input[j] == 'A'){
                maze[i+1][j+1] = 2;
                src = {i+1, j+1};
            }
            else if(input[j] == '.'){
                maze[i+1][j+1] = 1;
            }
        }
    }

//    for(int i = 0; i <= n+1; i++){
//        for(int j = 0; j <= m+1; j++){
//            cout << maze[i][j] << "\t";
//        }
//        cout << "\n";
//    }

    dst = bfs(src);

    // cout << dst.first << " " << dst.second << "\n";

    if(dst.first == -3 && dst.second == -3){
        cout << "NO\n";
        return 0;
    }
    else{
        cout << "YES\n";
        cout << level[dst.first][dst.second] << "\n";
    }

    pair <int, int> selected = dst;
    vector <char> c_path;

    while(true && level[dst.first][dst.second] > 0){
        path.push_back(selected);
        if(selected.first == src.first && selected.second == src.second){
                break;
        }
        pair <int, int> tmp = parent[selected.first][selected.second];
        /*
            (x, y) -> right (x, y+1)
           -> left (x, y-1)
           -> up (x - 1, y)
           -> down (x + 1, y)
        */
        if(selected.first == tmp.first && selected.second == tmp.second - 1){
            c_path.push_back('L');
        }
        else if(selected.first == tmp.first && selected.second == tmp.second + 1){
            c_path.push_back('R');
        }
        else if(selected.first == tmp.first - 1 && selected.second == tmp.second){
            c_path.push_back('U');
        }
        else{
            c_path.push_back('D');
        }


        selected = parent[selected.first][selected.second];
    }

    reverse(c_path.begin(), c_path.end());

    for(auto node: c_path){
        cout << node;
    }
    cout << "\n";

    return 0;
}

