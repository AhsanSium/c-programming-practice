#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue <int> pq;

    // O(log n )
    pq.push(10);
    pq.push(8);
    pq.push(12);
    pq.push(4);
    pq.push(5);
    pq.push(3);

    while(pq.size() != 0){
        //top O(1)
        cout << pq.top() << " ";

        // O(log n)
        pq.pop();
    }
    cout << "\n";

    return 0;
}
