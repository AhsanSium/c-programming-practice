#include<bits/stdc++.h>
using namespace std;

int main()
{
    int nodes = 4;
    vector< vector <int> >edge_list;

    //               edge1 edge2 weight
    edge_list.push_back({0, 1, 2});
    edge_list.push_back({1, 2, 4});
    edge_list.push_back({1, 3, 9});
    edge_list.push_back({2, 3, 1});

    // time O(E), space O(E)
    for(int i = 0; i < edge_list.size(); i++)
    {
        cout << edge_list[i][0] << " " << edge_list[i][1] << " " <<edge_list[i][2] << endl;

    }

    return 0;
}
