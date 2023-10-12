#include<bits/stdc++.h>
using namespace std;

template <class T>
class node
{
public:
    T data;
    node * prv;
    node * nxt;
};

template <class T>
class Deque
{
public:
    node <T> * head;
    node <T> * tail;
    int sz;

    Deque()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
    }

    node <T> * create_new_node(T value)
    {
        node<T> * newnode = new node<T>;
        newnode->data = value;
        newnode->nxt = NULL;
        newnode->prv = NULL;
        return newnode;
    }

    // push_back O(1)
    void push_back(T value)
    {
        node<T> * newnode = create_new_node(value);

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
    void push_front(T value)
    {
        node <T> * newnode = create_new_node(value);

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
        node <T> * newnode = tail;
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
        node <T> * newnode = head;
        head = head->nxt;
        delete(newnode);
        head->prv = NULL;
        sz --;
    }


    // list items O(n)
    void print_items()
    {
        if(sz == 0){
            cout << "Deque is Empty! \n";
            return;
        }
        node <T> * newnode = head;
        while(newnode != NULL){
            cout << newnode->data << " ";
            newnode = newnode -> nxt;
        }
        cout << "\n";
        return;
    }

    // Front Item O(1)
    T head_item()
    {
        if(sz == 0){
            cout << "Deque is Empty!, Returning garbage value: ";
            T a;
            return a;
        }
        return head->data;
    }

    // Back Item O(1)
    T tail_item()
    {
        if(sz == 0){
            cout << "Deque is Empty!, Returning garbage value: ";
            T a;
            return a;
        }
        return tail->data;
    }
};

int main()
{
    Deque <char> dq;
    dq.push_back('A');
    dq.push_back('B');
    dq.push_back('C');
    dq.push_back('D');

    dq.print_items();

    dq.pop_back();
    dq.pop_front();
    dq.push_front('X');

    dq.print_items();

    cout << "Front item " << dq.head_item() << "\n";
    cout << "Back item " << dq.tail_item() << "\n";

    dq.pop_back();
    dq.pop_back();
    dq.pop_front();

    cout << "Front item " << dq.head_item() << "\n";

    return 0;
}

