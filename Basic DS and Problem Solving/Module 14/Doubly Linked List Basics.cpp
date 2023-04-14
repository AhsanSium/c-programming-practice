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

    // Get Size of Doubly Linked List
    int GetSize()
    {
        cout << sz <<"\n";
        return sz;
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

    return 0;
}
