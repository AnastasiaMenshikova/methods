#include "stdafx.h" 
#include "deque.h" 
#include <ctime> 
#include <cstdlib> 

using namespace std;

deque::deque()
{
	head = NULL;
	tail = NULL;
}

deque::~deque()
{
	Clear();
}

void deque::pushLast(int a)		// Функция добавления элемента в конец очереди
{
	node *pv = new node;	//выделяем место в ячейке памяти 
	pv->value = a;			//записываем значение в информационное поле
	pv->prev = tail;
	pv->next = NULL;
	if (deque::IsEmpty())	//если очередь пуста
	{
		tail = head = pv;	//первый элемент будет и началом, и концом
	}
	else  //если в очереди есть хотя бы один элемент
	{
		tail->next = pv;
		tail = pv;
	}
}

void deque::pushFirst(int a)		// Функция добавления элемента в начало очереди
{
	node *pv = new node;	//выделяем место в ячейке памяти 
	pv->value = a;			//записываем значение в информационное поле
	pv->next = head;
	pv->prev = NULL;
	if (deque::IsEmpty())	//если очередь пуста
	{
		head = tail = pv;	//первый элемент будет и началом, и концом
	}
	else  //если в очереди есть хотя бы один элемент
	{
		head->prev = pv;
		head = pv;
	}
}

int deque::popFirst()			// Функция удаления элемента из начала очереди, возвращает целочисленное значение
{
	node* pv = head;	//выделяем место в ячейке памяти
	if (deque::IsEmpty())	//если очередь пуста, возвращаем NULL
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

int deque::popLast()			// Функция удаления элемента из конца очереди, возвращает целочисленное значение
{
	node* pv = tail;	//выделяем место в ячейке памяти
	if (deque::IsEmpty())	//если очередь пуста, возвращаем NULL
	{
		return NULL;
	}
	else
	{
		int a;	// в переменную запишем значение удалённого элемента
		a = pv->value;
		tail = pv->prev;
		tail->next = NULL;
		delete pv;
		return a;
	}
}

bool deque::Search(int key)	//Функция для поиска элемента по значению
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

void deque::Del()	//Функция удаление элемента, используется в функции Clear() для очистки очереди
{
	node* pv = head;	//выделяем место в ячейке памяти 
	head = pv->next;		//меняем указатель на начало на указатель следующего элемента
	delete pv;				//удаляем первый элемент из очереди
}

void deque::RandPush(int amount, int range) //функция добавления случайных элементов в очередь
{
	int random, i = 0;
	node *pv = new node();
	srand(time(NULL));
	while (i != amount)
	{
		random = rand() % range;
		pushLast(random);
		i++;
	}
}

void deque::Clear()		//функция очистки очереди
{
	while (head != NULL) //пока указатель на начало не ноль
	{
		Del();
	}
}


deque::iterater deque::getHead()	//Возвращает указатель на начало очереди
{
	return head;
}

deque::iterater deque::getTail() //Возвращает указатель на конец очереди
{
	return tail;
}

deque::iterater deque::getNext(iterater a) //Возвращает указатель на следующий элемент
{
	if (deque::IsEmpty()) {
		return NULL;
	}
	return a->next;
}

int deque::getInf(iterater a)	//Возвращает значение элемента очереди или 0, если очередь пуста
{
	if (deque::IsEmpty())
	{
		return NULL;
	}
	return a->value;
}

bool deque::IsEmpty() //Возращает false, если очередь пуста и true, если очередь заполнена хотя бы одним элементом
{
	if (head)
		return false;
	else true;
}
