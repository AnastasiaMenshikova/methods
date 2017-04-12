#include "stdafx.h" 
#include "queue.h" 
#include <ctime> 
#include <cstdlib> 

using namespace std;

queue::queue()
{
	head = NULL;
	tail = NULL;
}

queue::~queue()
{
	Clear();
}

void queue::push(int a)		// Функция добавления элемента в конец очереди
{
	node *pv = new node;	//выделяем место в ячейке памяти 
	pv->value = a;			//записываем значение в информационное поле
	pv->next = NULL;
	if (queue::IsEmpty())	//если очередь пуста
	{
		tail = head = pv;	//первый элемент будет и началом, и концом
	}
	else  //если в очереди есть хотя бы один элемент
	{
		tail->next = pv;
		tail = pv;
	}
}

int queue::pop()			// Функция удаления элемента из начала очереди, возвращает целочисленное значение
{
	node* pv = new node();	//выделяем место в ячейке памяти
	pv = head;
	if (queue::IsEmpty())	//если очередь пуста, возвращаем NULL
	{
		return NULL;
	}
	else
	{
		int a;	// в переменную запишем значение удалённого элемента
		a = pv->value;
		pv = head;
		head = pv->next;
		delete pv;
		return a;
	}
}

bool queue::Search(int key)	//Функция для поиска элемента по значению
{
	node *pv = head;	//выделяем место в ячейке памяти 
	while (pv) //пока указатель на начало не ноль
	{
		if (pv->value == key)	//если значение очереди совпало с введённым, возвращаем true
		{
			return true;
		}
		pv = pv->next;	//меняем указатель, тем самым проходим по очереди
	}
	return false;
}

void queue::Del()	//Функция удаление элемента, используется в функции Clear() для очистки очереди
{
	node* pv = head;	//выделяем место в ячейке памяти 
	head = pv->next;		//меняем указатель на начало на указатель следующего элемента
	delete pv;				//удаляем первый элемент из очереди
}

void queue::RandPush(int amount, int range) //функция добавления случайных элементов в очередь
{
	int random, i = 0;
	node *pv = new node();
	srand(time(NULL));
	while (i != amount)
	{
		random = rand() % range;
		push(random);
		i++;
	}
}

void queue::Clear()		//функция очистки очереди
{
	while (head != NULL) //пока указатель на начало не ноль
	{
		Del();
	}
}

queue::iterater queue::getHead()	//Возвращает указатель на начало очереди
{
	return head;
}

queue::iterater queue::getTail() //Возвращает указатель на конец очереди
{
	return tail;
}

queue::iterater queue::getNext(iterater a) //Возвращает указатель на следующий элемент
{
	if (queue::IsEmpty()) {
		return NULL;
	}
	return a->next;
}

int queue::getInf(iterater a)	//Возвращает значение элемента очереди или 0, если очередь пуста
{
	if (queue::IsEmpty())
	{
		return NULL;
	}
	return a->value;
}

bool queue::IsEmpty() //Возращает false, если очередь пуста и true, если очередь заполнена хотя бы одним элементом
{
	if (head)
		return false;
	else true;
}
