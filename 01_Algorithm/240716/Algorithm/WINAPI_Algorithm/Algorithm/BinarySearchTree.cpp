#include "BinarySearchTree.h"

BinarySearchTree::~BinarySearchTree()
{
	// TODO : 노드들 삭제 필요
}

void BinarySearchTree::Insert(int key)
{
	Node* newNode = new Node(key);

	if (_root == nullptr)
	{
		_root = newNode;
		return;
	}

	Node* node = _root;
	Node* parent = nullptr;

	// 자리 찾기, 부모 찾기
	while(true)
	{
		if (node == nullptr)
			break;

		parent = node;
		if (key < node->key)
		{
			node = node->left;
		}
		else
		{
			node = node->right;
		}
	}

	newNode->parent = parent;
	if (key < parent->key)
	{
		parent->left = newNode;
	}
	else
	{
		parent->right = newNode;
	}
}

void BinarySearchTree::PrintTree(Node* node)
{
	if (node == nullptr)
		return;

	// Tree의 전위 순회 : 부모 - 왼쪽 자식들(부모 왼쪽 오른쪽) - 오른쪽 자식들(부모 왼쪽 오른쪽) ...
	// Tree의 중위 순회 : 왼쪽 자식들 - 부모 - 오른쪽 자식들
	// Tree의 후위 순회 : 왼쪽 자식들 - 오른쪽 자식들 - 부모
	cout << node->key << endl;

	Node* left = node->left;
	Node* right = node->right;

	PrintTree(left);
	PrintTree(right);
}

Node* BinarySearchTree::Search(Node* node, int key)
{
	if (node == nullptr)
		return nullptr;

	if (node->key == key)
	{
		return node;
	}

	if (node->key > key)
		Search(node->left, key);
	else
		Search(node->right, key);
}

Node* BinarySearchTree::Min(Node* node)
{
	Node* left = node->left;

	if (left == nullptr)
	{
		return node;
	}

	Min(left);
}

Node* BinarySearchTree::Max(Node* node)
{
	Node* right = node->right;

	if (right == nullptr)
	{
		return node;
	}
	
	Max(right);
}

Node* BinarySearchTree::Previous(Node* node)
{
	if (node->left == nullptr)
		return node;

	return Max(node->left);
}

Node* BinarySearchTree::Next(Node* node)
{
	if (node->right == nullptr)
		return node;

	return Min(node->right);
}

void BinarySearchTree::Delete(Node* node)
{
	if (node == nullptr)
		return;

	if (node->left == nullptr)
	{
		Replace(node, node->right);
	}
	else if (node->right == nullptr)
	{
		Replace(node, node->left);
	}
	else
	{
		Node* prev = Previous(node);
		node->key = prev->key;
		node->data = prev->data;

		Delete(prev);
	}
}

void BinarySearchTree::Replace(Node* node1, Node* node2)
{
	if (node1->parent == nullptr)
		_root = node2;
	else if (node1 == node1->parent->left)
	{
		node1->parent->left = node2;
	}
	else
	{
		node1->parent->right = node2;
	}

	if (node2 != nullptr)
		node2->parent = node1->parent;

	delete node1;
}
