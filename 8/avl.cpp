#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *left, *right;
    int height;
    Node(int val){
        this->val = val;
        left = nullptr;
        right = nullptr;
        height = 0;
    }
};

int getHeight(Node* node){
    if(!node) return 0;
    return node->height;
}

Node *rightRotate(Node *n)
{
    Node *x = n->left;
    Node *T2 = x->right;
    x->right = n;
    n->left = T2;
    n->height = max(getHeight(n->left),
                    getHeight(n->right)) + 1;
    x->height = max(getHeight(x->left),
                    getHeight(x->right)) + 1;
    return x;
}

Node *leftRotate(Node *n)
{
    Node *y = n->right;
    Node *T2 = y->left;
    y->left = n;
    n->right = T2;
    n->height = max(getHeight(n->left),
                    getHeight(n->right)) + 1;
    y->height = max(getHeight(y->left),
                    getHeight(y->right)) + 1;
    return y;
}

int getBalance(Node* node){
    if(!node) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

Node* insert(Node* node, int val){
    if(!node)
        return new Node(val);
    if(node->val<val)
        node->right = insert(node->right, val);
    else if(node->val>val)
        node->left = insert(node->left, val);
    else
        return node;
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);
    if(balance > 1 && val < node->left->val)
        return rightRotate(node);
    if (balance > 1 && val < node->left->val)
        return rightRotate(node);
    if (balance < -1 && val > node->right->val)
        return leftRotate(node);
    if (balance > 1 && val > node->left->val){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && val < node->right->val){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void printInorder(Node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->val << " ";
    printInorder(node->right);
}

int main(){
    Node* root = insert(nullptr, 12);
    root = insert(root, 34);
    root = insert(root, 45);
    root = insert(root, 1);
    root = insert(root, 0);
    root = insert(root, 89);
    root = insert(root, 10);
    root = insert(root, 25);
    cout<<"Inorder traversal of the tree: \n";
    printInorder(root);
    return 0;
}
