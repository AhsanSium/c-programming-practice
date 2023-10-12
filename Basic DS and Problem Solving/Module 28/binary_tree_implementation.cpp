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
    node* allnode[6];

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

        for(int i = 0; i < 6; i++){
            allnode[i] = createNewNode(i);
        }

        allnode[0]->left = allnode[1];
        allnode[0]->right = allnode[2];

        allnode[1]->left = allnode[5];
        allnode[1]->parent = allnode[0];

        allnode[2]->left = allnode[3];
        allnode[2]->right = allnode[4];
        allnode[2]->parent = allnode[0];

        allnode[5]->parent = allnode[1];

        allnode[3]->parent = allnode[2];

        allnode[4]->parent = allnode[2];

        root = allnode[0];
    }

    void print_tree_info()
    {
        int p = -1;
        int l = -1;
        int r = -1;

        int sp1 = 40;
        int sp2 = 40;

        for(int i = 0; i < 6; i++)
        {
            if(allnode[i]->parent != NULL)
                p = allnode[i]->parent->id;

            if(allnode[i]->left != NULL)
                l = allnode[i]->left->id;

            if(allnode[i]->right != NULL)
                r = allnode[i]->right->id;

            cout << "Node "<< i <<": Parent = " << p << " , Left child = " << l << " , Right child = " << r << "\n";

//            for (int i = 0; i < sp1; ++i)
//            {
//               cout << " ";
//            }
//
//            if(p != -1)
//                cout << "[" << p << "]" <<"\n";
//
//            for (int i = 0; i < sp1-5; ++i)
//            {
//               cout << " ";
//            }
//
//            if(l != -1)
//                cout << "[" << l << "]";
//
//
//            for (int i = 0; i < 5; ++i)
//            {
//               cout << " ";
//            }
//
//            if(r != -1)
//                cout << "[" << r << "]";
//
//
//            cout << "\n\n\n";
//            sp1 = sp1 - 4;
//            sp2 = sp2 - 4;
        }
    }
};

int main()
{
    BinaryTree bt;
    bt.build_binary_tree();
    bt.print_tree_info();
    return 0;
}
