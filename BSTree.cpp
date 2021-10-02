#include <iostream>
#include <type_traits>
#include <vector>
using namespace std;

class BSTree
{
public:
    class Node
    {
    public:
        Node () {}
        Node(int value) : key(value), left(nullptr), right(nullptr)  {}
        int key;
        Node* left;
        Node* right;
    };

    BSTree() : _root(nullptr){}


    Node* getRoot()
    {
        return _root;
    }

    void insert(int value)
    {
        Node* tmp = _root;

        Node* newNode = new Node(value);
        Node* parent = nullptr;

        while (tmp)
        {
            parent = tmp;
            tmp = (newNode->key < tmp->key) ? tmp->left : tmp->right;
        }

        if (!parent)
            _root = newNode;
        else if (newNode->key < parent->key)
            parent->left = newNode;
        else
            parent->right = newNode;
    }

    Node* search(int value)
    {
        Node* root = _root;

        while (root != nullptr && root->key != value)
        {
            if (value < root->key)
                root = root->left;
            else
                root = root->right;
        }

        return root;
    }

    void inorder(BSTree::Node* node)
    {
        if (node)
        {
            inorder(node->left);
            cout << node->key << ' ';
            inorder(node->right);
        }
    }

    void preorder(BSTree::Node* node)
    {
        if (node)
        {
            cout << node->key << ' ';
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(BSTree::Node* node)
    {
        if (node)
        {
            postorder(node->left);
            postorder(node->right);
            cout << node->key << ' ';
        }
    }

    void levelorder(BSTree& myTree)
    {

    }
private:
    Node* _root;
};

int main()
{
    BSTree myTree;
    vector<int>  data = {8, 3, 10, 1, 6, 14, 4, 7, 13};

    for (int i = 0; i < data.size(); i++)
        myTree.insert(data[i]);

    myTree.inorder(myTree.getRoot());
    myTree.preorder(myTree.getRoot());
    myTree.postorder(myTree.getRoot());

    // if (myTree.search(228))
    // {
    //     cout << "Value found" << endl;
    // }
}