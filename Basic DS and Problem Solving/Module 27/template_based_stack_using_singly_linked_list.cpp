#include<bits/stdc++.h>
using namespace std;


template <class T>
class node
{
public:
    T data;
    node * nxt;
};

template <class T>
class SinglyLinkedList
{
public:
    node<T> *head;
    int sz;
    SinglyLinkedList()
    {
        head = NULL;
        sz = 0;
    }

    //Creates a new node with the given data and returns it O(1)
    node<T> * CreateNewNode(T data)
    {
        node<T> *newnode = new node<T>;
        newnode->data = data;
        newnode->nxt = NULL;
        return newnode;
    }

    //Inserts a node with given data at head O(1)
    void InsertAtHead(T data)
    {
        sz++;
        node<T> *newnode = CreateNewNode(data);
        if(head == NULL)
        {
            head = newnode;
            return;
        }
        node<T> *a = head;
        newnode->nxt = a;
        head = newnode;
        return;
    }


    //Prints the linked list O(n)
    void Traverse()
    {
        node <T> * a = head;
        while(a != NULL){
            cout << a->data <<" ";
            a = a->nxt;
        }
        cout << "\n";
    }

    // Returns the size of linked list O(1)
    int getSize()
    {
        return sz;
    }

    // Delete at head O(1)
    void deleteAtHead()
    {
        if(head == NULL){
            return;
        }

        node<T> * a = head;
        node<T> * b = head->nxt;

        delete a;

        head = b;
        sz--;
    }

};

//Template Stack using Doubly Linked List

template <class T>
class Stack
{
public:

    SinglyLinkedList <T> sl;

    Stack()
    {

    }

    T top()
    {
        if(sl.getSize() <= 0){
            cout << "Stack Empty, no element on top, Returning garbage value: ";
            T a;
            return a;
        }
        else{
            return sl.head->data;

        }
    }

    void push(T item)
    {
        sl.InsertAtHead(item);
    }

    void pop()
    {
        if(sl.getSize() <= 0){
            cout << "Stack Empty cannot pop \n";
            return;
        }
        else{
            sl.deleteAtHead();
        }

    }

    void print_stack()
    {
        sl.Traverse();
    }
};


int main()
{
    Stack <char> st;
    st.push('A');
    //cout << st.top() << "\n";
    st.push('B');
    st.push('C');
    st.push('D');
    st.push('E');
    st.push('F');
    st.push('G');
    cout << st.top() << "\n";
    st.print_stack();
    st.pop();
    cout << st.top() << "\n";
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();

    st.print_stack();


    cout << st.top() << " ";

    st.print_stack();

    return 0;
}

