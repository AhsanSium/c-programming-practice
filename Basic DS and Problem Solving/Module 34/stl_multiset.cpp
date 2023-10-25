#include <bits/stdc++.h>
using namespace std;

int main()
{
    multiset <int> a;

    // Insert O (log(n))
    a.insert(5);
    a.insert(6);
    a.insert(3);
    a.insert(6);
    a.insert(6);
    a.insert(1);
    a.insert(2);
    a.insert(7);
    a.insert(7);
    a.insert(7);
    a.insert(8);

    // Print O(n)
    for(auto it: a)
        cout << it <<" ";
    cout <<"\n";

    cout <<"Size of Multi set " << a.size();

    cout <<"\n";
    // Erase all occurance
    a.erase(6);

    // Erase single occurrence
    a.erase(a.find(7));

    // Print O(n)
    for(auto it: a)
        cout << it <<" ";
    cout <<"\n";

    if(a.find(5) != a.end()){
        cout << "5 exists";
    }
    cout <<"\n";

    if(a.find(4) != a.end()){
        cout << "4 exists";
    }
    else{
        cout << "4 does not exists";
    }
    cout <<"\n";

    return 0;
}

