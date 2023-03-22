#include<iostream>
#include<fstream>
#include<Windows.h>
#include <iomanip>

const int n = 5;
int menu1();
void print_arr(double arr[n]);
void print_arr(double* arr, int size);

int main()
{
	SetConsoleOutputCP(1251);
	int choice1;
	do
	{
		choice1 = menu1();
		if (choice1 != 3)
		{
			if (choice1 == 1)
			{
				double a[n];
				double b[n];
				int v;
				std::cout << "Заполнить массив: \n с клавиатуры - 1; \n случайным образом - 2 \n ->";
				std::cin >> v;
				if (v == 1)
				{
					std::cout << "Введите массив: \n";
					for (int i = 0; i < n; ++i)
					{
						std::cin >> a[i];
						b[i] = a[i];
						std::cout << "\n";
					}
				}
				if (v == 2)
				{
					for (int i = 0; i < n; ++i)
					{
						a[i] = rand() % 100;
						int sgn = rand() % 2;
						if (sgn == 1)
							a[i] *= -1;
						b[i] = a[i];
					}
				}
				print_arr(b);
				std::cout << "\n Хотите ли вы изменить массив? y - Yes, n - No\n";
				char ch;
				std::cin >> ch;
				if (ch == 'y')
				{
					std::cout << "изменить весь массив вручную или выборочные элементы?\n 1-весь\n 2-отдельно \n";
					int v1;
					std::cin >> v1;
					if (v1 == 1)
					{
						std::cout << "Введите массив: \n";
						for (int i = 0; i < n; ++i)
						{
							std::cin >> a[i];
							std::cout << "\n";
						}
						print_arr(a);

					}
					if (v1 == 2)
					{
						while (1)
						{
							int v2;
							std::cout << "Изменить элемент далее - 1\n Не менять далее - 2\n";
							std::cin >> v2;
							if (v2 == 1)
							{
								int num;
								std::cout << "Введите номер элемента, который хотите изменить(меньше " << n << ")" << "\n";
								std::cin >> num;
								std::cout << "Введите число, на которое поменять элемент\n";
								double chislo;
								std::cin >> chislo;
								a[num] = chislo;
							}
							if (v2 == 2) break;
						}

					}
					std::cout << "Хотите ли вы отменить изменения? \n Да - 1 \n Нет - 2\n";
					int v3;
					std::cin >> v3;
					if (v3 == 1)
					{
						print_arr(b);
					}
					if (v3 == 2)
					{
						print_arr(a);
					}

				}
				if (ch == 'n')
				{
					print_arr(b);
				}


			}


			if (choice1 == 2)
			{
				int size;
				std::cout << "Введите размер массива\n->";
				std::cin >> size;
				double* arr = new double[size];
				double* arr1 = new double[size];
				int v;
				std::cout << "Заполнить массив: \n с клавиатуры - 1; \n случайным образом - 2 \n ->";
				std::cin >> v;
				if (v == 1)
				{
					std::cout << "Введите массив: \n";
					for (int i = 0; i < size; ++i)
					{
						std::cin >> arr[i];
						arr1[i] = arr[i];
						std::cout << "\n";
					}
				}
				if (v == 2)
				{
					for (int i = 0; i < size; ++i)
					{
						arr[i] = rand() % 100;
						int sgn = rand() % 2;
						if (sgn == 1)
							arr[i] *= -1;
						arr1[i] = arr[i];
					}
				}
				print_arr(arr1, size);
				std::cout << "\n Хотите ли вы изменить массив? y - Yes, n - No\n";
				char ch;
				std::cin >> ch;
				if (ch == 'y')
				{
					std::cout << "изменить весь массив вручную или выборочные элементы?\n 1-весь\n 2-отдельно \n";
					int v1;
					std::cin >> v1;
					if (v1 == 1)
					{
						std::cout << "Введите массив: \n";
						for (int i = 0; i < size; ++i)
						{
							std::cin >> arr[i];
							std::cout << "\n";
						}
						print_arr(arr, size);

					}
					if (v1 == 2)
					{
						while (1)
						{
							int v2;
							std::cout << "Изменить элемент далее - 1\n Не менять далее - 2\n";
							std::cin >> v2;
							if (v2 == 1)
							{
								int num;
								std::cout << "Введите номер элемента, который хотите изменить(меньше " << size << ")" << "\n";
								std::cin >> num;
								std::cout << "Введите число, на которое поменять элемент\n";
								double chislo;
								std::cin >> chislo;
								arr[num] = chislo;
							}
							if (v2 == 2) break;
						}

					}
					std::cout << "Хотите ли вы отменить изменения? \n Да - 1 \n Нет - 2\n";
					int v3;
					std::cin >> v3;
					if (v3 == 1)
					{
						print_arr(arr1, size);
					}
					if (v3 == 2)
					{
						print_arr(arr, size);
					}

				}
				if (ch == 'n')
				{
					print_arr(arr1, size);
				}


			}




		}
		char isExit;
		std::cout << "\nЗавершить работу?(Y/N - любой символ)\n->";
		std::cin >> isExit;
		if (isExit == 'y' || isExit == 'Y')
			choice1 = 3;
		std::cout << "\n";

	} while (choice1 != 3);
	std::cin.get();
	return 0;
}


int menu1()
{
	std::cout << "Выберите пункт меню\n";
	std::cout << "1. Работа со статическим массивом.\n";
	std::cout << "2. Работа с динамическим масивом.\n";
	std::cout << "3. Завершить работу.\n-> ";

	int choice = 0;
	std::cin >> choice;
	return choice;
}


void print_arr(double arr[n])
{
	for (int i = 0; i < n; ++i)
	{
		std::cout << std::setw(4) << arr[i];
		std::cout << "\n\n";
	}
}

void print_arr(double* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << std::setw(4) << *(arr + i);
		std::cout << "\n";
	}
}