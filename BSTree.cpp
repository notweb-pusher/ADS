#include <ios>
#include <iostream>
#include <type_traits>
#include <vector>
#include <queue>

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

    void inorder(Node* node)
    {
        if (node)
        {
            inorder(node->left);
            cout << node->key << ' ';
            inorder(node->right);
        }
    }

    void preorder(Node* node)
    {
        if (node)
        {
            cout << node->key << ' ';
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(Node* node)
    {
        if (node)
        {
            postorder(node->left);
            postorder(node->right);
            cout << node->key << ' ';
        }
    }

    void bfs()
    {

        if (!_root)
            return ;
        
        queue<Node*> queue;
        queue.push(_root);

        while(!queue.empty())
        {
            Node* tmp = queue.front();
            cout << tmp->key << ' ';

            if (tmp->left != nullptr)
                queue.push(tmp->left);
            if (tmp->right != nullptr)
                queue.push(tmp->right);

            queue.pop();
        }
    }
private:
    Node* _root;
};

int main()
{
    // BSTree myTree;
    // vector<int>  data = {8, 3, 10, 1, 6, 14, 4, 7, 13};

    // for (int i = 0; i < data.size(); i++)
    //     myTree.insert(data[i]);

    // myTree.inorder(myTree.getRoot());
    // myTree.preorder(myTree.getRoot());
    // myTree.postorder(myTree.getRoot());
    // myTree.bfs();
    // if (myTree.search(228))
    // {
    //     cout << "Value found" << endl;
    // }
}