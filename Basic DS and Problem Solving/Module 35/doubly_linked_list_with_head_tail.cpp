#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node * nxt;
    Node * prv;
};

class LinkedList
{
public:
    Node * head;
    Node * tail;
    int sz;

    LinkedList()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
    }

    // Creates a new node next = null, previous = null
    Node * CreateNewNode(int value)
    {
        Node * newNode = new Node;
        newNode->value = value;
        newNode->nxt = NULL;
        newNode->prv = NULL;

        return newNode;
    }

    // Insert a node at head with given value at O(1)
    void insertHead(int value)
    {
        Node * newNode = CreateNewNode(value);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            sz++;
            return;
        }
        Node * a = head;
        newNode->nxt = a;
        a->prv = newNode;
        head = newNode;
        sz++;
        return;
    }

    // Insert a node at tail with given value at O(1)
    void insertTail(int value)
    {
        Node * newNode = CreateNewNode(value);
        if(tail == NULL){
            head = newNode;
            tail = newNode;
            sz++;
            return;
        }
        Node * a = tail;
        newNode->prv = a;
        a->nxt = newNode;
        tail = newNode;
        sz++;
        return;
    }

    // Insert a node at mid with given value at O(n)
    void insertMid(int value)
    {
        if(sz < 2){
            cout << "Cannot insert mid, less than 2 nodes found.\n";
            return;
        }

        int mid = sz / 2;

        Node * a = head;
        int cur_index = 0;
        while(cur_index < mid - 1){
            a = a->nxt;
            cur_index++;
        }

        Node * newNode =  CreateNewNode(value);
        newNode->nxt = a->nxt;
        newNode->prv = a;
        Node * b = a->nxt;
        b->prv = newNode;
        a->nxt = newNode;
        sz++;
        return;

    }

    // Print Linked List O(n)
    void print()
    {
        Node * a = head;
        while(a != NULL){
            cout << a->value << " ";
            a = a->nxt;
        }
        cout << "\n";
    }

    // Works at O(1)
    void Merge(LinkedList a)
	{
	    if(head == NULL || a.head == NULL || a.tail == NULL){return;}
		//Merge a at the back of this linked-list
		Node * t = tail;
		t->nxt = a.head;
		tail = a.tail;
	}
};


int main()
{
    LinkedList a;
	LinkedList b;

	a.insertHead(1);
	a.insertTail(5);
	a.insertMid(3);
	a.insertHead(0);
	a.insertTail(10);
	a.print(); // prints  0 1 3 5 10

	b.insertHead(10);
	b.insertTail(50);
	b.insertMid(30);
	b.insertHead(9);
	b.insertTail(100);
	b.print(); // prints  9 10 30 50 100

	a.Merge(b);
	a.print(); // prints  0 1 3 5 10 9 10 30 50 100
	b.print(); // prints  9 10 30 50 100

    return 0;
}

