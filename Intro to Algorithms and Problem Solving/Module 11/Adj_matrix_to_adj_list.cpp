#include<bits/stdc++.h>
using namespace std;

int main()
{
    int nodes;
    cin >> nodes;
    int matrix[nodes][nodes] = {};
    vector <int> adj_list[nodes];

    for(int i = 0; i < nodes; i++){
        for(int j = 0; j < nodes; j++){
            int input;
            cin >> input;
            matrix[i][j] = input;
        }
    }

    for(int i = 0; i < nodes; i++){
        for(int j = 0; j < nodes; j++){
            if(matrix[i][j] == 1){
                adj_list[i].push_back(j);
            }
        }
    }

    for(int i = 0; i < nodes; i++){
        cout << i << ": ";
        for(int j = 0; j < adj_list[i].size(); j++){
            cout << adj_list[i][j]<< " ";
        }
        cout << "\n";
    }

    return 0;
}
