#include<bits/stdc++.h>
using namespace std;

int main()
{
    queue <int> q;

    // Enqueue O(1)
    q.push(5);
    q.push(10);
    q.push(15);
    q.push(20);
    q.push(25);

    // Front O(1)
    cout << "Front Element: " << q.front() <<"\n";

    // Size
    cout << "Size: " << q.size() <<"\n";

    // Dequeue O(1)
    q.pop();

    cout <<"Front Element: " << q.front() <<"\n";


    return 0;
}
