#include "stdafx.h"
#include "queue.h"
#include <fstream>
#include <iostream>


using namespace std;

int main()
{
	int mn, data, range, amount, error; // data - информационное поле
	queue a;
	queue::iterater iter;
	queue::iterater iter_tail;
	bool flagempty = false;
	bool flagvvod = true;
	ifstream f;
	ofstream f1;
	setlocale(LC_ALL, "Russian");
	do
	{
		cout << "Выберите пункт меню:" << endl;
		cout << "1)Добавить один элемент в конец очереди" << endl;
		cout << "2)Заполнить очередь рандомными значениями" << endl;
		cout << "3)Удалить элемент из начала очереди" << endl;
		cout << "4)Очистить очередь" << endl;
		cout << "5)Поиск элемента в очереди по значению" << endl;
		cout << "6)Просмотр элементов очереди" << endl;
		cout << "7)Считавание элементов очереди из файла" << endl;
		cout << "8)Создать файл и записать туда элементы очереди" << endl;
		cout << "Нажмите 0 для выхода из программы" << endl;
		cin >> mn;

		if (mn < 0 || mn>8)
		{
			cout << "Ошибка! Необходимо ввести число от 1 до 8 или 0 для выхода." << endl;
			system("pause");
			cin.clear();
			cin.ignore();
			system("cls");
		}
		switch (mn)
		{


		case 1:
		{
			system("cls");
			error = 1;
			for (;;)
			{
				cout << "Введите одно значение для добавления в очередь:" << endl;
				if ((cin >> data) && (cin.good()))
				{
					break;
				}
				else
				{
					if (error == 1)
					{
						error = 0;
						cout << "\n Некорректное значение. Введите число:" << endl;
						system("pause");
					}

					cin.clear();
					cin.ignore();
					system("cls");
				}
			}
			a.push(data);
			system("cls");
			cout << "Элемент был успешно добавлен." << endl;
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			int flag = 0;
			system("cls");
			error = 1;
			while (flag != 1)
			{
				cout << "Введите количество элементов:" << endl;
				if ((cin >> amount) && (cin.good()))
				{
					flag = 1;
				}
				else
				{
					if (error == 1)
					{
						error = 0;
						cout << "\n Некорректное значение. Выполните операцию заново." << endl;
						system("pause");
					}
					cin.clear();
					cin.ignore();
					system("cls");
				}
			}

			while (flag != 0)
			{
				cout << "Введите максимальное значение:" << endl;
				if ((amount > 0) && (cin >> range) && (cin.good()))
				{
					flag = 0;
					a.RandPush(amount, range);
					system("cls");
					cout << "Элементы были успешно добавлены." << endl;
					system("pause");
					system("cls");
				}
				else
				{
					if (error == 1)
					{
						error = 0;
						cout << "\n Некорректное значение. Выполните операцию заново." << endl;
						system("pause");
					}
					cin.clear();
					cin.ignore();
				}
				system("cls");
			}
			system("cls");
			break;
		}

		case 3:
		{

			system("cls");
			if (a.IsEmpty())
			{
				system("cls");
				cout << "Невозможно удалить элемент, очередь пуста. Добавьте элементы." << endl;
				system("pause");
			}
			else
			{
				int p = a.pop();
				cout << "Элемент" << p << "был успешно удален" << endl;
				system("pause");
			}
			system("cls");
			break;
		}

		case 4:
		{
			system("cls");
			if (a.IsEmpty())
			{
				cout << "Элементов нет." << endl;
				system("pause");
			}
			else
			{
				a.Clear();
				cout << "Очередь была успешно очищена." << endl;
				system("pause");
			}
			system("cls");
			break;
		}

		case 5:
		{
			system("cls");
			error = 1;
			if (a.IsEmpty())
			{
				system("cls");
				cout << "Очередь пуста. Добавьте элементы для поиска." << endl;
				system("pause");
			}
			else
			{
				cout << "Введите элемент для поиска:" << endl;
				if ((cin >> data) && (cin.good()))
				{
					if (a.Search(data) == false)
					{
						cout << "Элемент не был найден." << endl;
					}
					else
					{
						cout << "Элемент " << data << " находится в очереди." << endl;
					}

				}
				else
				{
					if (error == 1)
					{
						error = 0;
						cout << "\n Некорректное значение. Введите число:" << endl;
						system("pause");
					}

					cin.clear();
					cin.ignore();
					system("cls");
				}
				system("pause");
			}
			system("cls");
			break;
		}


		case 6:
		{
			system("cls");
			iter = a.getHead();
			if (a.IsEmpty())
			{
				cout << "В очереди нет элементов." << endl;
				system("pause");
			}
			else
			{
				cout << "Элементы очереди:" << endl;
				while (iter)
				{
					cout << a.getInf(iter) << ' ';
					iter = a.getNext(iter);

				}
				cout << endl;
				system("pause");
			}

			system("cls");
			break;

		}

		case 7:
			cout << "Введите имя файла\n";
			char name_file[30];
			cin >> name_file;
			f.open(name_file, ios::in);
			if (!f.is_open())
			{
				cout << "Ошибка!Такого файла не существует, создайте или введите другое название" << endl;
				system("pause");
				cin.clear();
				cin.ignore();
				system("cls");
				break;
			}
			while (!f.eof()) {
				f >> data;
				a.push(data);
			}
			f.close();
			cout << "Элементы были считаны из файла" << endl;
			system("pause");
			cin.clear();
			cin.ignore();
			system("cls");
			break;

		case 8:
			flagempty = a.IsEmpty();
			if (flagempty)
			{
				cout << "Очередь пуста, невозможно создать файл" << endl << endl;
				system("pause");
				cin.clear();
				cin.ignore();
				system("cls");
				flagempty = false;
				break;
			}

			cout << "Введите имя файла\n";
			char name_file1[30];
			cin >> name_file1;
			f1.open(name_file1, ios::out | ios::trunc);
			if (!f1.is_open())
			{
				cout << "Ошибка при открытии файла" << endl;
				system("pause");
				cin.clear();
				cin.ignore();
				system("cls");
				break;
			}

			iter = a.getHead();
			iter_tail = a.getTail();
			while (iter) {
				data = a.getInf(iter);
				f1 << data;
				if (!(iter == iter_tail))
					f1 << "\n";
				iter = a.getNext(iter);
			}
			cout << "Элементы были добавлены в файл " << name_file1 << endl;
			system("pause");
			cin.clear();
			cin.ignore();
			system("cls");
			f1.close();
			break;
		default: break;
		}
	} while (mn != 0);


	system("pause");
	return 0;
}
