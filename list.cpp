#include "stdafx.h" 
#include "list.h" 
#include <iostream> 
#include <conio.h> 
#include "string.h" 
#include <ctime> 
#include <cstdlib> 

using namespace std;

list::list()
{
	head = NULL;
	tail = NULL;
}

list::~list()
{
	Clear();
}

void list::PushHead(int a) { //Функция добавления элемента в начало списка
	node *pv = new node;
	pv->value = a;
	pv->next = NULL;
	pv->prev = NULL;
	if (list::IsEmpty()) // если список пуст
	{
		tail = head = pv;
	}
	else
	{
		pv->next = head;
		head->prev = pv;
		head = pv;
	}
}

void list::PushTail(int a) { //Функция добавления элемента в конец списка
	node *pv = new node;
	pv->value = a;
	pv->next = NULL;
	pv->prev = NULL;
	if (list::IsEmpty())
	{
		tail = head = pv;
	}
	else
	{
		pv->prev = tail;
		tail->next = pv;
		tail = pv;
	}
}

void list::PushBefore(int key, int a) { //Функция добавления элемента до ключа
	node *pv = new node;
	node *sled;
	pv->value = a;
	pv->next = NULL;
	pv->prev = NULL;
	if (list::IsEmpty())
	{
		tail = head = pv;
	}
	else
	{
		sled = tail;
		while (sled->value != key)
		{
			sled = sled->prev;
		}
		pv->prev = sled->prev;
		sled->prev = pv;
		pv->next = sled;
		if (pv->prev)
			pv->prev->next = pv;
		else
			head = pv;
	}
}

void list::PushAfter(int key, int a) { //Функция добавления элемента после ключа
	node *pv = new node;
	node *pred;
	pv->value = a;
	pv->next = NULL;
	pv->prev = NULL;
	if (list::IsEmpty())
	{
		tail = head = pv;
	}
	else
	{
		pred = head;
		while (pred->value != key)
		{
			pred = pred->next;
		}
		pv->next = pred->next;
		pred->next = pv;
		pv->prev = pred;
		if (pv->next)
			pv->next->prev = pv;
		else
			tail = pv;
	}
}

int list::PopHead() {			//Функция:удаляет первый элемент в списке
	node* pv = head;
	if (list::IsEmpty()) {
		return NULL;
	}
	else
	{
		int a;
		a = pv->value;
		if (pv->next)
		{
			head = pv->next;
			head->prev = NULL;
		}
		else
			head = tail = NULL;
		delete pv;
		return a;
	}
}

int list::PopTail() { //Функция удаляет последний элемент в списке 
	node* pv = tail;
	if (list::IsEmpty()) {
		return NULL;
	}
	else
	{
		int a;
		a = pv->value;
		if (pv->prev)
		{
			tail = pv->prev;
			tail->next = NULL;
		}
		else
			head = tail = NULL;
		delete pv;
		return a;
	}
}

bool list::Search(int key) { //Функция проверки на существование элемента в списке. 
	node *pv = head;
	while (pv)
	{
		if (pv->value == key)
		{
			return true;	//Возвращает true, если такой элемент есть
		}
		pv = pv->next;
	}
	return false;			//Возвращает false, если такого элемента нет в списке
}

void list::Del() { //Функция удаляет первый элемент в списке
	node* pv = head;
	head = pv->next;
	delete pv;
}

void list::DelKey(int key) { //Функция удаляет ключ
	node* pv = head;
	int fl = 0;
	while (pv)
	{
		if (pv->value == key)
		{
			break;
		}
		pv = pv->next;
	}
	if (pv->next == NULL && pv->prev == NULL)
	{
		delete pv;
		head = tail = NULL;
	}
	else
	{
		if (pv == head)
		{
			fl = 1;
			head = head->next;
			head->prev = 0;
			delete pv;
		}

		if (pv == tail)
		{
			fl = 1;
			tail = tail->prev;
			tail->next = 0;
			delete pv;
		}

		if (fl == 0)
		{
			pv->prev->next = pv->next;
			pv->next->prev = pv->prev;
			delete pv;
		}
	}
}

void list::RandPush(int amount, int range) { //Функция заполнения очереди рандомными значениями
	int random, i = 0;
	node* pv = new node();
	srand(time(NULL));
	while (i != amount)
	{
		random = rand() % range;
		PushTail(random);
		i++;
	}
}

void list::Sort() { //Функция сортировка списка
	node *predthis, *this1, *pv;
	bool s = 0;
	predthis = head;
	this1 = pv = head->next;
	while (this1)
	{
		if ((pv->prev) && (this1->value < pv->prev->value))
		{
			while ((pv->prev) && (this1->value < pv->prev->value))
			{
				pv = pv->prev;
			}
			predthis->next = this1->next;
			if (this1->next)
			{
				this1->next->prev = predthis;
			}
			else
			{
				tail = predthis;
			}

			if (pv->prev)
			{
				pv->prev->next = this1;
				this1->prev = pv->prev;
			}

			else
			{
				head = this1;
				this1->prev = NULL;
			}

			this1->next = pv;
			pv->prev = this1;


			s = 1;
		}

		if (s == 0)
		{
			predthis = predthis->next;
			this1 = pv = predthis->next;
		}
		else
		{
			this1 = pv = predthis->next;
		}
		s = 0;
	}
}

void list::Clear() { //Функция чистки списка
	while (head) 
	{
		Del();
	}
}

list::iterater list::getHead() { //Получение указателя на начало списка 
	return head;
}

list::iterater list::getTail() { //Получение указателя на конец списка 
	return tail;
}

list::iterater list::getNext(iterater a) { //Получение указателя на следующий элемент в списке 
	if (list::IsEmpty()) {
		return NULL;
	}
	return a->next;
}

list::iterater list::getPrev(iterater a) { //Получение указателя на предыдущий элемент в списке  
	if (list::IsEmpty()) {
		return NULL;
	}
	return a->prev;
}

int list::getInf(iterater a) { //Получение данного из списка 
	if (list::IsEmpty()) {
		return NULL;
	}
	return a->value;
}

bool list::IsEmpty() { //Функция проверки на пустоту
	if (head)
		return false;
	else true;
}
