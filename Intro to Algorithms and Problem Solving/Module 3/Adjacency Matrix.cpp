/*
    Graph Representation
    Adjacency Matrix

    0        1
    A ------ B           # total nodes = 4
            / \          # total edge = 4
           /   \         # Undirected + Unweighted
          /     \
       2 C ----- D 3
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int nodes = 4; // O(1)
    int matrix[nodes][nodes] = {}; // Space Complexity O(n^2)

    /*
    for(int i = 0; i < nodes; i++){
        for(int j = 0; j < nodes; j++){
            matrix[i][j] = 0;
        }
    }
    */

    // O(n^2)
    for(int i = 0; i < nodes; i++){
        for(int j = 0; j < nodes; j++){
            // matrix[i][j] = 0;
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n\n";

    // O(E) E -> no of edge
    // maximum no of edge in a graph - n^2
    // Time complexity worst case O(n^2)

    matrix[0][1] = 1;
    matrix[1][0] = 1;

    matrix[1][2] = 1;
    matrix[2][1] = 1;

    matrix[2][3] = 1;
    matrix[3][2] = 1;

    matrix[3][1] = 1;
    matrix[3][3] = 1;

    // O(n^2)
    for(int i = 0; i < nodes; i++){
        for(int j = 0; j < nodes; j++){
            // matrix[i][j] = 0;
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
