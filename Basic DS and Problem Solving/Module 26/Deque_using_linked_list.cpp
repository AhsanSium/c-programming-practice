#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node * prv;
    node * nxt;
};

class Deque
{
public:
    node * head;
    node * tail;
    int sz;

    Deque()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
    }

    node * create_new_node(int value)
    {
        node * newnode = new node;
        newnode->data = value;
        newnode->nxt = NULL;
        newnode->prv = NULL;
        return newnode;
    }

    // push_back O(1)
    void push_back(int value)
    {
        node * newnode = create_new_node(value);

        if(sz == 0){
            head = newnode;
            tail = newnode;
            sz++;
            return;
        }
        tail -> nxt = newnode;
        newnode -> prv = tail;
        tail = newnode;
        sz++;
        return;
    }

    // push_front O(1)
    void push_front(int value)
    {
        node * newnode = create_new_node(value);

        if(sz == 0){
            head = newnode;
            tail = newnode;
            sz++;
            return;
        }
        head -> prv = newnode;
        newnode -> nxt = head;
        head = newnode;
        sz ++;
    }

    // pop_back O(1)
    void pop_back()
    {
        if(sz == 1){
            delete tail;
            head = NULL;
            tail = NULL;
            sz --;
            return;
        }
        if(sz == 0){
            cout << "Deque is Empty! \n";
            return;
        }
        node * newnode = tail;
        tail = tail->prv;
        delete(newnode);
        tail->nxt = NULL;
        sz --;
    }

    // pop_front O(1)
    void pop_front()
    {
        if(sz == 1){
            delete head;
            head = NULL;
            tail = NULL;
            sz --;
            return;
        }
        if(sz == 0){
            cout << "Deque is Empty! \n";
            return;
        }
        node * newnode = head;
        head = head->nxt;
        delete(newnode);
        head->prv = NULL;
        sz --;
    }


    // list items

    void print_items()
    {
        if(sz == 0){
            cout << "Deque is Empty! \n";
            return;
        }
        node * newnode = head;
        while(newnode != NULL){
            cout << newnode->data << " ";
            newnode = newnode -> nxt;
        }
        cout << "\n";
        return;
    }

    int front_item()
    {
        if(sz == 0){
            cout << "Deque is Empty! \n";
            return -1;
        }
        return head->data;
    }

    int tail_item()
    {
        if(sz == 0){
            cout << "Deque is Empty! \n";
            return -1;
        }
        return tail->data;
    }
};

int main()
{
    Deque dq;
    dq.push_back(5);
    dq.push_back(15);
    dq.push_back(20);
    dq.push_back(25);

    dq.print_items();

    dq.pop_back();
    dq.pop_front();

    dq.print_items();

    cout << "Front item " << dq.front_item() << "\n";

    return 0;
}
