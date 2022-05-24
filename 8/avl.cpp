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

Node * minValueNode(Node* node)
{
    Node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

Node* deleteNode(Node* root, int key)
{
    if (root == NULL)
        return root;
    if ( key < root->val )
        root->left = deleteNode(root->left, key);
    else if( key > root->val )
        root->right = deleteNode(root->right, key);
    else
    {
        if( (root->left == NULL) ||
            (root->right == NULL) )
        {
            Node *temp = root->left ?
                         root->left :
                         root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else
        {
            Node* temp = minValueNode(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right,
                                     temp->val);
        }
    }
    if (root == NULL)
        return root;
    root->height = 1 + max(getHeight(root->left),
                           getHeight(root->right));

    int balance = getBalance(root);
    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);
    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);
    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void printInorder(Node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->val << " ";
    printInorder(node->right);
}

void searchFor(Node* node, int key){
    if(!node){
        cout<<"Could not find "<<key<<endl;
        return;
    }
    if(node->val==key){
        cout<<"Found "<<key<<endl;
        return;
    }
    if(node->val<key)
        searchFor(node->left, key);
    else
        searchFor(node->right, key);
}

int main(){
    int choice;
    Node* root = nullptr;
    while(true){
        printf("0 for help >>");
        cin>>choice;
        if(choice == 0){
            cout<<"1 -> insert\n";
            cout<<"2 -> search\n";
            cout<<"3 -> delete\n";
            cout<<"4 -> print inorder\n";
            cout<<"-1 -> exit\n";
        } else if(choice == 1){
            int val;
            printf("Enter value to insert: ");
            cin>>val;
            root = insert(root, val);
            printf("Done\n");
        } else if(choice == 3){
            int val;
            printf("Enter value to delete: ");
            cin>>val;
            root = deleteNode(root, val);
            printf("Done\n");
        } else if(choice == 2){
            int val;
            printf("Enter value to search for: ");
            cin>>val;
            searchFor(root, val);
        } else if(choice == 4){
            printInorder(root);
            cout<<endl;
        }
        else break;
    }
    return 0;
}
