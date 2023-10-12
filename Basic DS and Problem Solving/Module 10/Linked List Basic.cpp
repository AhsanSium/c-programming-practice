#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node * nxt;
};

class LinkedList
{
public:
    node * head;
    int sz;

    LinkedList()
    {
        head = NULL;
        sz=0;
    }
    //create a node w ith data=value, next=null
    node * createNewNode(int value)
    {
        node * a = new node;
        a->data = value;
        a->nxt = NULL;
        return a;
    }
    //insert new value at head
    void InsertAtHead(int value)
    {
        node * a = createNewNode(value);

        if(head == NULL){ head = a; sz++; return; }
        else {
            a->nxt = head;
            head = a;
            sz++;
        }
    }

    // Insert anywhere on the linked list
    void insertAtAnyIndex(int index, int value)
    {
        if(index < 0 || index > sz){
            return;
        }

        if(index == 0) {InsertAtHead(value); return;}

        sz++;
        node * a = head;
        int cur_index = 0;
        while(cur_index != index - 1){
            a = a->nxt;
            cur_index ++;
        }

        node * newNode = createNewNode(value);

        newNode->nxt = a->nxt;
        a->nxt = newNode;
    }

    //Insert after a specific value
    void insertAfterValue(int value, int data)
    {
        node * a;
        a = head;
        while(a != NULL){
            if(a->data == value){break;}
            a = a->nxt;
        }
        if(a == NULL){ cout << "Doesn't exist \n"; return;}

        node * newNode = createNewNode(data);
        newNode->nxt = a->nxt;
        a->nxt = newNode;
        sz++;
        return;
    }

    //prints linked list
    void Traverse()
    {
        node * a = head;
        int cnt = 1;
        while(a != NULL){
            cout<< a->data << " ";
            cout<<", cnt = " << cnt<<" | ";
            a = a->nxt;
            cnt++;
        }
        cout << "\n";
    }

    // Get the no of elements O(1)
    int getSize()
    {
        cout<<sz<<"\n";
        return sz;
    }

    // get value at index
    int getValue(int index)
    {
        node * a = head;
        int cnt = 0;
        while(a != NULL){
            if(cnt == index){ return a->data; }
            a = a->nxt;
            cnt++;
        }
        return -1;
    }

    //print linked list reverse
    void printInside(node * a)
    {
        if(a == NULL) return;

        printInside(a->nxt);
        cout<<a->data<<" ";
    }

    void printReverse()
    {
        node * a = head;
        printInside(a);
        cout << "\n";
    }

    // swap first tow nodes
    void swapFirst()
    {
        if(sz < 2) return;
        node * a = head;
        node * b = head->nxt;

        a->nxt = b->nxt;
        b->nxt = a;
        head = b;
    }

    // Search for a single value
    int searchDistinctValue(int value)
    {
        node * a = head;
        int index = 0;
        while( a != NULL )
        {
            if( a->data == value){
                return index;
            }
            a = a->nxt;
            index++;
        }
        return -1;
    }

    //Search All possible occurrence
    void searchAllValue(int value)
    {
        node * a = head;
        int index = 0;
        while( a != NULL )
        {
            if( a->data == value){
                cout << value << " is found at index " << index << "\n";
            }
            a = a->nxt;
            index++;
        }

    }

    //Delete Head
    void deleteAtHead()
    {
        if(head == NULL) return;

        node * a = head;
        head = a->nxt;
        sz--;
        delete a;
    }

    //Delete node at any Index
    void deleteAnyIndex(int index)
    {
        if(index < 0 || index > sz - 1) return;
        else if(index == 0) {deleteAtHead(); return;}
        else{
            node * a = head;
            int cur_index = 0;
            while(cur_index != index - 1){
                a = a->nxt;
                cur_index++;
            }

            node * b = a->nxt;
            a->nxt = b->nxt;
            delete b;
            sz--;
        }
    }
    //Sort Linked List Ascending order
    void sortLinkedList()
    {
        node * a = head;

        while(a != NULL){
            node * i = a->nxt;
            while(i != NULL){
                node * b = i->nxt;
                if(i->data > b->data){

                }
            }
            i = i->nxt;
        }
    }


};

int main()
{
    LinkedList l;
    //cout<<l.getSize()<<"\n";
    l.InsertAtHead(5);
    //cout<<l.getSize()<<"\n";
    l.InsertAtHead(6);
    l.InsertAtHead(30);
    //cout<<l.getSize()<<"\n";
    l.InsertAtHead(20);
    l.InsertAtHead(30);

    //cout<<l.getValue(2)<<"\n";

    //cout<<l.getValue(6)<<"\n";

    //l.printReverse();
    l.Traverse();
//    l.swapFirst();
//    l.Traverse();
//    l.printReverse();
//
//    l.insertAtAnyIndex(1, 76);
//    l.Traverse();
//    l.deleteAtHead();
//    l.Traverse();
//
//    l.deleteAnyIndex(2);
//    l.Traverse();
//    l.getSize();
//
//    l.insertAfterValue(60, 60);
//    l.Traverse();


    return 0;
}
