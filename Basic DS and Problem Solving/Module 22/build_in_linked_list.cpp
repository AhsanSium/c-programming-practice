#include <bits/stdc++.h>
using namespace std;

void print(list <int> l);

void insert_list(list<int>&l, int idx, int value);

void delete_from_list(list <int> &l, int idx);

int main()
{
    list <int> l;
    // O(1) maintains head
    l.push_front(10);
    l.push_front(20);
    l.push_front(30);

    //O(1) Maintains tail
    l.push_back(50);
    l.push_back(50);

    // O(1) delete back element
    l.pop_back();

    // O(1)
    l.pop_front();

    //O(n)
    print(l);

    //O(n)
    insert_list(l, 2, 80);

    print(l);

    //O(n)
    delete_from_list(l, 2);

    print(l);

    return 0;
}

void print(list <int> l)
{
    // a points to LL head
    // list <int> :: iterator a = l.begin();
    // Auto detects the data-type after =
    auto a = l.begin();

    while(a != l.end()){
        cout << *a << " ";
        a++;
    }
    cout <<"\n";
}

void insert_list(list<int>&l, int idx, int value)
{
    // list <int> :: iterator it = l.begin();
    auto it = l.begin(); // O(1)
    advance(it, idx); // O(idx)
    l.insert(it, value);
}

void delete_from_list(list <int> &l, int idx)
{
    auto it = l.begin();
    advance(it, idx);
    l.erase(it);
}
