#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class AVLTree {
public:
  class Node {
  public:
    Node() {}
    Node(int key) : key(key), height(0), left(nullptr), right(nullptr) {}
    int key;
    int height;
    Node *left;
    Node *right;
    ~Node() {}
  };

  AVLTree() : _root(nullptr) {}

  void insert(int key) { _root = insert(_root, key); }

  // void print() { preorder(getRoot()); }

  void erase(int value) { erase(_root, value); }

  // BFS print

  void print() {

    if (!_root)
      return;

    queue<Node *> queue;
    queue.push(_root);

    while (!queue.empty()) {
      Node *tmp = queue.front();
      cout << tmp->key << ' ';

      if (tmp->left != nullptr)
        queue.push(tmp->left);
      if (tmp->right != nullptr)
        queue.push(tmp->right);

      queue.pop();
    }
  }

private:
  Node *_root;

  Node *erase(Node *node, int key) 
  {
    if (!node)
      return nullptr;
    if (node->key == key) 
    {
      // 0 children
      if (!node->left && !node->right) 
      {
        delete node;
        return nullptr;
      }
      // 1 right children
      else if (!node->left) 
      {
        Node *tmp = node->right;
        delete node;
        return tmp;
      }
      // 1 left children
      else if (!node->right) 
      {
        Node *tmp = node->left;
        delete node;
        return tmp;
      }
      // 2 children

      else 
      {
        Node *tmp = successor(node->right);
        node->key = tmp->key;
        node->right = erase(node->right, node->key);
      }
    }

    else if (node->key < key)
      node->right = erase(node->right, key);
    else if (node->key > key)
      node->left = erase(node->left, key);

    node->height = 1 + std::max(height(node->left), height(node->right));

    int height_delta = getHeightDelta(node);

    if (height_delta > 1 && key < node->left->key)
      return rightRotate(node);

    if (height_delta > 1 && key > node->left->key) {
      node->left = leftRotate(node->left);
      return rightRotate(node);
    }

    if (height_delta < -1 && key > node->right->key)
      return leftRotate(node);

    if (height_delta < -1 && key < node->right->key) {
      node->right = rightRotate(node->right);
      return leftRotate(node);
    }

    return node;
  }

  Node *getRoot() { return _root; }

  Node *successor(Node *node) 
  {
    while (node->left)
      node = node->left;
    return node;
  }

  Node *insert(Node *node, int key) 
  {
    if (node == nullptr) 
      return new Node(key);

    if (key < node->key) 
      node->left = insert(node->left, key);
    else if (key > node->key)
      node->right = insert(node->right, key);
    else 
      return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int height_delta = getHeightDelta(node);

    if (height_delta > 1 && key < node->left->key)
      return rightRotate(node);

    if (height_delta > 1 && key > node->left->key) 
    {
      node->left = leftRotate(node->left);
      return rightRotate(node);
    } 

    if (height_delta < -1 && key > node->right->key)
      return leftRotate(node);

    if (height_delta < -1 && key < node->right->key) 
    {
      node->right = rightRotate(node->right);
      return leftRotate(node);
    }

    return node;
  }

  Node *rightRotate(Node *node) 
  {
    Node *tmp = node->left;
    node->left = tmp->right;
    tmp->right = node;

    node->height = 1 + max(height(node->left), height(node->right));
    tmp->height = 1 + max(height(node->left), height(node->right));

    return tmp;
  }

  Node *leftRotate(Node *node) 
  {
    Node *tmp = node->right;
    node->right = tmp->left;
    tmp->left = node;

    node->height = 1 + max(height(node->left), height(node->right));
    tmp->height = 1 + max(height(tmp->left), height(tmp->right));

    return tmp;
  }

  int height(Node *node) { return node ? node->height : 0; }

  int getHeightDelta(Node *node) 
  {
    return node ? height(node->left) - height(node->right) : 0;
  }

  void preorder(Node *node) 
  {
    if (node) {
      cout << node->key << " ";
      preorder(node->left);
      preorder(node->right);
    }
  }
};

int main() 
{
  vector<int> a = {2, 1, 3, 4, 5, 6, 7, 8, 10, 228};
  AVLTree myTree;

  for (auto el : a)
    myTree.insert(el);

  myTree.print();

  myTree.erase(1);
  myTree.erase(3);
  myTree.erase(7);
  myTree.erase(5);

  cout << '\n';
  myTree.print();
}
