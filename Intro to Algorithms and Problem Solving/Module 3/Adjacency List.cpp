/*
    Graph Representation
    Adjacency List

    0        1
    A ------ B           # total nodes = 4
            / \          # total edge = 4
           /   \         # Undirected + Unweighted
          /     \
       2 C ----- D 3




*/

#include<bits/stdc++.h>
using namespace std;

// Time normal O(E), worst -> O(n ^ 2)
// Space normal O(E), worst -> O(n^2)
int main()
{
    int nodes = 4; // O(1)

    vector <int> adj_list[nodes]; // Array of Vectors O(n^2)

    // O (E * 2) -> O(E) -> O(n^2);
    // If no of Edge is low O(E), then Adjacency list out performs
    // Adjacency Matrix, because AM always needs n * n 2d array.
    adj_list[0] = {1};
    adj_list[1] = {0, 2, 3};
    adj_list[2] = {1, 3};
    adj_list[3] = {1, 2};

    // O(E * 2) -> O(E) -> O(n^2)
    for(int i = 0; i < nodes; i++){
        cout << i << " -> ";
        for(int j = 0; j < adj_list[i].size(); j++){
            cout << adj_list[i][j]<< " ";
        }
        cout << "\n";
    }

    return 0;
}

