#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 500;


class Queue
{
public:
    int a [MAX_SIZE];
    int l, r;

    Queue()
    {
        l = 0;
        r = -1;
    }

    void enqueue(int val)
    {
        if(r + 1 >= MAX_SIZE){
            cout << "Queue is Full";
            return;
        }
        r++;
        a[r] = val;
    }

    void dequeue ()
    {
        if( l > r){
            cout << "Queue is Empty";
            return;
        }
        l++;
    }

    int front_element()
    {
        if(l > r){
            cout << "Queue is Empty";
            return 0;
        }
        return a[l];
    }

    int queue_size()
    {
        return r - l + 1;
    }



};

int main()
{
    Queue q;
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);

    cout << "Front Element: " <<q.front_element();
    return 0;
}
