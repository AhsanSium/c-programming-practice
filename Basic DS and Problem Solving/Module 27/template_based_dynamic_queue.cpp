#include <bits/stdc++.h>
using namespace std;

template < class T >
class Queue
{
public:
    T *a;
    int array_cap;
    int l, r;
    int sz;

    Queue()
    {
        a = new T[1];
        array_cap = 1;
        l = 0;
        r = -1;
        sz = 0;
    }

    void remove_circular()
    {
        if(l>r){
            T *tmp = new T[array_cap];
            int idx = 0;
            for(int i=l; i<array_cap; i++)
            {
                tmp[idx] = a[i];
                idx++;
            }
            for(int i=0;i<=r;i++)
            {
                tmp[idx] = a[i];
                idx++;
            }
            swap(tmp,a);
            l = 0;
            r = array_cap -1;
            delete [] tmp;
        }
    }

    void increase_size()
    {
        remove_circular();
        // size increase

        T *tmp = new T[array_cap*2];

        for(int i=0;i<array_cap;i++){
            tmp[i] = a[i];
        }

        swap(a,tmp);

        array_cap = array_cap * 2;

        delete [] tmp;
    }

    void enqueue(T val)
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

    void dequeue()
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

    T front_element()
    {
        if(sz == 0){
            cout << "Empty Queue! ";
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
    Queue <char> q;
    cout << "Queue Size: " <<q.queue_size()<<"\n";
    cout << "Front Element: " <<q.front_element()<<"\n";
    q.enqueue('A');
    q.enqueue('B');
    q.enqueue('C');
    q.enqueue('D');

    cout << "Front Element: " <<q.front_element()<<"\n";
    cout << "Queue Size: " <<q.queue_size()<<"\n";
    q.dequeue();
    cout << "Queue Size: " <<q.queue_size()<<"\n";

    cout << "Front Element: " <<q.front_element()<<"\n";
    return 0;
}

