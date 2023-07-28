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
    node *head;
    int sz;
    DoublyLinkedList()
    {
        head = NULL;
        sz = 0;
    }

    //Creates a new node with the given data and returns it O(1)
    node * CreateNewNode(int data)
    {
        node *newnode = new node;
        newnode->data = data;
        newnode->nxt = NULL;
        newnode->prv = NULL;
        return newnode;
    }

    //Inserts a node with given data at head O(1)
    void InsertAtHead(int data)
    {
        sz++;
        node *newnode = CreateNewNode(data);
        if(head == NULL)
        {
            head = newnode;
            return;
        }
        node *a = head;
        newnode->nxt = a;
        a->prv = newnode;
        head = newnode;
    }

    //Inserts the given data at the given index O(n)
    void Insert(int index, int data)
    {
        if(index > sz)
        {
            return;
        }
        if(index==0)
        {
            InsertAtHead(data);
            return;
        }
        node *a = head;
        int cur_index = 0;
        while(cur_index!= index-1)
        {
            a = a->nxt;
            cur_index++;
        }
        // a = cur_index - 1
        node *newnode = CreateNewNode(data);
        newnode->nxt = a->nxt;
        newnode->prv = a;
        node *b = a->nxt;
        b->prv = newnode;
        a->nxt = newnode;
        sz++;
    }

    //Deletes the given index O(n)
    void Delete(int index)
    {
        if(index >= sz)
        {
            cout<<index<<" doesn't exist.\n";
            return;
        }
        node *a = head;
        int cur_index = 0;
        while(cur_index != index)
        {
            a = a->nxt;
            cur_index++;
        }
        node *b = a->prv;
        node *c = a->nxt;
        if(b!=NULL)
        {
            b->nxt = c;
        }
        if(c!= NULL)
        {
            c->prv = b;
        }
        delete a;
        if(index==0)
        {
            head = c;
        }
        sz--;
    }

    //Prints the linked list O(n)
    void Traverse()
    {
        node *a = head;
        while(a!=NULL)
        {
            cout<<a->data<<" ";
            a = a->nxt;
        }
        cout<<"\n";
    }

    // Returns the size of linked list O(1)
    int getSize()
    {
        return sz;
    }

    //Reverse the doubly linked list O(n)
    void Reverse()
    {
        if(head==NULL)
        {
            return;
        }
        node *a = head;
        int cur_index = 0;
        while(cur_index != sz-1)
        {
            a = a->nxt;
            cur_index++;
        }
        // last index is in a

        node *b = head;
        while(b!= NULL)
        {
            swap(b->nxt, b->prv);
            b = b->prv;
        }
        head = a;
    }

    //swap the i-th index and j-th index
    void Swap(int i, int j)
    {
        //cout << i << j; return;
        if(i > sz || i < 0 || j > sz || sz < 0)
        {
            cout<<"Index doesn't exist.\n";
            return;
        }
        node * a = head;
        node * b = head;

        for(int k = 0; k < i; k++){
            a = a->nxt;
        }

        for(int k = 0; k < j; k++){
            //cout << b->data;
            b = b->nxt;
        }

        swap(a->data,b->data);

        cout << "Swapped index "<< i << " and Index " << j << " \n";
    }

    // Delete at head O(1)
    void deleteAtHead()
    {
        if(head == NULL){
            return;
        }

        node * a = head;
        node * b = head->nxt;

        delete a;

        if(b!= NULL) b->prv = NULL;

        head = b;
        sz--;
    }

    //  delete all the nodes that have data = 0
    void deleteZero()
    {
        if(sz == 0) return;

        node * a = head;

        int flag = sz;


        while(flag > 0){
            //cout <<sz;
            node * temp = a;
            if(temp->data == 0){
                //cout << "DATA: " <<temp->data<<" \n";
                if(head->data == 0){

                        node *b = head;
                        node *c = temp->nxt;
                        if(b!=NULL)
                        {
                            b->nxt = c;
                        }
                        if(c!= NULL)
                        {
                            c->prv = b;
                        }
                        delete temp;
                        head = c;
                        sz--;
                        a = c;
                }
                else{
                        node *b = temp->prv;
                        node *c = temp->nxt;
                        if(b!=NULL)
                        {
                            b->nxt = c;
                        }
                        if(c!= NULL)
                        {
                            c->prv = b;
                        }
                        delete temp;
                        if(flag==0)
                        {
                            head = c;
                        }
                        sz--;
                        a = c;
                    }

                }
                else{
                    a = a->nxt;
                }

                flag--;
        }

        cout<<"Removed All the 0 valued Node.\n";

    }
};

class Stack
{
public:

    DoublyLinkedList dl;

    Stack()
    {

    }

    int top()
    {
        if(dl.getSize() == 0){
            cout << "Stack Empty\n";
            return -1;
        }
        return dl.head->data;

    }

    void push(int item)
    {
        dl.InsertAtHead(item);
    }

    void pop()
    {
        if(dl.getSize() == 0){
            cout << "Stack Empty\n";
            return ;
        }
        dl.deleteAtHead();
    }
};


int main()
{

    Stack st;
    cout << st.top()<< "\n";
    st.push(5);
    st.push(4);
    st.push(7);
    st.push(9);
    st.push(1);

    cout << st.top()<< "\n";
    st.push(10);
    cout << st.top()<< "\n";
    st.pop();
    cout << st.top()<< "\n";

    return 0;
}
