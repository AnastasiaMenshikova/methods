#include "stdafx.h" 
#include "Matrix.h" 
#include <iostream> 
#include <fstream> 

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int mn, error, line, column, info;
	Matrix a;
	Matrix::iterater iter;
	setlocale(LC_ALL, "Russian");
	bool fl1;

	do
	{
			cout << "Выберите пункт из меню:" << endl;
			cout << "1)Добавить элемент в матрицу" << endl;
			cout << "2)Удаление элемента из матрицы" << endl;
			cout << "3)Удаление матрицы" << endl;
			cout << "4)Расстояние между городами" << endl;
			cout << "5)Просмотр матрицы по строкам" << endl;
			cout << "6)Просмотр матрицы по столбцам" << endl;
			cout << "Нажмите 0 для выхода из программы" << endl << endl;

			cin >> mn;
			if (mn < 0 || mn>6)
			{
				cout << "Ошибка! Необходимо ввести число от 1 до 6 или 0 для выхода." << endl << endl;
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
				while (1)
				{
					cout << "Введите номер первого города:" << endl;
					if ((cin >> line) && (cin.good()))
					{
						break;
					}
					else
					{
						cout << "\n Некорректное значение. Выполните операцию заново." << endl;
						system("pause");
						cin.clear();
						cin.ignore();
						system("cls");
					}
				}

				while (1)
				{
					cout << "Введите номер второго города:" << endl;
					if ((line > 0) && (cin >> column) && (cin.good()))
					{
						break;
					}
					else
					{
						cout << "\n Некорректное значение. Выполните операцию заново." << endl;
						system("pause");
						system("cls");
						cin.clear();
						cin.ignore();
					}


				}

				while (1)
				{
					cout << "Введите расстояние между городами:" << endl;
					if ((line > 0) && (column > 0) && (cin >> info) && (cin.good()))
					{

						a.Push(line, column, info);
						system("cls");
						cout << "Номер первого города: " << line << endl;
						cout << "Номер второго города: " << column << endl;
						cout << "Расстояние между городами: " << info << endl << endl;
						cout << "Успешно добавлено." << endl << endl;
						system("pause");
						system("cls");
						break;
					}
					else
					{
						cout << "\n Некорректное значение. Выполните операцию заново." << endl;
						system("pause");
						cin.clear();
						cin.ignore();
						system("cls");
					}
				}
				break;
			}
			case 2:
			{
				system("cls");
				if (a.IsEmptyMatrix())
				{
					cout << "Элементов в матрице нет" << endl;
					system("pause");
					system("cls");
					break;
				}
				else
				{
					while (1)
					{
						cout << "Введите номер первого города:" << endl;
						if ((cin >> line) && (cin.good()))
						{
							break;
						}
						else
						{
							cout << "\n Некорректное значение. Выполните операцию заново." << endl;
							system("pause");
							cin.clear();
							cin.ignore();
							system("cls");
						}
					}

					while (1)
					{
						cout << "Введите номер второго города:" << endl;
						if ((line > 0) && (cin >> column) && (cin.good()))
						{
							break;
						}
						else
						{
							cout << "\n Некорректное значение. Выполните операцию заново." << endl;
							system("pause");
							system("cls");
							cin.clear();
							cin.ignore();
						}


					}

					if (a.IsExistVector(line, column))
					{
						system("cls");
						a.Del(line, column);
						cout << "Элемент удален из матрицы" << endl;
						system("pause");
						system("cls");
						break;
					}
					else
					{
						system("cls");
						cout << "Маршрута между этими городами не существует" << endl;
						system("pause");
						system("cls");
						break;
					}

				}

			}

			case 3:
			{
				system("cls");
				if (a.IsEmptyMatrix())
				{
					cout << "Элементов в матрице нет" << endl;
					system("pause");
					system("cls");
					break;
				}
				else
				{
					system("cls");
					a.DelMatrix();
					cout << "Матрица удалена" << endl;
					system("pause");
					system("cls");
					break;
				}

			}

			case 4:
			{
				system("cls");
				if (a.IsEmptyMatrix())
				{
					cout << "Элементов в матрице нет" << endl;
					system("pause");
					system("cls");
					break;
				}
				else
				{
					while (1)
					{
						cout << "Введите номер первого города:" << endl;
						if ((cin >> line) && (cin.good()))
						{
							break;
						}
						else
						{
							cout << "\n Некорректное значение. Выполните операцию заново." << endl;
							system("pause");
							cin.clear();
							cin.ignore();
							system("cls");
						}
					}

					while (1)
					{
						cout << "Введите номер второго города:" << endl;
						if ((line > 0) && (cin >> column) && (cin.good()))
						{
							break;
						}
						else
						{
							cout << "\n Некорректное значение. Выполните операцию заново." << endl;
							system("pause");
							system("cls");
							cin.clear();
							cin.ignore();
						}


					}

					if (a.IsExistVector(line, column))
					{
						system("cls");
						cout << "Расстояние между городами: " << a.Search(line, column) << endl;
						system("pause");
						system("cls");
						break;
					}
					else
					{
						system("cls");
						cout << "Маршрута между этими городами не существует" << endl;
						system("pause");
						system("cls");
						break;
					}

				}

			}

			case 5:
			{
				system("cls");
				iter = a.GetLineHead();
				if (a.IsEmptyMatrix())
				{
					cout << "Элементов в матрице нет" << endl;
				}
				else
				{
					cout << "Строка - Столбец : Расстояние между городами" << endl;
					while (iter) {

						iter = a.GetRight(iter);

						if (iter->column == 0)
						{
							iter = a.GetDown(iter);
						}
						else
						{
							cout << a.GetLine(iter) << " - " << a.GetColumn(iter) << " : " << a.GetInfo(iter) << endl;
						}
					}
				}
				system("pause");
				system("cls");
				break;
			}



			case 6:
			{
				system("cls");
				iter = a.GetColumnHead();
				if (a.IsEmptyMatrix())
				{
					cout << "Элементов в матрице нет" << endl;
				}
				else
				{
					cout << "Строка - Столбец : Расстояние между городами" << endl;
					while (iter) {

						iter = a.GetDown(iter);

						if (iter->line == 0)
						{
							iter = a.GetRight(iter);
						}
						else
						{
							cout << a.GetLine(iter) << " - " << a.GetColumn(iter) << " : " << a.GetInfo(iter) << endl;
						}
					}
				}
				system("pause");
				system("cls");
				break;
			}



			}
		} while (mn != 0);

	system("pause");
	return 0;
}
