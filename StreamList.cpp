#include "stdafx.h" 
#include "StreamList.h" 
#include <iostream> 
#include <conio.h> 
#include <cstring> 

using namespace std;

StreamList::StreamList()
{
	headname = NULL;
	headnumber = NULL;
	tailname = NULL;
	tailnumber = NULL;
}

StreamList::~StreamList()
{
	DelList();
}

void StreamList::Push(char name[], char number[]) {
	node *elem = new node, *elem1, *elem2;
	strcpy_s(elem->name, name);
	strcpy_s(elem->number, number);
	if (IsEmpty()) // если список пуст
	{
		elem->nextName = elem->prevName = elem->nextNumber = elem->prevNumber = NULL;
		headname = headnumber = tailname = tailnumber = elem;
	}
	else
	{
		//сортируем по имени
		elem1 = headname;
		while ((strcmp(elem1->name, elem->name) <= 0) && (elem1->nextName)) // ищем подходящее место для вставки
		{
			elem1 = elem1->nextName;
		}

		if (strcmp(elem1->name, elem->name) < 0) //если нужно добавить в конце
		{
			elem1->nextName = elem;
			elem->prevName = elem1;
			elem->nextName = NULL;
			tailname = elem;
		}
		else  
		{
			elem->prevName = elem1->prevName;
			if (elem1->prevName)
			{
				elem1->prevName->nextName = elem;
			}
			else
			{
				elem->prevName = NULL;
				headname = elem;
			}


			elem->nextName = elem1;
			elem1->prevName = elem;
		}


		//сортируем по номеру
		elem2 = headnumber;
		while ((strcmp(elem2->number, elem->number) <= 0) && (elem2->nextNumber))
		{
			elem2 = elem2->nextNumber;
		}

		if (strcmp(elem2->number, elem->number) < 0)
		{
			elem2->nextNumber = elem;
			elem->prevNumber = elem2;
			elem->nextNumber = NULL;
			tailnumber = elem;
		}
		else
		{
			elem->prevNumber = elem2->prevNumber;
			if (elem2->prevNumber)
			{
				elem2->prevNumber->nextNumber = elem;
			}
			else
			{
				elem->prevNumber = NULL;
				headnumber = elem;
			}


			elem->nextNumber = elem2;
			elem2->prevNumber = elem;
		}

	}
}

void StreamList::DelList()
{
	node *elem, *del;
	elem = headname;
	while (elem)
	{
		del = elem;
		elem = elem->nextName;
		DelName(del->name);
	}
}

void StreamList::DelNumber(char Number[])
{
	node *elem = headnumber;
	int flag = NULL;

	while (elem) //Ищем элемент, который нам нужно удалить 
	{
		if (strcmp(elem->number, Number) == NULL)
		{
			break;
		}
		elem = elem->nextNumber;
	}

	if (elem->nextNumber == NULL && elem->prevNumber == NULL) //если в списке один номер
	{
		delete elem;
		headname = headnumber = tailname = tailnumber = NULL;
	}
	else
	{
		if (elem == headname) //Связываем указатели name 
		{
			flag = 1;
			headname = headname->nextName;
			headname->prevName = NULL;
		}

		if (elem == tailname)
		{
			flag = 1;
			tailname = tailname->prevName;
			tailname->nextName = NULL;
		}

		if (flag == NULL)
		{
			elem->prevName->nextName = elem->nextName;
			elem->nextName->prevName = elem->prevName;
		}

		flag = NULL;

		if (elem == headnumber) //Связываем указатели number и удаляем elem 
		{
			flag = 1;
			headnumber = headnumber->nextNumber;
			headnumber->prevNumber = NULL;
			delete elem;
		}

		if (elem == tailnumber)
		{
			flag = 1;
			tailnumber = tailnumber->prevNumber;
			tailnumber->nextNumber = NULL;
			delete elem;

		}

		if (flag == NULL)
		{
			elem->prevNumber->nextNumber = elem->nextNumber;
			elem->nextNumber->prevNumber = elem->prevNumber;
			delete elem;
		}
	}

}

void StreamList::DelName(char Name[])
{
	node *elem = headname;
	int flag = NULL;

	while (elem)
	{
		if (strcmp(elem->name, Name) == NULL)
		{
			break;
		}
		elem = elem->nextName;
	}

	if (elem->nextName == NULL && elem->prevName == NULL) //в списке находится одна фамилия
	{
		delete elem;
		headname = headnumber = tailname = tailnumber = NULL;
	}
	else
	{
		if (elem == headnumber) //Связываем указатели number 
		{
			flag = 1;
			headnumber = headnumber->nextNumber;
			headnumber->prevNumber = NULL;
		}

		if (elem == tailnumber)
		{
			flag = 1;
			tailnumber = tailnumber->prevNumber;
			tailnumber->nextNumber = NULL;
		}

		if (flag == NULL)
		{
			elem->prevNumber->nextNumber = elem-> nextNumber;
			elem-> nextNumber->prevNumber = elem->prevNumber;
		}

		flag = NULL;

		if (elem == headname) //Связываем указатели name и удаляем elem 
		{
			flag = 1;
			headname = headname->nextName;
			headname->prevName = NULL;
			delete elem;
		}

		if (elem == tailname)
		{
			flag = 1;
			tailname = tailname->prevName;
			tailname->nextName = NULL;
			delete elem;

		}

		if (flag == NULL)
		{
			elem->prevName->nextName = elem->nextName;
			elem->nextName->prevName = elem->prevName;
			delete elem;
		}
	}
}

char* StreamList::SearchName(char Number[])
{
	node *elem = headnumber; 
	while (elem)
	{
		if (strcmp(elem->number, Number) == NULL)
		{
			break;
		}
		elem = elem->nextNumber;
	}
	return elem->name;
}

char* StreamList::SearchNumber(char Name[])
{
	node *elem = headname;
	while (elem)
	{
		if (strcmp(elem->name, Name) == NULL)
		{
			break;
		}
		elem = elem->nextName;
	}
	return elem->number;
}

bool StreamList::ExistName(char keyName[])
{
	node *elem = headname;
	while (elem)
	{
		if (strcmp(elem->name, keyName) == NULL)
		{
			return true;
			break;
		}
		elem = elem->nextName;
	}
	return false;
}

bool StreamList::ExistNumber(char keyNumber[])
{
	node *elem = headnumber; 
	while (elem)
	{
		if (strcmp(elem->number, keyNumber) == NULL)
		{
			return true;
			break;
		}
		elem = elem->nextNumber;
	}
	return false;
}

bool StreamList::IsEmpty() { //Функция проверки на пустоту
	if (headname)
		return false;
	else true;
}

StreamList::iterater StreamList::GetHeadName() {
	return headname;
}

StreamList::iterater StreamList::GetTailName() { 
	return tailname;
}

StreamList::iterater StreamList::GetNextName(iterater a) {
	if (StreamList::IsEmpty()) {
		return NULL;
	}
	return a->nextName;
}

StreamList::iterater StreamList::GetPrevName(iterater a) {
	if (StreamList::IsEmpty()) {
		return NULL;
	}
	return a->prevName;
}

char* StreamList::GetNameInf(iterater a) { 
	if (StreamList::IsEmpty()) {
		return NULL;
	}
	return a->name;
}

StreamList::iterater StreamList::GetNumberHead() {
	return headnumber;
}

StreamList::iterater StreamList::GetNumberTail() {
	return tailnumber;
}

StreamList::iterater StreamList::GetNextNumber(iterater a) {
	if (StreamList::IsEmpty()) {
		return NULL;
	}
	return a->nextNumber;
}

StreamList::iterater StreamList::GetPrevNumber(iterater a) {
	if (StreamList::IsEmpty()) {
		return NULL;
	}
	return a->prevNumber;
}

char* StreamList::GetNumberInf(iterater a) {
	if (StreamList::IsEmpty()) {
		return NULL;
	}
	return a->number;
}
