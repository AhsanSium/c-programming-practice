#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node * nxt;
    node * prv;
};

class DoublyLinkedList
{
public:
    node * head;
    int sz;

    DoublyLinkedList()
    {
        head = NULL;
        sz = 0;
    }

    // Creates a new node next = null, previous = null
    node * CreateNewNode(int data)
    {
        node * newNode = new node;
        newNode->data = data;
        newNode->nxt = NULL;
        newNode->prv = NULL;

        return newNode;
    }

    // Insert a node at head with given data
    void InsertAtHead(int data)
    {
        node * newNode = CreateNewNode(data);
        if(head == NULL){
            head = newNode;
            sz++;
            return;
        }
        node * a = head;
        newNode->nxt = a;
        a->prv = newNode;
        head = newNode;
        sz++;
        return;
    }

    // Insert at any position in Doubly Linked List O(n)
    void Insert(int index, int data)
    {   if(index < 0 || index > sz){
            return;
        }
        else if(index == 0){InsertAtHead(data); return;}
        else{
            node * a = head;
            int cur_index = 0;
            while(cur_index != index - 1){
                a = a->nxt;
                cur_index++;
            }
            // a = cur_index - 1
            node * newNode =  CreateNewNode(data);
            newNode->nxt = a->nxt;
            newNode->prv = a;
            node * b = a->nxt;
            b->prv = newNode;
            a->nxt = newNode;
            sz++;
            return;
            }
    }


    // Traverse Linked List
    void Traverse()
    {
        node * a = head;
        while(a != NULL){
            cout << a->data << " ";
            a = a->nxt;
        }
        cout << "\n";
    }
    // Doubly Linked List Reverse O(2*n) = O(n)
    void Reverse()
    {
        if(head == NULL) return;
        node * a = head;
        int cur_index = 0;
        while(cur_index != sz -1){
            a = a->nxt;
            cur_index++;
        }
        // Latest index is in a
        node * b = head;
        while(b != NULL){
            swap(b->nxt, b->prv);
            b = b->prv;
        }
        head = a;
        return;
    }

    // Get Size of Doubly Linked List
    int GetSize()
    {
        cout << sz <<"\n";
        return sz;
    }

    // Delete specific index Node on Doubly Linked List O(n)
    void Delete(int index)
    {
        if(index >= sz){ cout <<"Wrong Index \n"; return; }
        node * a = head;
        int cur_index = 0;
        while(cur_index != index){
            a = a->nxt;
            cur_index++;
        }
        node * b = a->prv;
        node * c = a->nxt;

        if(b != NULL){ b->nxt = c; }
        if(c != NULL){ c->prv = b; }
        delete a;
        if(index == 0){ head = c; }
        sz--;
        return;
    }
};


int main()
{
    DoublyLinkedList dl;

    dl.InsertAtHead(5);
    dl.InsertAtHead(10);
    dl.InsertAtHead(22);
    dl.InsertAtHead(38);
    dl.InsertAtHead(40);

    dl.Traverse();

    dl.Insert(2, 100);
    dl.Traverse();

    dl.Delete(2);
    dl.Traverse();
    dl.GetSize();

    dl.Reverse();
    dl.Traverse();
    return 0;
}
