#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node * nxt;
};

class Queue
{
public:
    node * head;
    node * tail;
    int sz;

    Queue()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
    }

    node * CreateNode(int value)
    {
        node * newnode = new node;
        newnode->data = value;
        newnode->nxt = NULL;
        return newnode;
    }

    void enqueue(int value)
    {
        node * newnode = CreateNode(value);

        if(head == NULL){
            head = newnode;
            tail = newnode;
        }
        tail->nxt = newnode;
        tail = newnode;
        sz ++;
    }

    void dequeue()
    {
        if(sz == 0){
            cout <<"Queue is Empty \n";
            return;
        }

        if(sz == 1){
            delete head;
            head = NULL;
            tail = NULL;
            sz --;
            return;
        }

        node * a = head;
        head = head -> nxt;
        delete a;
        sz --;
        return;
    }

    int front_element()
    {
        if(sz == 0){
            cout <<"Queue Empty! \n";
        }

        return head->data;
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
    q.enqueue(15);
    q.enqueue(25);
    q.enqueue(35);

    cout << "Queue Front = " << q.front_element()<<"\n";
    cout << "Queue Size = " << q.queue_size()<<"\n";

    q.dequeue();

    cout << "Queue Size = " << q.queue_size()<<"\n";
    cout << "Queue Front = " << q.front_element()<<"\n";

    return 0;
}
