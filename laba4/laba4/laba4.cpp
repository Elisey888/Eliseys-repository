#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "Header.h"

// Дан список слов
// Из каждой группы подряд идущих одинаковых слов 
// оставить только одно



int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	NODE* head;
	init(head);
	std::ifstream file("1.txt");
	if (file)
	{
		createByQueue(head, file);
		printt(head, "Изначальный список: ");

		task(head);
		printt(head, "Итоговый список: ");

		clear(head);
		file.close();
	}
}