#include<bits/stdc++.h>
using namespace std;

class Node
{
// write your variables
public:
    float f;
    char ch;
    Node * next;
    Node * next_to_next;
};

class CustomLinkedList
{
public:
    Node * head;

    CustomLinkedList()
    {
        head = NULL;
    }

    Node * create_new_node(float f1, char ch1)
    {
        Node * newnode = new Node;
        newnode->next = NULL;
        newnode->next_to_next = NULL;
        newnode->ch = ch1;
        newnode->f = f1;

        return newnode;
    }

    void insert_at_head(float f1, char ch1)
    {
        Node * newnode = create_new_node(f1, ch1);

        if(head == NULL){
            head = newnode;
            return;
        }

        Node * tempnode = head;
        Node * next_tempnode = head->next;

        head = newnode;
        head->next = tempnode;
        if(next_tempnode != NULL){
            head->next_to_next = next_tempnode;
        }
    }

    void print_all()
    {
        if(head == NULL){
            cout << "Empty!\n";
            return;
        }
        Node * a = head;

        if(a->next_to_next != NULL){
        cout << "Next to next Float " << a->next_to_next->f << "  Next to next Char " << a->next_to_next->ch <<"\n";
        }
        while(a != NULL){
            cout << "Float " << a->f << " Char " << a->ch <<"\n";
            a = a->next;
        }
    }
};

int main()
{
    CustomLinkedList cll;

    cll.insert_at_head(4.1, 'a');
    cll.insert_at_head(4.2, 'b');
    cll.insert_at_head(4.3, 'c');
    cll.insert_at_head(4.4, 'd');
    cll.insert_at_head(4.5, 'e');

    cll.print_all();

    return 0;
}
