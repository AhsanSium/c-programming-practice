#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 500;


class Queue
{
public:
    int *a;
    int array_cap;
    int l, r;
    int sz;

    Queue()
    {
        a = new int[1];
        array_cap = 1;
        l = 0;
        r = -1;
        sz = 0;
    }

    void remove_circular()
    {
        if(l > r){
            int *tmp = new int [array_cap];
            int idx = 0;
            for(int i = l; i < array_cap; i++){
                tmp[idx] = a[i];
                idx ++;
            }
            for(int i = 0; i <= r; i++){
                tmp[idx] = a[i];
                idx++;
            }
            swap(tmp, a);
        }
    }

    void increase_size()
    {
        remove_circular();
        sz = sz * 2;
    }

    void enqueue(int val)
    {
        if(sz == array_cap){
            increase_size();
        }
        r++;

        if(r == array_cap){
            r = 0;
        }
        a[r] = val;
        sz ++;
    }

    void dequeue ()
    {
        if( sz == 0 ){
            increase_size();
        }

        l++;
        if(l == array_cap){
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

