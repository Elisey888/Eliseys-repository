#include "Menus.h"
#include "Validations.h"
#include "DeleteComments.h"



void menuOfVar()
{
    cout << "Выберите вариант: " << '\n';
    cout << "Без использования библиотек - 1" << '\n';
    cout << "С использованием библиотек <String> - 2" << '\n';
    cout << "С использованием библиотеки <Cstring> - 3" << '\n';
    int choice = 0;
    validationForVar(choice);
    string fileName = "";
    cout << "Введите название файла: " << '\n';
    cin >> fileName;
    if (choice == 1)
    {
        ifstream file(fileName);
        if (validationForFile(file))
        {
            deleteComments(file);
        }
    }
    if (choice == 2)
    {
        ifstream file(fileName);
        if (validationForFile(file))
        {
            deleteCommentsWithString(file);
        }

    }
    if (choice == 3)
    {
        ifstream file(fileName);
        if (validationForFile(file))
        {
            deleteCommentsWithStringh(file);
        }
    }
}