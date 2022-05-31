#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node
{
public:
	T val;
	Node<T> *left, *right;
	Node(T val)
	{
		this->val = val;
		left = nullptr;
		right = nullptr;
	}
};

template <class T>
Node<T> *rightRotate(Node<T> *x)
{
	Node<T> *y = x->left;
	x->left = y->right;
	y->right = x;
	return y;
}

template <class T>
Node<T> *leftRotate(Node<T> *x)
{
	Node<T> *y = x->right;
	x->right = y->left;
	y->left = x;
	return y;
}

template <class T>
Node<T> *splay(Node<T> *root, T key)
{
    // Base cases: root is NULL or
    // key is present at root
	// cout<<"hello"<<endl;
    if (root == NULL || root->val == key)
        return root;
 
    // Key lies in left subtree
    if (root->val > key)
    {
        // Key is not in tree, we are done
        if (root->left == NULL) return root;
 
        // Zig-Zig (Left Left)
        if (root->left->val > key)
        {
            // First recursively bring the
            // key as root of left-left
            root->left->left = splay(root->left->left, key);
 
            // Do first rotation for root,
            // second rotation is done after else
            root = rightRotate(root);
        }
        else if (root->left->val < key) // Zig-Zag (Left Right)
        {
            // First recursively bring
            // the key as root of left-right
            root->left->right = splay(root->left->right, key);
 
            // Do first rotation for root->left
            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
        }
 
        // Do second rotation for root
        return (root->left == NULL)? root: rightRotate(root);
    }
    else // Key lies in right subtree
    {
        // Key is not in tree, we are done
        if (root->right == NULL) return root;
 
        // Zag-Zig (Right Left)
        if (root->right->val > key)
        {
            // Bring the key as root of right-left
            root->right->left = splay(root->right->left, key);
 
            // Do first rotation for root->right
            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        }
        else if (root->right->val < key)// Zag-Zag (Right Right)
        {
            // Bring the key as root of
            // right-right and do first rotation
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }
 
        // Do second rotation for root
        return (root->right == NULL)? root: leftRotate(root);
    }
}

template <class T>
Node<T> *insert(Node<T> *root, T k)
{
	if (!root)
		return new Node<T>(k);

	root = splay(root, k);
	if (root->val == k)
		return root;

	Node<T> *newNode = new Node<T>(k);

	if (root->val > k)
	{
		newNode->right = root;
		newNode->left = root->left;
		root->left = nullptr;
	}
	else
	{
		newNode->left = root;
		newNode->right = root->right;
		root->right = nullptr;
	}
	return newNode;
}

template <class T>
void preOrder(Node<T> *root)
{
	if (!root)
		return;
	cout << root->val << " ";
	preOrder(root->left);
	preOrder(root->right);
}

template <class T>
Node<T> *searchFor(Node<T> *root, T key)
{
	Node<T> *newRoot = splay(root, key);
	if (newRoot && newRoot->val == key)
		cout << "Found " << key << endl;
	else
		cout << "Could not find " << key << endl;
	return newRoot;
}

template <class T>
Node<T> *deleteNode(Node<T> *root, T key)
{
	Node<T> *temp;
	if (!root)
		return nullptr;

	root = splay(root, key);

	if (key != root->val)
		return root;

	if (!root->left)
	{
		temp = root;
		root = root->right;
	}

	else
	{
		temp = root;
		root = splay(root->left, key);
		root->right = temp->right;
	}
	free(temp);
	return root;
}

int main()
{
	int choice;
	Node<int> *root = nullptr;
	while (true)
	{
		printf("0 for help >>");
		cin >> choice;
		if (choice == 0)
		{
			cout << "1 -> insert\n";
			cout << "2 -> search\n";
			cout << "3 -> delete\n";
			cout << "4 -> print preorder\n";
			cout << "-1 -> exit\n";
		}
		else if (choice == 1)
		{
			int val;
			printf("Enter value to insert: ");
			cin >> val;
			root = insert(root, val);
			printf("Done\n");
		}
		else if (choice == 3)
		{
			int val;
			printf("Enter value to delete: ");
			cin >> val;
			root = deleteNode(root, val);
			printf("Done\n");
		}
		else if (choice == 2)
		{
			int val;
			printf("Enter value to search for: ");
			cin >> val;
			root = searchFor(root, val);
		}
		else if (choice == 4)
		{
			preOrder(root);
			cout << endl;
		}
		else
			break;
	}
	return 0;
}
