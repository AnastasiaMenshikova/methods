#include "stdafx.h" 
#include "Matrix.h" 
#include <iostream> 

Matrix::Matrix()
{
	headline = headcolumn = NULL;

}

Matrix::~Matrix()
{
	DelMatrix();
}

void Matrix::Push(int line, int column, int info) { //добавление элемента в матрицу
	Node *elem, *elemline, *elemcolumn, *elemline1, *elemcolumn1;
	
	if (IsEmptyMatrix())
	{
		elem = new Node;
		elemline = new Node;
		elemcolumn = new Node;
		
		elem->line = line;
		elem->column = column;
		elem->info = info;
		
		elemline->column = elemline->info = 0;
		elemline->line = line;
		
		elemcolumn->line = elemcolumn->info = 0;
		elemcolumn->column = column;

		elemline->down = elemcolumn->right = NULL;
		elemline->right = elemcolumn->down = elem;
		elem->right = elemline;
		elem->down = elemcolumn;
		headcolumn = elemcolumn;
		headline = elemline;
	}
	else
	{
		if (IsExistVector(line, column))
		{
			elemline = headline;
			while (elemline->line != line)
			{
				elemline = elemline->down;
			}
			while (elemline->column != column)
			{
				elemline = elemline->right;
			}
			elemline->info = info;
		}
		else
		{
			elem = new Node;
			elem->line = line;
			elem->column = column;
			elem->info = info;

			elemline1 = headline;
			if (elemline1->line == line)
			{
				elemline = elemline1;
			}
			else
			{
				while ((elemline1->down) && (elemline1->down->line != line))
				{
					elemline1 = elemline1->down;
				}

			}

			if (elemline1->line == line)
			{
				elemline = elemline1;
			}
			else
			{
				if ((elemline1->down) && (elemline1->down->line == line))
				{
					elemline = elemline1->down;
				}
				else
				{
					elemline = new Node;
					elemline->column = elemline->info = 0;
					elemline->line = line;
					elemline1 = headline;
					if ((elemline->line < elemline1->line)) //Вставить до головы 
					{
						elemline->down = headline;
						headline = elemline;
					}
					else
					{
						while ((elemline1->down) && (elemline1->down->line < elemline->line))
						{
							elemline1 = elemline1->down;
						}

						if (elemline1->down)
						{
							elemline->down = elemline1->down;
							elemline1->down = elemline;
						}
						else //Вставляем в конец 
						{

							elemline1->down = elemline;
							elemline->down = NULL;
						}
					}
					elemline->right = elemline;

				}
			}

			// 



			elemcolumn1 = headcolumn;
			if (elemcolumn1->column == column)
			{
				elemcolumn = elemcolumn1;
			}
			else
			{
				while ((elemcolumn1->right) && (elemcolumn1->right->column != column))
				{
					elemcolumn1 = elemcolumn1->right;
				}
			}


			if (elemcolumn1->column == column)
			{
				elemcolumn = elemcolumn1;
			}
			else
			{
				if ((elemcolumn1->right) && (elemcolumn1->right->column == column))
				{
					elemcolumn = elemcolumn1->right;
				}
				else
				{
					elemcolumn = new Node;
					elemcolumn->line = elemcolumn->info = 0;
					elemcolumn->column = column;
					elemcolumn1 = headcolumn;
					if ((elemcolumn->column < elemcolumn1->column)) //Вставить до головы 
					{
						elemcolumn->right = headcolumn;
						headcolumn = elemcolumn;
					}
					else
					{
						while ((elemcolumn1->right) && (elemcolumn1->right->column < elemcolumn->column))
						{
							elemcolumn1 = elemcolumn1->right;
						}

						if (elemcolumn1->right)
						{
							elemcolumn->right = elemcolumn1->right;
							elemcolumn1->right = elemcolumn;

						}
						else //Вставляем в конец 
						{
							elemcolumn1->right = elemcolumn;
							elemcolumn->right = NULL;

						}
					}
					elemcolumn->down =
						elemcolumn;

				}
			}



			while ((elemline->right->column != 0) && (elemline->right->column < elem->column))
			{
				elemline = elemline->right;
			}

			elem->right = elemline->right;
			elemline->right = elem;





			while ((elemcolumn->down->line != 0) && (elemcolumn->down->line < elem->line))
			{
				elemcolumn = elemcolumn->down;
			}

			elem->down = elemcolumn->down;
			elemcolumn->down = elem;
		}
	}
}






void Matrix::Del(int line, int column) { //удаление элемента по заданным строке и столбцу 

	Node *elemline, *elemcolumn, *elem, *delline, *delcolumn;

	elemline = headline;
	if (elemline->line == line)
	{
		if (SumLine(elemline->line) == 1)
		{
			headline = elemline->down;
			delete elemline;
		}
		else
		{
			while (elemline->right->column != column)
			{
				elemline = elemline->right;
			}
			elemline->right = elemline->right->right;
		}
	}
	else
	{
		while (elemline->down->line != line)
		{
			elemline = elemline->down;
		}

		if (SumLine(elemline->down->line) == 1)
		{
			delline = elemline->down;
			elemline->down = elemline->down->down;
			delete delline;
		}
		else
		{
			elemline = elemline->down;
			while (elemline->right->column != column)
			{
				elemline = elemline->right;
			}
			elemline->right = elemline->right->right;
		}
	}


	elemcolumn = headcolumn;
	if (elemcolumn->column == column)
	{
		if (SumColumn(elemcolumn->column) == 1)
		{
			headcolumn = elemcolumn->right;
			delete elemcolumn;
		}
		else
		{
			while (elemcolumn->down->line != line)
			{
				elemcolumn = elemcolumn->down;
			}
			elemcolumn->down = elemcolumn->down->down;
		}
	}
	else
	{
		while (elemcolumn->right->column != column && elemcolumn->column != column)
		{
			elemcolumn = elemcolumn->right;
		}

		if (SumColumn(elemcolumn->right->column) == 1)
		{
			delcolumn = elemcolumn->right;
			elemcolumn->right = elemcolumn->right->right;
			delete delcolumn->down;
			delete delcolumn;
		}
		else
		{
			elemcolumn = elemcolumn->right;
			while (elemcolumn->down->line != line)
			{
				elemcolumn = elemcolumn->down;
			}
			elem = elemcolumn->down;
			elemcolumn->down = elemcolumn->down->down;
			delete elem;
		}
	}
}

int Matrix::Search(int line, int column) { //поиск данных по строке и столбцу
	Node *elemline = headline;


	while ((elemline) && (elemline->line != line))
	{
		elemline = elemline->down;
	}

	if (elemline)
	{
		elemline = elemline->right;
		while (elemline->column != 0 && elemline->column != column)
		{
			elemline = elemline->right;
		}

		if (elemline->column == column)
			return elemline->info;
		else
			return 0;
	}
	else
	{
		return 0;
	}
}

void Matrix::DelMatrix() { //функция удаляет матрицу
	while (IsEmptyMatrix() == 0)
	{
		Del(headline->line, headcolumn->column);
	}
}

Matrix::iterater Matrix::GetLineHead() {
	return headline;
}

Matrix::iterater Matrix::GetColumnHead() {
	return headcolumn;
}

Matrix::iterater Matrix::GetRight(iterater a) {
	if (Matrix::IsEmptyMatrix()) {
		return NULL;
	}
	return a->right;
}

Matrix::iterater Matrix::GetDown(iterater a) {
	if (Matrix::IsEmptyMatrix()) {
		return NULL;
	}
	return a->down;
}

int Matrix::GetLine(iterater a) {
	if (Matrix::IsEmptyMatrix()) {
		return NULL;
	}
	return a->line;
}

int Matrix::GetColumn(iterater a) {
	if (Matrix::IsEmptyMatrix()) {
		return NULL;
	}
	return a->column;
}

int Matrix::GetInfo(iterater a) {
	if (Matrix::IsEmptyMatrix()) {
		return NULL;
	}
	return a->info;
}

bool Matrix::IsEmptyMatrix() { //проверка матрицы на пустоту 
	if (headline)
		return false;
	else true;
}

bool Matrix::IsExistVector(int line, int column) { //проверка на существование вектора 
	Node *elemline = headline;

	while ((elemline) && (elemline->line != line))
	{
		elemline = elemline->down;
	}

	if (elemline)
	{
		elemline = elemline->right;
		while (elemline->column != 0 && elemline->column != column)
		{
			elemline = elemline->right;
		}

		if (elemline->column == column)
			return true;
		else
			return false;
	}
	else
	{
		return false;
	}
}

int Matrix::SumLine(int line) { //подсчет элементов матрицы в заданной строке
	Node *elem1, *elem = headline;
	int sum = 0;
	while ((elem) && (elem->line != line))
	{
		elem = elem->down;
	}

	if (elem)
	{
		elem1 = elem->right;
		while (elem1->column != elem->column)
		{
			elem1 = elem1->right;
			sum++;
		}
	}
	return sum;
}

int Matrix::SumColumn(int column) { //подсчет элементов матрицы в заданном столбце
	Node *elem1, *elem = headcolumn;
	int sum = 0;
	while ((elem) && (elem->column != column))
	{
		elem = elem->right;
	}

	if (elem)
	{
		elem1 = elem->down;
		while (elem1->line != elem->line)
		{
			elem1 = elem1->down;
			sum++;
		}
	}
	return sum;
}
