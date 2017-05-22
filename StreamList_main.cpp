#include "stdafx.h" 
#include "StreamList.h" 
#include <iostream> 
#include <fstream> 


using namespace std;

int main()
{
	int mn, error; // data - информационное поле
	char Name[20], Number[20];
	StreamList a;
	StreamList::iterater iter, iter_tail;
	bool flagempty = false;
	ifstream f;
	ofstream f1;
	setlocale(LC_ALL, "Russian");
	do
	{
		cout << "Выберите пункт меню:" << endl;
		cout << "1)Добавить элемент в список" << endl;
		cout << "2)Удаление элемента по номеру телефона" << endl;
		cout << "3)Удаление элемента по фамилии" << endl;
		cout << "4)Поиск номера телефона по фамилии" << endl;
		cout << "5)Поиск фамилии по номеру телефона" << endl;
		cout << "6)Вывести на экран список по возрастанию фамилий" << endl;
		cout << "7)Вывести на экран список по возрастанию номеров телефона" << endl;
		cout << "8)Вывести на экран список по убыванию фамилий" << endl;
		cout << "9)Вывести на экран список по убыванию номеров телефона" << endl;
		cout << "10)Очистить список" << endl;
		cout << "11)Считавание элементов списка из файла" << endl;
		cout << "12)Создать файл и записать туда элементы списка" << endl;
		cout << "Нажмите 0 для выхода из программы" << endl << endl;
		
		cin >> mn;
		if (mn < 0 || mn>12)
		{
			cout << "Ошибка! Необходимо ввести число от 1 до 10 или 0 для выхода." << endl << endl;
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
			cout << "Введите фамилию:" << endl;
			cin >> Name;
			cout << "Введите номер телефона:" << endl;
			cin >> Number;
			a.Push(Name, Number);
			system("cls");
			break;
		}

		case 2:
		{
			{
				system("cls");
				if (a.IsEmpty())
				{
					cout << "Невозможно удалить. Список пуст." << endl << endl;
					system("pause");
					system("cls");
					break;
				}
				else
				{
					cout << "Введите номер телефона:" << endl;
					cin >> Number;
					if (a.ExistNumber(Number))
					{
						system("cls");
						a.DelNumber(Number);
						cout << "Элемент удален" << endl << endl;
						system("pause");
						system("cls");
						break;
					}
					else
					{
						system("cls");
						cout << "В списке такого номера нет" << endl << endl;
						system("pause");
						system("cls");
						break;
					}

				}

			}


		case 3:
		{
			system("cls");
			if (a.IsEmpty())
			{
				cout << "Невозможно удалить. Список пуст." << endl << endl;
				system("pause");
				system("cls");
				break;
			}
			else
			{
				cout << "Введите фамилию:" << endl;
				cin >> Name;
				if (a.ExistName(Name))
				{
					system("cls");
					a.DelName(Name);
					cout << "Элемент удален" << endl;
					system("pause");
					system("cls");
					break;
				}
				else
				{
					system("cls");
					cout << "В списке нет такой фамилии" << endl;
					system("pause");
					system("cls");
					break;
				}
			}
		}
			
		case 4:

			system("cls");
			if (a.IsEmpty())
			{
				cout << "Список пуст. Добавьте элементы или завершите работу" << endl << endl;
				system("pause");
				system("cls");
				break;
			}
			else
			{
				cout << "Введите фамилию:" << endl;
				cin >> Name;
				if (a.ExistName(Name))
				{
					cout << endl;
					cout << "Фамилия найдена. Номер телефона:" << endl;
					cout << a.SearchNumber(Name) << endl;
					system("pause");
					system("cls");
					break;
				}
				else
				{
					system("cls");
					cout << "В списке нет такой фамилии" << endl;
					system("pause");
					system("cls");
					break;
				}
			}
		}

		case 5:
		{
			system("cls");
			if (a.IsEmpty())
			{
				cout << "Список пуст. Добавьте элементы или завершите работу" << endl << endl;
				system("pause");
				system("cls");
				break;
			}
			else
			{
				cout << "Введите номер телефона:" << endl;
				cin >> Number;
				if (a.ExistNumber(Number))
				{
					cout << endl;
					cout << "Номер телефона найден. Фамилия:" << endl;
					cout<<a.SearchName(Number)<<endl<<endl;
					system("pause");
					system("cls");
					break;
				}
				else
				{
					system("cls");
					cout << "В списке нет такого номера телефона." << endl << endl;
					system("pause");
					system("cls");
					break;
				}
			}
		}

		case 6:
		{
			system("cls");
			iter = a.GetHeadName();
			if (a.IsEmpty())
			{
				cout << "Список пуст" <<endl<< endl;
			}
			else
			{
				cout << "Фамилия - Номер телефона:" << endl;
				while (iter) {
					cout << a.GetNameInf(iter)<<" - "<< a.GetNumberInf(iter) << endl;
					iter = a.GetNextName(iter);
				}
			}
			cout << endl;
			system("pause");
			system("cls");
			break;
		}
		case 7:
		{
			system("cls");
			iter = a.GetNumberHead();
			if (a.IsEmpty())
			{
				cout << "Список пуст" <<endl<< endl;
			}
			else
			{
				cout << "Фамилия - Номер телефона:" << endl;
				while (iter) {
					cout << a.GetNameInf(iter) << " - " << a.GetNumberInf(iter) << endl;
					iter = a.GetNextNumber(iter);
				}
			}
			system("pause");
			system("cls");
			break;
		}

		case 8:
		{
			system("cls");
			iter = a.GetTailName();
			if (a.IsEmpty())
			{
				cout << "Список пуст" << endl << endl;
			}
			else
			{
				cout << "Фамилия - Номер телефона:" << endl;
				while (iter) {
					cout << a.GetNameInf(iter) << " - " << a.GetNumberInf(iter) << endl;
					iter = a.GetPrevName(iter);
				}
			}
			system("pause");
			system("cls");
			break;
		}
		case 9:
		{
			system("cls");
			iter = a.GetNumberTail();
			if (a.IsEmpty())
			{
				cout << "Список пуст" << endl << endl;
			}
			else
			{
				cout << "Фамилия - Номер телефона:" << endl;
				while (iter) {
					cout << a.GetNameInf(iter) << " - " << a.GetNumberInf(iter) << endl;
					iter = a.GetPrevNumber(iter);
				}
			}
			system("pause");
			system("cls");
			break;
		}

		case 10:
		{
			system("cls");
			if (a.IsEmpty())
			{
				cout << "Нечего удалять. Список пуст"<< endl << endl;
				system("pause");
				system("cls");
				break;
			}
			else
			{
				a.DelList();
				cout << "Список удален" << endl << endl;
				system("pause");
				system("cls");
				break;
			}

		}

		case 11:
			cout << "Введите имя файла\n";
			char name_file[30];
			cin >> name_file;
			f.open(name_file, ios::in);
			if (!f.is_open())
			{
				cout << "Ошибка!Такого файла не существует, создайте или введите другое название" << endl << endl;
				system("pause");
				cin.clear();
				cin.ignore();
				system("cls");
				break;
			}
			while (!f.eof()) {
				f >> Name >> Number;
				a.Push(Name, Number);
			}
			f.close();
			cout << "Элементы были считаны из файла" << endl << endl;
			system("pause");
			cin.clear();
			cin.ignore();
			system("cls");
			break;

		case 12:
			flagempty = a.IsEmpty();
			if (flagempty)
			{
				cout << "Список пуст, невозможно создать файл" << endl << endl;
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
				cout << "Ошибка при открытии файла" << endl << endl;
				system("pause");
				cin.clear();
				cin.ignore();
				system("cls");
				break;
			}

			iter = a.GetHeadName();
			iter_tail = a.GetTailName();
			while (iter) {
				f1 << a.GetNameInf(iter) << "\n"<< a.GetNumberInf(iter);
				if (!(iter == iter_tail))
					f1 << "\n";
				iter = a.GetNextName(iter);
			
			}
			cout << "Элементы были добавлены в файл " << name_file1 << endl << endl;
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
