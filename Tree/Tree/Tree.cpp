#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
#include <limits>
#include <string>
#include <set>
#include <queue>

using namespace std;
//
//이진 트리를 입력받아 전위 순회(preorder traversal), 중위 순회(inorder traversal), 후위 순회(postorder traversal)한 결과를 출력하는 프로그램을 작성하시오.

struct Node
{
public:
	char data;
	Node* left;
	Node* right;


};

Node* CreateNode(char data) //노드를 만드는 함수
{
	Node* newNode = new Node();
	if (!newNode) {
		return NULL;
	}
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node* InsertNode(Node* root, char data) //루트노드에 data를 넣는 함수 왼쪽부터 차례대로 들어간다.
{
	if (root == NULL)
	{
		root = CreateNode(data);
		return root;
	}

	queue<Node*> q;
	q.push(root);


	while (!q.empty())
	{
		Node* temp = q.front();
		q.pop();


		if (temp->left != NULL)
		{
			q.push(temp->left);

		}
		else
		{
			temp->left = CreateNode(data);
			return root;
		}

		if (temp->right != NULL)
		{
			q.push(temp->right);
		}
		else
		{
			temp->right = CreateNode(data);
			return root;
		}




	}



}

void Preorder(struct Node* node) // 전위 순회함수
{
	if (node == NULL)
	{
		return;
	}
	if (node->data != '.')
	{
		cout << node->data;
	}
	Preorder(node->left);
	Preorder(node->right);
}

void Inorder(struct Node* node) // 중위 순회함수
{
	if (node == NULL)
	{
		return;
	}
	Inorder(node->left);
	if (node->data != '.')
	{
		cout << node->data;
	}
	Inorder(node->right);
}

void Postorder(struct Node* node)  // 후위 순회 함수
{
	if (node == NULL)
	{
		return;
	}
	Postorder(node->left);
	Postorder(node->right);
	if (node->data != '.')
	{
		cout << node->data;
	}
}


void FindAndInsert(struct Node* node, char target, char insertItem) //root노드를 따라서 target을 찾고 target자식으로 insertItem을 넣는다
{
	if (node == NULL)
	{
		return;
	}
	if (node->data == target)
	{
		node = InsertNode(node, insertItem);
		return;
	}
	FindAndInsert(node->left, target, insertItem);
	FindAndInsert(node->right, target, insertItem);
}

int main(void)
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	char a, b, c;

	cin >> a >> b >> c;

	Node* root = CreateNode(a);
	root = InsertNode(root, b);
	root = InsertNode(root, c);

	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b >> c;

		FindAndInsert(root, a, b);
		FindAndInsert(root, a, c);

	}
	Preorder(root);
	cout << "\n";
	Inorder(root);
	cout << "\n";
	Postorder(root);



	return 0;

}