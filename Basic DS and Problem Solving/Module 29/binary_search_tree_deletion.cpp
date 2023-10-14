#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int id;
    int value;
    node *left;
    node *right;
    node *parent;
};

class BST
{
public:

    node* root;

    BST()
    {
        root = NULL;
    }

    node* createNewNode(int id, int value)
    {
        node* newnode = new node;
        newnode->id = id;
        newnode->value = value;
        newnode->left = NULL;
        newnode->right = NULL;
        newnode->parent = NULL;

        return newnode;
    }

    void Insertion(int id, int value)
    {
        node * newnode = createNewNode(id, value);
        if(root == NULL){
            root = newnode;
            return;
        }

        node * cur = root;
        node * prv = NULL;

        while(cur != NULL){
            if(newnode->value > cur->value){
                prv = cur;
                cur = cur->right;
            }
            else{
                prv = cur;
                cur = cur->left;
            }
        }

        if(newnode->value > prv->value){
            prv->right = newnode;
        }
        else{
            prv->left = newnode;
        }

    }

    void Delete(int value)
    {
        node * current = root;
        node * prev = NULL;

        while(current != NULL){
            if(value > current->value){
                prev = current;
                current = current->right;
            }
            else if(value < current->value){
                prev = current;
                current = current->left;
            }
            else{
                break;
            }
        }

        if(current == NULL){
            cout << "Value is not present in BST\n";
            return;
        }

        // Case 1: both child is NULL
        if(current->left == NULL && current->right == NULL ){
            if(prev->left != NULL && prev->left->value == current->value){
                prev->left = NULL;
            }
            else{
                prev->right = NULL;
            }

            delete current;
            return;
        }

        // Case 2: node has only one child, right
        if(current->left == NULL && current->right != NULL)
        {
            if(prev->left->value == current->value){
                prev->left = current->right;
            }
            else{
                prev->right = current->right;
            }

            delete current;
            return;
        }

        // Case 2: node has only one child, left
        if(current->left != NULL && current->right == NULL)
        {
            if(prev->left->value == current->value){
                prev->left = current->left;
            }
            else{
                prev->right = current->left;
            }

            delete current;
            return;
        }
    }

    void BFS()
    {
        if(root == NULL) return;

        queue <node*> q;
        q.push(root);

        while(!q.empty())
        {
            node * a = q.front();
            q.pop();
            int p = -1, l = -1, r = -1;
            if(a->left != NULL){
               l = a->left->value;
               q.push(a->left);
            }
            if(a->right != NULL){
               r = a->right->id;
               q.push(a->right);
            }

            cout << "Node Value = " << a->value <<" Left child = " << l;
            cout << "  Right child = " << r <<"\n";
        }
    }

    void DFS(node * a)
    {
        // Base case
        if(a == NULL) return;

        cout << a->value << " ";

        DFS(a->left);
        DFS(a->right);
    }

};

int main()
{
    BST bst;

    bst.Insertion(1, 6);
    bst.Insertion(2, 4);
    bst.Insertion(3, 3);
    bst.Insertion(4, 5);
    bst.Insertion(5, 7);
    bst.Insertion(6, 8);


    bst.BFS();

    cout << "\n";

    //case 1
    //bt

    return 0;
}



