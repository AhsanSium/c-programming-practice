#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 500;


class Queue
{
public:
    int a [MAX_SIZE];
    int l, r;
    int sz;

    Queue()
    {
        l = 0;
        r = -1;
        sz = 0;
    }

    void enqueue(int val)
    {
        if(sz == MAX_SIZE){
            cout << "Queue is Full";
            return;
        }
        r++;

        if(r == MAX_SIZE){
            r = 0;
        }
        a[r] = val;
        sz ++;
    }

    void dequeue ()
    {
        if( sz == 0 ){
            cout << "Queue is Empty";
            return;
        }

        l++;
        if(l == MAX_SIZE){
            l = 0;
        }
        sz --;
    }

    int front_element()
    {
        if(sz == 0){
            cout << "Queue is Empty";
            return 0;
        }
        return a[l];
    }

    int queue_size()
    {
        return sz;
    }



};

int main()
{
    Queue q;
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.dequeue();

    cout << "Queue Size: " <<q.queue_size()<<"\n";
    cout << "Front Element: " <<q.front_element()<<"\n";
    return 0;
}

