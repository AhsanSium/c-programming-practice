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
    int rev;

    Deque()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
        rev = 0;
    }

    node * create_new_node(int value)
    {
        node * newnode = new node;
        newnode->data = value;
        newnode->nxt = NULL;
        newnode->prv = NULL;
        return newnode;
    }

    void insert_at_tail(int value)
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

    // push_back O(1)
    void push_back(int value)
    {
        if(rev == 0){
            insert_at_tail(value);
        }
        else{
            insert_at_head(value);
        }
    }

    void insert_at_head(int value)
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

    // push_front O(1)
    void push_front(int value)
    {
        if(rev == 0){
            insert_at_head(value);
        }
        else{
            insert_at_tail(value);
        }
    }

    void delete_tail()
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

    // pop_back O(1)
    void pop_back()
    {
        if(rev == 0){
            delete_tail();
        }
        else{
            delete_head();
        }
    }

    void delete_head()
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

    // pop_front O(1)
    void pop_front()
    {
        if(rev == 0){
            delete_head();
        }
        else{
            delete_tail();
        }

    }


    // list items

    void print_items()
    {
        if(sz == 0){
            cout << "Deque is Empty! \n";
            return;
        }
        if(rev == 0){
            node * newnode = head;
            while(newnode != NULL){
                cout << newnode->data << " ";
                newnode = newnode -> nxt;
            }
            cout << "\n";
            return;
        }
        else{
            node * newnode = tail;
            while(newnode != NULL){
                cout << newnode->data << " ";
                newnode = newnode -> prv;
            }
            cout << "\n";
            return;
        }

    }

    int front_item()
    {
        if(sz == 0){
            cout << "Deque is Empty! \n";
            return -1;
        }
        if(rev == 0){
           return head->data;
        }
        else{
            return tail->data;
        }

    }

    int back_item()
    {
        if(sz == 0){
            cout << "Deque is Empty! \n";
            return -1;
        }
        if(rev == 0){
           return tail->data;
        }
        else{
            return head->data;
        }
    }

    // Reverse Operation O(1)
    void reverse_deque()
    {
        cout <<"Deque Reversed \n";
        rev = rev == 0 ? 1 : 0;
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
    cout << "Front item " << dq.front_item() << "\n";

    //dq.pop_back();
    //dq.pop_front();

    //dq.print_items();

    //cout << "Front item " << dq.front_item() << "\n";

    dq.reverse_deque();

    //cout << "Front item " << dq.front_item() << "\n";

    //dq.push_back(5);
    //dq.push_back(15);
    //dq.push_back(20);
    //dq.push_back(25);

    dq.print_items();
    cout << "Front item " << dq.front_item() << "\n";
    cout << "Back item " << dq.back_item() << "\n";

    return 0;
}

