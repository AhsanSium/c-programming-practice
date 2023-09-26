#include<bits/stdc++.h>
using namespace std;

int main()
{
    deque <int> dq;

    dq.push_back(5);
    dq.push_back(20);
    dq.push_back(30);
    dq.push_back(40);

    cout << dq.size() << "\n";
    cout << "Front Item: " << dq.front() << "\n";


    return 0;
}
