#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int val;
	Node *left, *right;
	Node(int val)
	{
		this->val = val;
		left = nullptr;
		right = nullptr;
	}
};

Node *rightRotate(Node *x)
{
	Node *y = x->left;
	x->left = y->right;
	y->right = x;
	return y;
}

Node *leftRotate(Node *x)
{
	Node *y = x->right;
	x->right = y->left;
	y->left = x;
	return y;
}

Node *splay(Node *root, int val)
{
	if (!root || root->val == val)
		return root;

	if (root->val > val)
	{
		if (!root->left)
			return root;
		if (root->left->val > val)
		{
			root->left->left = splay(root->left->left, val);
			root = rightRotate(root);
		}
		else if (root->left->val < val)
		{
			root->left->right = splay(root->left->right, val);
			if (!root->left->right)
				root->left = leftRotate(root->left);
		}
		return root->left ? rightRotate(root) : root;
	}
	else
	{		
		if (!root->right)
			return root;
		if (root->right->val > val)
		{
			root->right->left = splay(root->right->left, val);
			if (root->right->left)
				root->right = rightRotate(root->right);
		}
		else if (root->right->val < val)
		{
			root->right->right = splay(root->right->right, val);
			root = leftRotate(root);
		}
		return root->right ? leftRotate(root) : root;
	}
}

Node *insert(Node *root, int k)
{
	if (!root)
		return new Node(k);

	root = splay(root, k);
	if (root->val == k)
		return root;

	Node *newNode = new Node(k);

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

void printInorder(Node *root)
{
	if (!root)
		return;
	printInorder(root->left);
	cout << root->val << " ";
	printInorder(root->right);
}

void searchFor(Node *root, int key)
{
	Node *n = splay(root, key);
	if (n->val == key)
		cout << "Found " << key << endl;
	else
		cout << "Could not find " << key << endl;
}

Node *deleteNode(Node *root, int key)
{
	Node *temp;
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
	Node *root = nullptr;
	while (true)
	{
		printf("0 for help >>");
		cin >> choice;
		if (choice == 0)
		{
			cout << "1 -> insert\n";
			cout << "2 -> search\n";
			cout << "3 -> delete\n";
			cout << "4 -> print inorder\n";
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
			searchFor(root, val);
		}
		else if (choice == 4)
		{
			printInorder(root);
			cout << endl;
		}
		else
			break;
	}
	return 0;
}
