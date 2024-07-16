#include "unordered_map"
#include "map"
#include "BinarySearchTree.h"

// �ؽ� ���̺� : �޸𸮸� �ְ� Ž���ð��� ���Ѵ�.
// Ž�� : ��� �ð�... �ؽ��浹�� ���� ü�̴׿� ���� �޶��� �� �ִ�.
// ���� : ��� �ð�
// �浹, ü�̴�(����Ʈ) ����

// �ڰ���������Ž��Ʈ��(map)
// Ž�� : logN
// ���� : logN

// �ؽ����̺�(umordered map) vs �ڰ���������Ž��Ʈ(map)
// �ؽ� �Լ� �� �浹�� ���� �Ͼ ���... �ڰ���������Ž��Ʈ�� ��
// �浹�� ���� ���... �ؽ����̺� ��

int main()
{
#pragma region BST
	BinarySearchTree bst;
	bst.Insert(50);
	bst.Insert(40);
	bst.Insert(70);
	bst.Insert(30);
	bst.Insert(45);

	// bst.PrintTree(bst._root);

	auto searchNode =  bst.Search(bst._root, 45);
	if (searchNode != nullptr)
	{
		cout << "�ش� ��带 ã�ҽ��ϴ�" << endl;
		cout << searchNode->key << endl;
	}
	else
	{
		cout << "�ش� ��尡 �����ϴ�." << endl;
	}

	cout << "�ּ� ���� " << bst.Min(bst._root)->key << "�Դϴ�." << endl;
	cout << "�ִ� ���� " << bst.Max(bst._root)->key << "�Դϴ�." << endl;


	auto Node = bst.Search(bst._root, 60);
	auto previousNode = bst.Previous(Node);
	auto nextNode = bst.Next(Node);
	if(previousNode != nullptr)
		cout << previousNode->key << endl;
	if(nextNode != nullptr)
		cout << nextNode->key << endl;
#pragma endregion

	unordered_map<int, int> um;

	um[5] = 1;

	return 0;
}