#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <Windows.h>
#include <string>
#include <string.h>
#include <fstream>
#include <functional>
#include <stdio.h>
#include <cstdio>


const int SEM = 8, SUB = 5, MAX_COUNT_OF_STUDENTS = 100;


struct Marks
{
	std::string Subject{};
	int Mark[SEM]{};
};

struct Student
{
	std::string Name{};
	int Course{};
	int Group{};
	Marks Mark[SUB];
	std::string FormStudying{};
};


void pickAndCheckErr(const char* message, int& x);
void pickAndCheck(const char* message, int& x, const int a, const int b);

bool ifFileExist(const char* nameOfFile, const int choice);
void pickNameOfFile(char* nameOfFile, const int choice, const bool flagOfCheck);
void renameFile(const char* nameOfFile, char* nameOfNewFile, const int choiceFile);

bool readStudentFromFile(std::ifstream& file, Student& student);
void readStudentFromBinaryFile(std::ifstream& binaryFile, Student& student);
//, std::ifstream::streampos sizeOfFile
void readFile(Student* listOfStudents, int& sizeOfList, const char* nameOfFile);
void readBinaryFile(Student* listOfStudents, int& sizeOfList, const char* nameOfFile);
void readFileOrBinaryFile(Student* listOfStudents, int& sizeOfList, const int choiceFile, const char* nameOfFile);

void createFile(Student* listOfStudents, const int sizeOfList, const char* nameOfFile);
void createBinaryFile(Student* listOfStudents, const int sizeOfList, const char* nameOfFile);
void createFileOrBinaryFile(Student* listOfStudents, const int sizeOfList, const int choiceFile, const char* nameOfFile);

int choiceSubject(Student student);
bool checkMarks(Student student, const int chosenSubject);
bool checkMarks(Student student, const int chosenSubject);
void printBadStudent(Student student, const int chosenSubject);
bool searchBadStudents(const int chosenSubject, Student* listOfStudents, const int sizeOfList);
//void mainTask(const int choiceFile, const char* nameOfFile);

void printStudent(Student student, const bool flagOfPrint);
void printListOfStudents(const int choiceFile, const char* nameOfFile);

bool compareStudents(Student student1, Student student2);
void swapStudents(Student& student1, Student& student2);
void swapNameOrFormStudying(std::string& str1, std::string& str2);
void swapElement(int& element1, int& element2);
void sortingListOfStudents(const int choiceFile, const char* nameOfFile);

void addStudentsFromConsole(Student* listOfStudents, int& sizeOfList);
void addStudentsFromFile(Student* listOfStudents, int& sizeOfList);
void addStudentsFromBinaryFile(Student* listOfStudents, int& sizeOfList);
void addStudents(const int choiceFile, const char* nameOfFile);

void editStudentFromConsole(Student& student);
void editStudentsFromConsole(Student* listOfStudents, const int sizeOfList, bool& flagOfStudents);
void editStudents(const int choiceFile, char* nameOfFile);

void deleteStudent(Student* listOfStudents, int& sizeOfList, const int count);
void deleteStudentsFromConsole(Student* listOfStudents, int& sizeOfList, bool& flagOfStudent);
void deleteStudents(const int choiceFile, char* nameOfFile);


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choiceFile = 1;

	while (choiceFile != 0)
	{
		int sizeOfList = 0, flagOfRecursion;

		pickAndCheck("Заполнить список из обычного файла >> 1\nЗаполнить список из бинарного файла >> 2\nЗавершить выполнение программы >> 0\n", choiceFile, 0, 2);

		if (choiceFile != 0)
		{
			char nameOfFile[255] = "";

			pickNameOfFile(nameOfFile, choiceFile, true);

			pickAndCheck("\nРешить основную задачу для текущего списка студентов >> 1\nВывести текущий список студентов в консоль >> 2\nОтсортировать текущий  список студентов >> 3\nДобавить запись в текущий список студентов >> 4\nИзменить запись в текущем списке студентов >> 5\nУдалить запись в текущем списке студентов >> 6\nЗакончить работу с этим списком студентов >> 0\n", flagOfRecursion, 0, 6);

			system("cls");

			switch (flagOfRecursion)
			{
			case 1:
				/*mainTask(choiceFile, nameOfFile);*/
				break;
			case 2:
				printListOfStudents(choiceFile, nameOfFile);
				break;
			case 3:
				sortingListOfStudents(choiceFile, nameOfFile);
				break;
			case 4:
				addStudents(choiceFile, nameOfFile);
				break;
			case 5:
				editStudents(choiceFile, nameOfFile);
				break;
			case 6:
				deleteStudents(choiceFile, nameOfFile);
				break;
			default:
				break;
			}
		}
	}

	return 0;
}


void pickAndCheckErr(const char* message, int& x)
{
	std::cout << message;
	while (!(std::cout << ">> ", std::cin >> x))
	{
		std::cout << "\nОшибка ввода! Повторите ввод\n";
		std::cin.clear();
		std::cin.ignore(255, '\n');
	}
}

void pickAndCheck(const char* message, int& x, const int a, const int b)
{
	bool flag = true;

	std::cout << message;

	while (flag)
	{
		pickAndCheckErr("", x);

		if (x >= a && x <= b)
			flag = false;
		else
		{
			std::cout << "\nОшибка ввода! Повторите ввод\n";
			std::cin.clear();
			std::cin.ignore(255, '\n');
		}
	}
}


bool ifFileExist(const char* nameOfFile, const int choice)
{
	bool result = false;

	if (choice == 1)
	{
		std::ifstream file(nameOfFile);

		if (file.is_open())
			result = true;

		file.close();
	}

	if (choice == 2)
	{
		std::ifstream file(nameOfFile, std::ios::binary);

		if (file.is_open())
			result = true;

		file.close();
	}

	return result;
}

void pickNameOfFile(char* nameOfFile, const int choiceFile, const bool flagOfCheck)
{
	bool flagOfFile = false;

	while (!flagOfFile)
	{
		std::cout << "\nВведите имя файла >> ";
		std::cin >> nameOfFile;

		if (choiceFile != 0)
			flagOfFile = ifFileExist(nameOfFile, choiceFile);
		else
			flagOfFile = true;

		if (!flagOfCheck)
			flagOfFile = true;

		if (!flagOfFile)
			std::cout << "Файла с таким именем не существует или он не может быть открыт! Повторите ввод.\n";
	}
}

void renameFile(const char* nameOfFile, char* nameOfNewFile, const int choiceFile)
{
	bool flagOfRename = false;

	while (!flagOfRename)
	{
		pickNameOfFile(nameOfNewFile, choiceFile, false);

		if (rename(nameOfFile, nameOfNewFile) != 0)
		{
			std::cout << "\nОшибка ввода! Повторите ввод\n";
			std::cin.clear();
			std::cin.ignore(255, '\n');
		}
		else
		{
			std::cout << "\nФайл был успешно переименован.\n";

			flagOfRename = true;
		}
	}
}


bool readStudentFromFile(std::ifstream& file, Student& student)
{
	std::string str;

	getline(file, str);
	student.Name = str;

	getline(file, str);
	student.Course = stoi(str);

	getline(file, str);
	student.Group = stoi(str);

	for (int i = 0; i < SUB; ++i)
	{
		getline(file, str);
		student.Mark[i].Subject = str;

		for (int j = 0; j < student.Course * 2; ++j)
			file >> student.Mark[i].Mark[j];

		for (int j = student.Course * 2; j < SEM; ++j)
			student.Mark[i].Mark[j] = 0;

		getline(file, str);
	}

	getline(file, str);
	student.FormStudying = str;

	if (file.eof())
		return false;
	else
		return true;
}

void readStudentFromBinaryFile(std::ifstream& binaryFile, Student& student)
{
	size_t sizeOfBuffer = 0;
	char* buffer = new char[255];

	binaryFile.read((char*)&sizeOfBuffer, sizeof(size_t));
	binaryFile.read(buffer, sizeOfBuffer);
	student.Name = std::string(buffer, sizeOfBuffer);

	binaryFile.read((char*)&student.Course, sizeof(int));

	binaryFile.read((char*)&student.Group, sizeof(int));

	for (int i = 0; i < SUB; ++i)
	{
		binaryFile.read((char*)&sizeOfBuffer, sizeof(size_t));
		binaryFile.read(buffer, sizeOfBuffer);
		student.Mark[i].Subject = std::string(buffer, sizeOfBuffer);

		for (int j = 0; j < student.Course * 2; ++j)
			binaryFile.read((char*)&student.Mark[i].Mark[j], sizeof(int));

		for (int j = student.Course * 2; j < SEM; ++j)
			student.Mark[i].Mark[j] = 0;
	}

	binaryFile.read((char*)&sizeOfBuffer, sizeof(size_t));
	binaryFile.read(buffer, sizeOfBuffer);
	student.FormStudying = std::string(buffer, sizeOfBuffer);

	delete[] buffer;
}

void readFile(Student* listOfStudents, int& sizeOfList, const char* nameOfFile)
{
	std::ifstream file(nameOfFile);

	while (readStudentFromFile(file, listOfStudents[sizeOfList]) && sizeOfList < 100)
		sizeOfList += 1;

	sizeOfList += 1;

	file.close();
}

void readBinaryFile(Student* listOfStudents, int& sizeOfList, const char* nameOfFile)
{
	std::ifstream binaryFile(nameOfFile, std::ios::binary | std::ios::in);

	binaryFile.seekg(0, std::ios_base::end);

	std::ifstream::streampos sizeOfFile = binaryFile.tellg();

	binaryFile.seekg(0, std::ios_base::beg);

	//int count = sizeOfList;

	while (binaryFile.tellg() < sizeOfFile && sizeOfList < 100)
	{
		readStudentFromBinaryFile(binaryFile, listOfStudents[sizeOfList]);

		sizeOfList += 1;
	}

	//sizeOfList = count;

	binaryFile.close();
}

void readFileOrBinaryFile(Student* listOfStudents, int& sizeOfList, const int choiceFile, const char* nameOfFile)
{
	if (choiceFile == 1)
		readFile(listOfStudents, sizeOfList, nameOfFile);

	if (choiceFile == 2)
		readBinaryFile(listOfStudents, sizeOfList, nameOfFile);
}


void createFile(Student* listOfStudents, const int sizeOfList, const char* nameOfFile)
{
	std::ofstream newFile(nameOfFile);

	for (int k = 0; k < sizeOfList; ++k)
	{
		if (k != 0)
			newFile << '\n';

		newFile << listOfStudents[k].Name << '\n';

		newFile << listOfStudents[k].Course << '\n';

		newFile << listOfStudents[k].Group << '\n';

		for (int i = 0; i < SUB; ++i)
		{
			newFile << listOfStudents[k].Mark[i].Subject << '\n';

			for (int j = 0; j < listOfStudents[k].Course * 2; ++j)
				newFile << listOfStudents[k].Mark[i].Mark[j] << ' ';

			newFile << '\n';
		}

		newFile << listOfStudents[k].FormStudying;
	}

	newFile.close();
}

void createBinaryFile(Student* listOfStudents, const int sizeOfList, const char* nameOfFile)
{
	std::ofstream newBinaryFile(nameOfFile, std::ios::binary | std::ios::out);

	for (int k = 0; k < sizeOfList; ++k)
	{
		size_t sizeOfBuffer;
		char* buffer = new char[255];

		buffer = strcpy(new char[listOfStudents[k].Name.length() + 1], listOfStudents[k].Name.c_str());
		sizeOfBuffer = strlen(buffer);

		newBinaryFile.write((char*)&sizeOfBuffer, sizeof(size_t));
		newBinaryFile.write(buffer, sizeOfBuffer);

		newBinaryFile.write((char*)&listOfStudents[k].Course, sizeof(int));

		newBinaryFile.write((char*)&listOfStudents[k].Group, sizeof(int));

		for (int i = 0; i < SUB; ++i)
		{
			buffer = strcpy(new char[listOfStudents[k].Mark[i].Subject.length() + 1], listOfStudents[k].Mark[i].Subject.c_str());
			sizeOfBuffer = strlen(buffer);

			newBinaryFile.write((char*)&sizeOfBuffer, sizeof(size_t));
			newBinaryFile.write(buffer, sizeOfBuffer);

			for (int j = 0; j < listOfStudents[k].Course * 2; ++j)
				newBinaryFile.write((char*)&listOfStudents[k].Mark[i].Mark[j], sizeof(int));
		}

		buffer = strcpy(new char[listOfStudents[k].FormStudying.length() + 1], listOfStudents[k].FormStudying.c_str());
		sizeOfBuffer = strlen(buffer);

		newBinaryFile.write((char*)&sizeOfBuffer, sizeof(size_t));
		newBinaryFile.write(buffer, sizeOfBuffer);


		delete[] buffer;
	}

	newBinaryFile.close();
}

void createFileOrBinaryFile(Student* listOfStudents, const int sizeOfList, const int choiceFile, const char* nameOfFile)
{
	if (choiceFile == 1)
		createFile(listOfStudents, sizeOfList, nameOfFile);

	if (choiceFile == 2)
		createBinaryFile(listOfStudents, sizeOfList, nameOfFile);
}


int choiceSubject(Student student)
{
	int choice;

	for (int i = 0; i < 5; ++i)
		std::cout << student.Mark[i].Subject << " >> " << i + 1 << '\n';

	pickAndCheck("", choice, 1, 5);

	return choice;
}

bool checkMarks(Student student, const int chosenSubject)
{
	bool result = false;

	int i = 0;

	while (i < student.Course * 2 && !result)
	{
		if (student.Mark[chosenSubject].Mark[i] == 2)
			result = true;

		i += 1;
	}

	return result;
}

void printBadStudent(Student student, const int chosenSubject)
{
	std::cout << "\n\nСтудент " << student.Name << ", обучающийся на " << student.Course << " курсе в " << student.Group << " группе ";

	if (student.FormStudying == "очная")
		std::cout << "очно, ";
	else
		std::cout << "заочно, ";

	std::cout << "имеет задолженность по предмету " << student.Mark[chosenSubject].Subject;

	int i = 0, countBadMarks = 0;
	while (i < student.Course * 2)
	{
		if (student.Mark[chosenSubject].Mark[i] == 2)
		{
			countBadMarks += 1;

			if (countBadMarks == 1)
				if (i + 1 != 2)
					std::cout << " в ";
				else
					std::cout << " во ";

			if (countBadMarks > 1)
				std::cout << ", " << i + 1;
			else
				if (countBadMarks == 1)
					std::cout << i + 1;
		}
		i += 1;
	}
	if (countBadMarks > 1)
		std::cout << " семестрах.";
	else
		if (countBadMarks == 1)
			std::cout << " семестре.";

	std::cout << '\n';
}

bool searchBadStudents(const int chosenSubject, Student* listOfStudents, const int sizeOfList)
{
	bool result = false;

	for (int i = 0; i < sizeOfList; ++i)
		if (checkMarks(listOfStudents[i], chosenSubject))
		{
			printBadStudent(listOfStudents[i], chosenSubject);

			result = true;
		}

	return result;
}

//void mainTask(const int choiceFile, const char* nameOfFile)
//{
//	
//}


void printStudent(Student student, const bool flagOfPrint)
{
	if (flagOfPrint)
		std::cout << student.Name << '\n';

	std::cout << student.Course << '\n';

	std::cout << student.Group << '\n';

	for (int i = 0; i < SUB; ++i)
	{
		std::cout << student.Mark[i].Subject;

		std::cout << ':';

		for (int j = 0; j < student.Course * 2; ++j)
			std::cout << ' ' << student.Mark[i].Mark[j];

		std::cout << '\n';
	}

	std::cout << student.FormStudying << '\n';
}

void printListOfStudents(const int choiceFile, const char* nameOfFile)
{
	int sizeOfList = 0;

	Student listOfStudents[MAX_COUNT_OF_STUDENTS];

	system("cls");

	if (choiceFile == 1)
		readFile(listOfStudents, sizeOfList, nameOfFile);

	if (choiceFile == 2)
		readBinaryFile(listOfStudents, sizeOfList, nameOfFile);

	std::cout << "Текущий список студентов:\n\n";

	for (int i = 0; i < sizeOfList; ++i)
	{
		printStudent(listOfStudents[i], true);

		std::cout << '\n';
	}

	std::cout << "\n\n";
}


bool compareStudents(Student student1, Student student2)
{
	bool result = false;

	if (student1.Course < student2.Course)
		result = false;
	else
		if (student1.Course > student2.Course)
			result = true;
		else
			if (student1.Group < student2.Group)
				result = false;
			else
				if (student1.Group > student2.Group)
					result = true;
				else
					if (student1.Name <= student2.Name)
						result = false;
					else
						result = true;

	return result;
}

void swap_students(Student& student1, Student& student2)
{
	swapNameOrFormStudying(student1.Name, student2.Name);

	swapElement(student1.Course, student2.Course);

	swapElement(student1.Group, student2.Group);

	for (int i = 0; i < SUB; ++i)
		for (int j = 0; j < SEM; ++j)
			swapElement(student1.Mark[i].Mark[j], student2.Mark[i].Mark[j]);

	swapNameOrFormStudying(student1.FormStudying, student2.FormStudying);
}

void swapNameOrFormStudying(std::string& str1, std::string& str2)
{
	std::string str = str1;
	str1 = str2;
	str2 = str;
}

void swapElement(int& element1, int& element2)
{
	int element = element1;
	element1 = element2;
	element2 = element;
}

void sortingListOfStudents(const int choiceFile, const char* nameOfFile)
{
	int sizeOfList = 0;

	Student listOfStudents[MAX_COUNT_OF_STUDENTS];

	system("cls");

	readFileOrBinaryFile(listOfStudents, sizeOfList, choiceFile, nameOfFile);

	bool flagOfSorting = false;

	for (int i = 0; i < sizeOfList - 1; i++)
	{
		for (int j = i + 1; j < sizeOfList; j++)
			if (compareStudents(listOfStudents[i], listOfStudents[j]))
			{
				if (!flagOfSorting)
					flagOfSorting = true;

				swap_students(listOfStudents[i], listOfStudents[j]);
			}
	}

	if (flagOfSorting)
	{
		std::cout << "Список студентов был отсортирован.\n\n";

		std::remove(nameOfFile);

		int choiceNewFile;

		pickAndCheck("Записать новый список в обычный файл >> 1\nЗаписать новый список в бинарный файл >> 2\n", choiceNewFile, 1, 2);

		char nameOfNewFile[255] = "";

		pickNameOfFile(nameOfNewFile, choiceNewFile, false);

		createFileOrBinaryFile(listOfStudents, sizeOfList, choiceNewFile, nameOfNewFile);

		std::cout << '\n';

		if (ifFileExist(nameOfNewFile, choiceNewFile))
			std::cout << "Файл был успешно создан.";
		else
			std::cout << "Создать файл не удалось.";
	}
	else
		std::cout << "Список студентов не был отсортирован.";

	std::cout << "\n\n\n";
}


void addStudentsFromConsole(Student* listOfStudents, int& sizeOfList)
{
	while (sizeOfList < MAX_COUNT_OF_STUDENTS)
	{
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cout << "\nВведите имя нового студента >> ";
		std::getline(std::cin, listOfStudents[sizeOfList].Name);

		std::cout << "\nВведите курс нового студента >> ";
		std::cin >> listOfStudents[sizeOfList].Course;

		std::cout << "\nВведите группу нового студента >> ";
		std::cin >> listOfStudents[sizeOfList].Group;

		std::cout << "\nВведите оценки нового студента:\n\n";

		for (int i = 0; i < SUB; ++i)
		{
			std::cout << listOfStudents[sizeOfList].Mark[i].Subject << '\n';

			for (int j = 0; j < SEM; ++j)
			{
				std::cout << "Оценка за " << j + 1 << " семестр >> ";
				std::cin >> listOfStudents[sizeOfList].Mark[i].Mark[j];
			}

			std::cout << '\n';
		}

		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cout << "Введите форму обучения нового студента >> ";
		getline(std::cin, listOfStudents[sizeOfList].FormStudying);

		sizeOfList += 1;
	}

	int choiceNewFile;

	pickAndCheck("Заполнить список из обычного файла >> 1\nЗаполнить список из бинарного файла >> 2\n", choiceNewFile, 1, 2);

	char nameOfNewFile[255] = "";

	pickNameOfFile(nameOfNewFile, choiceNewFile, false);

	createFileOrBinaryFile(listOfStudents, sizeOfList, choiceNewFile, nameOfNewFile);

	if (ifFileExist(nameOfNewFile, choiceNewFile))
		std::cout << "Файл был успешно создан.";
	else
		std::cout << "Создать файл не удалось.";
}

void addStudentsFromFile(Student* listOfStudents, int& sizeOfList)
{
	int count = sizeOfList;

	char nameOfFile[255] = "";

	pickNameOfFile(nameOfFile, 1, true);

	readFile(listOfStudents, sizeOfList, nameOfFile);

	if (count == sizeOfList)
		std::cout << "Новые студенты не были добавлены в список.\n\n";
	else
		std::cout << "Новые студенты были добавлены в список.\n\n";

	char nameOfNewFile[255] = "";

	renameFile(nameOfFile, nameOfNewFile, 1);

	createFile(listOfStudents, sizeOfList, nameOfNewFile);

	if (ifFileExist(nameOfNewFile, 1))
		std::cout << "Файл был успешно отредактирован.";
	else
		std::cout << "Отредактировать файл не удалось.";
}

void addStudentsFromBinaryFile(Student* listOfStudents, int& sizeOfList)
{
	int count = sizeOfList;

	char nameOfFile[255] = "";

	pickNameOfFile(nameOfFile, 2, true);

	readBinaryFile(listOfStudents, sizeOfList, nameOfFile);

	if (count == sizeOfList)
		std::cout << "Новые студенты не были добавлены в список.\n\n";
	else
		std::cout << "Новые студенты были добавлены в список.\n\n";

	char nameOfNewFile[255] = "";

	renameFile(nameOfFile, nameOfNewFile, 2);

	createBinaryFile(listOfStudents, sizeOfList, nameOfNewFile);

	if (ifFileExist(nameOfNewFile, 2))
		std::cout << "Файл был успешно отредактирован.";
	else
		std::cout << "Отредактировать файл не удалось.";
}

void addStudents(const int choiceFile, const char* nameOfFile)
{
	int sizeOfList = 0;

	Student listOfStudents[MAX_COUNT_OF_STUDENTS];

	system("cls");

	readFileOrBinaryFile(listOfStudents, sizeOfList, choiceFile, nameOfFile);

	std::remove(nameOfFile);

	int choiceMethod;

	pickAndCheck("Добавить студентов в список с помощью консоли >> 1\nДобавить студентов в список с помощью обычного файла >> 2\nДобавить студентов в список с помощью бинарного файла >> 3\n", choiceMethod, 1, 3);

	if (choiceMethod == 1)
		addStudentsFromConsole(listOfStudents, sizeOfList);

	if (choiceMethod == 2)
		addStudentsFromFile(listOfStudents, sizeOfList);

	if (choiceMethod == 3)
		addStudentsFromBinaryFile(listOfStudents, sizeOfList);

	std::cout << "\n\n\n";
}


void editStudentFromConsole(Student& student)
{
	printStudent(student, false);

	int flagOfEdit;

	pickAndCheck("\nИзменить данные курса этого студента?\nДа >> 1\nНет >> 2\n", flagOfEdit, 1, 2);

	if (flagOfEdit == 1)
	{
		std::cout << "\nВведите курс нового студента >> ";
		std::cin >> student.Course;

	}

	std::cout << '\n';

	pickAndCheck("Изменить данные группы этого студента?\nДа >> 1\nНет >> 2\n", flagOfEdit, 1, 2);

	if (flagOfEdit == 1)
	{
		std::cout << "\nВведите группу нового студента >> ";
		std::cin >> student.Group;
	}

	std::cout << '\n';

	pickAndCheck("Изменить оценки этого студента?\nДа >> 1\nНет >> 2\n", flagOfEdit, 1, 2);

	if (flagOfEdit == 1)
	{
		std::cout << "\nВведите новые оценки студента:\n";

		for (int i = 0; i < SUB; ++i)
		{
			std::cout << '\n' << student.Mark[i].Subject << '\n';

			for (int j = 0; j < student.Course * 2; ++j)
			{
				std::cout << "\nОценка за " << i + 1 << " семестр >> ";
				std::cin >> student.Mark[i].Mark[j];
				std::cout << '\n';
			}
		}
	}

	std::cout << '\n';

	pickAndCheck("Изменить данные формы обучения этого студента?\nДа >> 1\nНет >> 2\n", flagOfEdit, 1, 2);

	if (flagOfEdit == 1)
	{
		std::cout << "\nВведите форму обучения нового студента >> ";
		std::cin >> student.FormStudying;
	}

	std::cout << '\n';
}

void editStudentsFromConsole(Student* listOfStudents, const int sizeOfList, bool& flagOfStudents)
{
	int flagOfEdit = 1;

	while (flagOfEdit == 1)
	{
		bool flagOfStudent = false;

		std::string Name;

		std::cout << "\nВведите имя студента, данные которого хотите изменить\n>> ";
		getline(std::cin, Name);

		for (int i = 0; i < sizeOfList; ++i)
			if (Name == listOfStudents[i].Name)
			{
				editStudentFromConsole(listOfStudents[i]);

				flagOfStudent = true;
			}

		if (flagOfStudent)
			flagOfStudents = true;
		else
			std::cout << "Студента с таким именем нет в списке.\n";

		if (sizeOfList < MAX_COUNT_OF_STUDENTS)
			pickAndCheck("Изменить данные еще одного студента?\nДа >> 1\nНет >> 2\n", flagOfEdit, 1, 2);
	}
}

void editStudents(const int choiceFile, char* nameOfFile)
{
	int sizeOfList = 0;

	Student listOfStudents[MAX_COUNT_OF_STUDENTS];

	system("cls");

	readFileOrBinaryFile(listOfStudents, sizeOfList, choiceFile, nameOfFile);

	int choiceMethod;

	bool flagOfEdit = false;

	char nameOfNewFile[255] = "";;

	pickAndCheck("Изменить данные студентов в списке с помощью консоли >> 1\nИзменить данные студентов в списке с помощью обычного файла >> 2\nИзменить данные студентов в списке с помощью бинарного файла >> 3\n", choiceMethod, 1, 3);

	if (choiceMethod == 1)
	{
		editStudentsFromConsole(listOfStudents, sizeOfList, flagOfEdit);

		if (!flagOfEdit)
			std::cout << "\nСовпадений не найдено, список студентов не был изменен.\n\n\n";
		else
		{
			std::cout << "\nДанные некоторых студентов были изменены.\n\n";

			std::remove(nameOfFile);

			int choiceNewFile;

			pickAndCheck("Заполнить список из обычного файла >> 1\nЗаполнить список из бинарного файла >> 2\n", choiceNewFile, 1, 2);

			pickNameOfFile(nameOfNewFile, choiceNewFile, false);

			createFileOrBinaryFile(listOfStudents, sizeOfList, choiceNewFile, nameOfNewFile);

			if (ifFileExist(nameOfNewFile, choiceNewFile))
				std::cout << "Файл был успешно создан.";
			else
				std::cout << "Создать файл не удалось.";

			std::cout << "\n\n\n";
		}
	}
	else
	{
		int sizeOfEditList = 0;

		Student listOfEditStudents[MAX_COUNT_OF_STUDENTS];

		pickNameOfFile(nameOfNewFile, choiceMethod - 1, true);

		if (choiceMethod == 2)
			readFile(listOfEditStudents, sizeOfEditList, nameOfNewFile);

		if (choiceMethod == 3)
			readBinaryFile(listOfEditStudents, sizeOfEditList, nameOfNewFile);

		for (int i = 0; i < sizeOfList; ++i)
			for (int j = 0; j < sizeOfEditList; ++j)
				if (listOfEditStudents[j].Name == listOfStudents[i].Name)
				{
					if (!flagOfEdit)
						flagOfEdit = true;

					swap_students(listOfStudents[i], listOfEditStudents[j]);
				}

		if (!flagOfEdit)
			std::cout << "\nСовпадений не найдено, список студентов не был изменен.\n\n\n";
		else
		{
			std::remove(nameOfFile);

			std::cout << "\nДанные некоторых студентов были изменены.\n\n";

			renameFile(nameOfNewFile, nameOfFile, choiceMethod - 1);

			createFileOrBinaryFile(listOfStudents, sizeOfList, choiceMethod - 1, nameOfFile);

			if (ifFileExist(nameOfFile, choiceMethod - 1))
				std::cout << "Файл был успешно отредактирован.";
			else
				std::cout << "Отредактировать файл не удалось.";

			std::cout << "\n\n\n";
		}
	}
}


void deleteStudent(Student* listOfStudents, int& sizeOfList, const int count)
{
	for (int i = count; i < sizeOfList - 1; ++i)
		swap_students(listOfStudents[i], listOfStudents[i + 1]);

	sizeOfList -= 1;
}

void deleteStudentsFromConsole(Student* listOfStudents, int& sizeOfList, bool& flagOfStudent)
{
	int flagOfDelete = 1;

	while (flagOfDelete == 1)
	{
		std::string Name;

		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cout << "\nВведите имя студента, данные которого хотите удалить >> ";
		std::getline(std::cin, Name);

		for (int i = 0; i < sizeOfList; ++i)
			if (Name == listOfStudents[i].Name)
			{
				deleteStudent(listOfStudents, sizeOfList, i);

				if (!flagOfStudent)
					flagOfStudent = true;
			}

		if (sizeOfList > 0)
			pickAndCheck("\nУдалить данные еще одного студента?\nДа >> 1\nНет >> 2\n", flagOfDelete, 1, 2);
	}
}

void deleteStudents(const int choiceFile, char* nameOfFile)
{
	int sizeOfList = 0;

	Student listOfStudents[MAX_COUNT_OF_STUDENTS];

	system("cls");

	readFileOrBinaryFile(listOfStudents, sizeOfList, choiceFile, nameOfFile);

	int choiceMethod;

	bool flagOfStudent = false;

	char nameOfNewFile[255] = "";;

	pickAndCheck("Удалить данные студентов в списке с помощью консоли >> 1\nУдалить данные студентов в списке с помощью обычного файла >> 2\nУдалить данные студентов в списке с помощью бинарного файла >> 3\n", choiceMethod, 1, 3);

	if (choiceMethod == 1)
	{
		deleteStudentsFromConsole(listOfStudents, sizeOfList, flagOfStudent);

		std::cout << '\n';

		if (!flagOfStudent)
			std::cout << "\nСовпадений не найдено, список студентов не был изменен.\n\n\n";
		else
		{
			std::remove(nameOfFile);

			std::cout << "\nДанные некоторых студентов были удалены.\n\n";

			int choiceNewFile;

			pickAndCheck("Заполнить список из обычного файла >> 1\nЗаполнить список из бинарного файла >> 2\n", choiceNewFile, 1, 2);

			pickNameOfFile(nameOfNewFile, choiceNewFile, false);

			createFileOrBinaryFile(listOfStudents, sizeOfList, choiceNewFile, nameOfNewFile);

			if (ifFileExist(nameOfNewFile, choiceFile))
				std::cout << "Файл был успешно создан.";
			else
				std::cout << "Создать файл не удалось.";

			std::cout << "\n\n\n";
		}
	}
	else
	{
		int count = 0;

		std::string Name[MAX_COUNT_OF_STUDENTS];

		pickNameOfFile(nameOfNewFile, choiceMethod - 1, true);

		if (choiceMethod == 2)
		{
			std::ifstream file(nameOfNewFile);

			while (!file.eof() && count < MAX_COUNT_OF_STUDENTS)
			{
				std::string str;

				getline(file, str);
				Name[count] = str;

				count += 1;
			}

			file.close();
		}

		if (choiceMethod == 3)
		{
			std::ifstream binaryFile(nameOfNewFile, std::ios::binary || std::ios::in);

			binaryFile.seekg(0, std::ios_base::end);

			auto filesize = binaryFile.tellg();

			binaryFile.seekg(0, std::ios_base::beg);

			size_t sizeOfBuffer = 0;
			char* buffer = new char[255];

			while (binaryFile.tellg() < filesize && count < MAX_COUNT_OF_STUDENTS)
			{
				binaryFile.read((char*)&sizeOfBuffer, sizeof(size_t));
				binaryFile.read(buffer, sizeOfBuffer);

				Name[count] = std::string(buffer, sizeOfBuffer);

				count += 1;
			}

			delete[] buffer;

			binaryFile.close();
		}

		int i = 0, j = 0;

		while (j < count)
		{
			while (i < sizeOfList)
			{
				if (Name[j] == listOfStudents[i].Name)
				{
					deleteStudent(listOfStudents, sizeOfList, i);

					if (!flagOfStudent)
						flagOfStudent = true;
				}

				i += 1;
			}

			i = 0;

			j += 1;
		}

		std::remove(nameOfFile);

		if (!flagOfStudent)
			std::cout << "\nСовпадений не найдено, список студентов не был изменен.\n\n";
		else
			std::cout << "\nДанные некоторых студентов были удалены.\n\n";

		renameFile(nameOfNewFile, nameOfFile, choiceFile);

		createFileOrBinaryFile(listOfStudents, sizeOfList, choiceFile, nameOfFile);

		if (ifFileExist(nameOfFile, choiceFile))
			std::cout << "Файл был успешно отредактирован.";
		else
			std::cout << "Отредактировать файл не удалось.";

		std::cout << "\n\n\n";
	}
}