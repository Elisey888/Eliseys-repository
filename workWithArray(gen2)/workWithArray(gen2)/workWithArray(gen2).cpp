#include <iostream>
#include <fstream>
#include <Windows.h>
#include <iomanip>

const int SIZEARRAY = 5;
using namespace std;

void validationForSaveMenu(int& x);
void validationForMenu(int& x);
int mainMenu();
int secondMenu();
int menuForChange();
int menuForSave();
int menuForReturn();
int menuForExit();
void printArr(double arr[SIZEARRAY]);
void printArr(double* arr, int size);
int fileCheck(std::ifstream& file);
void fillArr(int choice, double arr[SIZEARRAY], istream& stream);
void fillArr(int choice, double* arr, int size, istream& stream);
void Save(double arr[SIZEARRAY]);
void Save(double* arr, int size);
void elementChange(double arr[SIZEARRAY]);
void elementChange(double* arr, int size);
void copyArray(double arr2[SIZEARRAY], double arr[SIZEARRAY]);
void copyDynamicArray(double* arr2, double* arr, int size);
void taskStaticArray(int choiceForMainMenu, int choiceForSecondMenu);
void taskDynamicArray(int choiceForMainMenu, int choiceForSecondMenu);

int main()
{
	SetConsoleOutputCP(1251);
	int choiceForMainMenu;
	int choiceForSecondMenu = 0;
	do
	{
		choiceForMainMenu = mainMenu();
		if (choiceForMainMenu == 1)
		{
			taskStaticArray(choiceForMainMenu, choiceForSecondMenu);
		}
		if (choiceForMainMenu == 2)
		{
			taskDynamicArray(choiceForMainMenu, choiceForSecondMenu);
		}
		if (menuForExit() == 1)
		{
			choiceForMainMenu = 4;
		}
		cout << "\n";

	} while (choiceForMainMenu != 4);
	cin.get();
	return 0;
}

void validationForMenu(int& x)
{
	while (!(cin >> x) || x > 3 || x < 1)
	{
		cout << "Ошибка ввода!\n";
		cin.clear();
		cin.ignore(255, '\n');
		cout << "\nВыберите пункт меню:\n";
	}
}
void validationForSaveMenu(int& x)
{
	while (!(cin >> x) || x > 2 || x < 1)
	{
		cout << "Ошибка ввода!\n";
		cin.clear();
		cin.ignore(255, '\n');
		cout << "\nВыберите пункт меню:\n";
	}
}
int mainMenu()
{
	cout << "Выберите пункт меню\n";
	cout << "1. Работа со статическим массивом.\n";
	cout << "2. Работа с динамическим масивом.\n";
	cout << "3. Завершить работу.\n-> ";

	int choice = 0;
	validationForMenu(choice);

	return choice;
}
int secondMenu()
{
	cout << "Выберите пункт меню\n";
	cout << "Заполнить массив: \n";
	std::cout << "1. Из текстового файла.\n";
	std::cout << "2. С клавиатуры.\n";
	std::cout << "3. Случайным образом.\n-> ";

	int choice = 0;
	validationForMenu(choice);

	return choice;
}
int menuForChange()
{
	cout << "Хотите ли вы изменить массив?\n";
	cout << "1. Да, хочу полностью поменять его\n";
	cout << "2. Да, хочу поменять отдельные элементы\n";
	cout << "3. Нет\n";
	int choice = 0;
	validationForMenu(choice);

	return choice;
}
int menuForSave()
{
	cout << "Сохранить изменения?\n";
	cout << "1. Да\n";
	cout << "2. Нет\n";

	int choice = 0;
	validationForSaveMenu(choice);

	return choice;
}
int menuForReturn()
{
	cout << "Хотите ли вы вернуть/отменить изменения?\n";
	cout << "1. Да, хочу отменить изменения полностью\n";
	cout << "2. Да, хочу вернуть изменения на шаг назад\n";
	cout << "3. Нет\n";

	int choice = 0;
	validationForMenu(choice);

	return choice;
}
int menuForExit()
{
	int Exit;
	cout << "\nЗавершить работу? Да - 1; Нет - 2 \n->";

	int choice = 0;
	validationForSaveMenu(choice);

	return choice;
}
void printArr(double arr[SIZEARRAY])
{
	for (int i = 0; i < SIZEARRAY; ++i)
	{
		cout << std::setw(4) << arr[i];
		cout << "\n\n";
	}
}

void printArr(double* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << std::setw(4) << *(arr + i);
		cout << '\n';
	}
}
int fileCheck(ifstream& file)
{
	int result = 1;
	if (!file)
		result = -1;
	else
		if (file.peek() == EOF)
			result = 0;
	return result;
}
void fillArr(int choice, double arr[SIZEARRAY], std::istream& stream)
{
	if (choice == 3)
	{
		srand(GetTickCount64());
		for (int i = 0; i < SIZEARRAY; ++i)
		{
			arr[i] = rand() % 100;
			int sgn = rand() % 2;
			if (sgn == 1)
				arr[i] *= -1;
		}
	}
	else
	{
		for (int i = 0; i < SIZEARRAY; ++i)
		{
			stream >> arr[i];
		}
	}
	printArr(arr);
}
void fillArr(int choice, double* arr, int size, std::istream& stream)
{
	if (choice == 3)
	{
		srand(GetTickCount64());
		for (int i = 0; i < size; ++i)
		{
			*(arr + i) = rand() % 100;
			int sgn = rand() % 2;
			if (sgn == 1)
				*(arr + i) *= -1;
		}
	}
	else
	{
		for (int i = 0; i < size; ++i)
		{
			stream >> arr[i];
		}

		printArr(arr, size);
	}
}
void copyArray(double arr2[SIZEARRAY], double arr[SIZEARRAY])
{
	for (int i = 0; i < SIZEARRAY; ++i)
	{
		arr2[i] = arr[i];
	}
}
void copyDynamicArray(double* arr2, double* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		arr2[i] = arr[i];
	}

}
void Save(double arr[SIZEARRAY])
{
	ofstream file("FileForSave.txt");
	for (int i = 0; i < SIZEARRAY; ++i)
	{
		file << arr[i];
		file << " ";
	}
	file.close();
}
void Save(double* arr, int size)
{
	ofstream file("FileForSave.txt");
	for (int i = 0; i < size; ++i)
	{
		file << arr[i];
		file << " ";
	}
	file.close();
}
void elementChange(double arr[SIZEARRAY])
{
	while (1)
	{
		int choiceInMenuElementChange;
		std::cout << "Изменить элемент далее - 1\n Не менять далее - 2\n";
		std::cin >> choiceInMenuElementChange;
		if (choiceInMenuElementChange == 1)
		{
			int num;
			std::cout << "Введите номер элемента, который хотите изменить(меньше " << SIZEARRAY << ")" << "\n";
			std::cin >> num;
			std::cout << "Введите число, на которое поменять элемент\n";
			double chislo;
			std::cin >> chislo;
			arr[num] = chislo;
		}
		if (choiceInMenuElementChange == 2) break;
	}
}
void elementChange(double* arr, int size)
{
	while (1)
	{
		int choiceInMenuElementChange;
		std::cout << "Изменить элемент далее - 1\n Не менять далее - 2\n";
		std::cin >> choiceInMenuElementChange;
		if (choiceInMenuElementChange == 1)
		{
			int num;
			std::cout << "Введите номер элемента, который хотите изменить(меньше " << SIZEARRAY << ")" << "\n";
			std::cin >> num;
			std::cout << "Введите число, на которое поменять элемент\n";
			double chislo;
			std::cin >> chislo;
			arr[num] = chislo;
		}
		if (choiceInMenuElementChange == 2) break;
	}
}

void taskStaticArray(int choiceForMainMenu, int choiceForSecondMenu)
{
	if (choiceForMainMenu == 1)
	{
		double a[SIZEARRAY];
		double b[SIZEARRAY];
		double c[SIZEARRAY];
		choiceForSecondMenu = secondMenu();
		std::ifstream file("FileForSave.txt");
		if (choiceForSecondMenu == 1)
		{
			if (fileCheck(file) == 1)
			{
				fillArr(choiceForSecondMenu, a, file);
				copyArray(b, a);
			}
			else
			{
				if (fileCheck(file) == -1)
					cout << "Файл не найден\n";
				else
					cout << "Файл пустой\n";
			}
		}
		else
			fillArr(choiceForSecondMenu, a, cin);
		copyArray(b, a);
		Save(a);
		if (choiceForSecondMenu != 1 || fileCheck(file) == 1)
		{
			int choiceForThirdMenu;
			choiceForThirdMenu = menuForChange();
			if (choiceForThirdMenu == 1)
			{
				choiceForSecondMenu = secondMenu();
				fillArr(choiceForSecondMenu, a, cin);
			}
			if (choiceForThirdMenu == 2)
			{
				elementChange(a);
			}
			copyArray(c, a);
			int choiceSave;
			choiceSave = menuForSave();
			if (choiceSave == 1) Save(a);
			printArr(a);
			int choiseForReturnMenu;
			choiseForReturnMenu = menuForReturn();
			if (choiseForReturnMenu == 1)
			{
				printArr(b);
				choiceSave = menuForSave();
				if (choiceSave == 1) Save(b);
				cout << "Готово";
			}
			if (choiseForReturnMenu == 2)
			{
				printArr(c);
				choiceSave = menuForSave();
				if (choiceSave == 1) Save(c);
				cout << "Готово";
			}
		}
	}




}

void taskDynamicArray(int choiceForMainMenu, int choiceForSecondMenu)
{
	int size;
	cout << "Введите размер массива\n->";
	cin >> size;
	double* a = new double[size];
	double* b = new double[size];
	double* c = new double[size];
	choiceForSecondMenu = secondMenu();
	ifstream file("FileForSave.txt");
	if (choiceForSecondMenu == 1)
	{
		if (fileCheck(file) == 1)
		{
			fillArr(choiceForSecondMenu, a, size, file);
			copyDynamicArray(b, a, size);
		}
		else
		{
			if (fileCheck(file) == -1)
				cout << "Файл не найден\n";
			else
				cout << "Файл пустой\n";
		}
	}
	else
		fillArr(choiceForSecondMenu, a, size, cin);
	copyDynamicArray(b, a, size);
	Save(a, size);
	if (choiceForSecondMenu != 1 || fileCheck(file) == 1)
	{
		int choiceForThirdMenu;
		choiceForThirdMenu = menuForChange();
		if (choiceForThirdMenu == 1)
		{
			choiceForSecondMenu = secondMenu();
			fillArr(choiceForSecondMenu, a, size, cin);
		}
		if (choiceForThirdMenu == 2)
		{
			elementChange(a, size);
		}
		copyDynamicArray(c, a, size);
		int choiceSave;
		choiceSave = menuForSave();
		if (choiceSave == 1) Save(a, size);
		printArr(a, size);
		int choiseForReturnMenu;
		choiseForReturnMenu = menuForReturn();
		if (choiseForReturnMenu == 1)
		{
			printArr(b, size);
			choiceSave = menuForSave();
			if (choiceSave == 1) Save(b, size);
			cout << "Готово";
		}
		if (choiseForReturnMenu == 2)
		{
			printArr(c, size);
			choiceSave = menuForSave();
			if (choiceSave == 1) Save(c, size);
			cout << "Готово";
		}
	}


}