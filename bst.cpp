#include "stdafx.h" 
#include "bst.h" 
#include <iostream> 
#include <vector> 
#include <queue> 

using namespace std;

bst::bst()
{
	Top = NULL;
}

bst::~bst()
{
	DelTree();
}

void bst::Push(Node *root, int info) {
	Node *elem = new Node;
	elem->info = info;

	if (root) //если есть корень
	{
		if (info < root->info) {

			if (root->left)
			{
				Push(root->left, info);
			}
			else
			{
				root->left = elem;
				elem->info = info;
				elem->left = elem->right = NULL;
				return;
			}
		}

		if (info >= root->info) {
			if (root->right) {
				Push(root->right, info);
			}
			else {
				root->right = elem;
				elem->info = info;
				elem->left = elem->right = NULL;
				return;
			}
		}
	}
	else //если нет корня 
	{
		Top = elem;
		elem->left = elem->right = NULL;

	}
}

void bst::PushWrapper(int info) { //добавления элемента в дерево
	Push(Top, info);
}

void bst::Del(Node *&elem, int info) {
	if (info < elem->info)
	{
		Del(elem->left, info);
	}
	else
	{
		if (info > elem->info)
		{
			Del(elem->right, info);
		}
		else
		{
			if (elem->left != NULL && elem->right != NULL)
			{
				elem->info = minimum(elem->right);
				Del(elem->right, minimum(elem->right));
			}
			else
			{
				if (elem->left != 0)
				{
					elem = elem->left;
				}
				else
				{
					elem = elem->right;
				}
			}
		}
	}
}

void bst::DelWrapper(int info) { //удаление элемента 
	Del(Top, info);
}

int bst::Depth(Node *root, int depth)
{
	if (root == NULL)
	{
		return depth;
	}
	else
	{
		if (Depth(root->left, depth + 1) > Depth(root->right, depth + 1))
		{
			return Depth(root->left, depth + 1);
		}
		else
		{
			return Depth(root->right, depth + 1);
		}
	}
}

int bst::DepthWrapper() { //Функция:вычисление глубины дерева,Ввод:---,Возвращает:глубину 
	return Depth(Top, -1);
}

void bst::DelTree() //удаление дерева 
{
	while (!IsEmptyTree())
	{
		DelWrapper(Top->info);
	}
}

void bst::Straight(FCallback callback, Node *root)
{
	if (!root)
		return;
	//cout « root->info«endl; 
	callback(root->info);
	Straight(callback, root->left);
	Straight(callback, root->right);
}

void bst::StraightWrapper(FCallback callback) //Функция:прямой обход дерева,Ввод:функцию вывода,Возвращает:-— 
{
	Straight(callback, Top);
}

void bst::Symmetric(FCallback callback, Node *root)
{
	if (!root)
		return;
	Symmetric(callback, root->left);
	callback(root->info);
	Symmetric(callback, root->right);
}

void bst::SymmetricWrapper(FCallback callback) //Функция:симметричный обход дерева,Ввод:функцию вывода,Возвращает:-— 
{
	Symmetric(callback, Top);
}

void bst::Back(FCallback callback, Node *root)
{
	if (!root)
		return;
	Back(callback, root->left);
	Back(callback, root->right);
	callback(root->info);
}

void bst::BackWrapper(FCallback callback) //Функция:обратный обход дерева,Ввод:функцию вывода,Возвращает:-— 
{
	Back(callback, Top);
}

void bst::Width(FCallback callback) //Функция:обход дерева по ширине,Ввод:функцию вывода,Возвращает:-— 
{
	queue<Node> q;
	q.push(*Top);
	while (!q.empty())
	{
		callback((&q.front())->info);
		if ((&q.front())->left != 0 && (&q.front())->right != 0)
		{
			q.push(*(&q.front())->left);
			q.push(*(&q.front())->right);
		}
		else
		{
			if ((&q.front())->left)
			{
				q.push(*(&q.front())->left);
			}
			if ((&q.front())->right)
			{
				q.push(*(&q.front())->right);
			}
		}
		q.pop();
	}

}

bool bst::IsEmptyTree() { //Функция:проверка на существование дерева,Ввод:---,Возвращает:true,если дерево пустое,false,если непустое 
	if (Top)
		return false;
	else true;
}

bool bst::IsExistElem(int info) { //Функция:проверка на существование элемента,Ввод:данные,Возвращает:true,если такой элемент существует,false,если элемента не существует 
	Node *elem = Top;
	while (elem)
	{
		if (info < elem->info)
		{
			elem = elem->left;
		}
		else
		{
			if (info > elem->info)
			{
				elem = elem->right;
			}
			else
			{
				return true;
			}
		}
	}
	return false;
}

int bst::minimum(Node *root) { //Функция:вычисление минимального элемента в дереве,Ввод:Указатель на вершину,Возвращает:элемент 
	if (root->left == NULL)
	{
		return root->info;
	}
	else
	{
		minimum(root->left);
	}
}
