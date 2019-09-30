#include<iostream>
#include<queue>
#include<vector>
using namespace std;

priority_queue<pair<int,int>> q;



struct Node
{
	int data;
	Node* left = nullptr;
	Node* right = nullptr;
};

Node* root = nullptr;

void Insert(int data,Node*& node = root)
{
	if (!root)
	{
		root = new Node();
		root->data = data;
		return;
	}
	if (!node)
	{
		node = new Node();
		node->data = data;
		return;
	}


	if (data > node->data)
	{
		Insert(data, node->right);
	}
	else
	{
		Insert(data, node->left);
	}

}
void Print(Node* node = root)
{
	if (node)
	{
		Print(node->left);
		cout << node->data << endl;
		Print(node->right);
	}
}



void Delete(int data,Node*& node = root)
{
	if (!node)
	{
		cout << "Can't Find" << endl;
		return;
	}

	Node* temp;

	if (data > node->data)
	{
		Delete(data, node->right);
	}
	else if (data < node->data)
	{
		Delete(data, node->left);
	}
	else
	{
		if (node->left && node->right)
		{
			Node* minNode = node->right;
			while (minNode->left)
			{
				minNode = minNode->left;
			}
			int tempData = minNode->data;
			node->data = tempData;

			Delete(tempData, node->right);
		}
		else if (node->left)
		{
			temp = node;
			node = node->left;
			delete temp;
		}
		else if (node->right)
		{
			temp = node;
			node = node->right;
			delete temp;
		}
		else
		{
			temp = node;
			node = nullptr;
			delete temp;
		}
	}
}

#include<random>

int main()
{
	random_device rd;
	uniform_int_distribution<int> ud(1,100);

	Insert(10);
	Insert(5);
	Insert(7);
	Insert(6);
	Insert(3);
	Insert(2);
	Insert(12);
	Insert(13);

	Delete(5);
	Print();

}