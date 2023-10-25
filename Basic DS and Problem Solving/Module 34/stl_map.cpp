#include<bits/stdc++.h>
using namespace std;

int main()
{
    map <string, int> mp;

    // Key must be distinct but value can be duplicate
    // Insert O (log n)
    // Map stores lexicographically sorted
    mp["map1"] = 1;
    mp["map2"] = 2;
    mp["map3"] = 9;
    mp["map4"] = 8;

    // Value of a key O (log n)
    cout << mp["map3"]<<"\n";

    mp["map3"] = 11;

    cout << mp["map3"]<<"\n";

    // Print the map O(n)
    for(auto it:mp)
        cout << "Key : " << it.first <<" , value : "<< it.second<<"\n";

    //cout << "\n";

    // O(1)
    cout << "Size of Map: "<<mp.size()<<"\n";

    map <int, int> mp2;

    mp2[69] = 1;
    mp2[57] = 5;
    mp2[89] = 5;
    mp2[1000000] = 155;

    for(auto it:mp2)
        cout << "Key : " << it.first <<" , value : "<< it.second<<"\n";


    return 0;
}

