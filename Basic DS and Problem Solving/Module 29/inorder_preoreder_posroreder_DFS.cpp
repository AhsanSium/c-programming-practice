#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int id;
    node *left;
    node *right;
    node *parent;
};

class BinaryTree
{
public:

    node* root;

    BinaryTree()
    {
        root = NULL;
    }

    node* createNewNode(int id)
    {
        node* newnode = new node;
        newnode->id = id;
        newnode->left = NULL;
        newnode->right = NULL;
        newnode->parent = NULL;

        return newnode;
    }

    void build_binary_tree()
    {
        node* allnode[6];

        for(int i = 0; i < 6; i++){
            allnode[i] = createNewNode(i);
        }

        allnode[0]->left = allnode[1];
        allnode[0]->right = allnode[2];

        allnode[2]->left = allnode[5];
        allnode[2]->parent = allnode[0];

        allnode[1]->left = allnode[3];
        allnode[1]->right = allnode[4];
        allnode[1]->parent = allnode[0];

        allnode[5]->parent = allnode[2];

        allnode[3]->parent = allnode[1];

        allnode[4]->parent = allnode[1];

        root = allnode[0];

        cout << "First Id: " << allnode[0]->id << "\n";
    }


    // f(left) + parent + f(right)
    void Inorder(node * a)
    {
        // Base case
        if(a == NULL) return;

        Inorder(a->left);

        cout << a->id << " ";

        Inorder(a->right);
    }

    // root + f(left) + f(right)
    void Preorder(node * a)
    {
        // Base case
        if(a == NULL) return;

        cout << a->id << " ";

        Preorder(a->left);
        Preorder(a->right);
    }

    // f(left) + f(right) + root
    void Postorder(node * a)
    {
        // Base case
        if(a == NULL) return;

        Postorder(a->left);
        Postorder(a->right);

        cout << a->id << " ";
    }

};

int main()
{
    BinaryTree bt;
    bt.build_binary_tree();

    cout << "Inorder: ";
    bt.Inorder(bt.root);

    cout << "\n";
    cout << "Preorder: ";
    bt.Preorder(bt.root);

    cout << "\n";
    cout << "Postorder: ";
    bt.Postorder(bt.root);

    return 0;
}

