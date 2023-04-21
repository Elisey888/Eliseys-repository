#include "Validations.h"



bool validationForFile(ifstream& file)
{
    if (fileCheck(file))
    {
        if (fileNotEmpty(file))
        {
            return true;
        }
        else
        {
            cout << "Файл пустой";
        }
    }
    else
    {
        cout << "Файл не открыт." << '\n';
    }
    return false;
}

bool checkCommentsForChar(char charArr[100], int k)
{
    int i;
    int j;
    char openBraket = '{';
    char closeBraket = '}';
    bool findOpen = false;
    bool findClose = false;
    int size = k;
    for (i = 0; i < size; i++)
    {
        if (charArr[i] == '{')
        {
            findOpen = true;
            break;
        }
    }
    for (j = size - 1; j > 0; j--)
    {
        if (charArr[j] == '}')
        {
            findClose = true;
            break;
        }
    }
    if (findOpen && findClose)
    {
        if (i > j)
        {
            return false;
        }
        return true;
    }
    return false;
}

bool checkCommentsForString(string str)
{
    int i;
    int j;
    char openBraket = '{';
    char closeBraket = '}';
    bool findOpen = false;
    bool findClose = false;
    int size = str.size();
    for (i = 0; i < size; i++)
    {
        if (str[i] == '{')
        {
            findOpen = true;
            break;
        }
    }
    for (j = size - 1; j > 0; j--)
    {
        if (str[j] == '}')
        {
            findClose = true;
            break;
        }
    }
    if (findOpen && findClose)
    {
        if (i > j)
        {
            return false;
        }
        return true;
    }
    return false;
}

bool fileCheck(ifstream& file)
{

    if (file.is_open())
    {
        return true;
    }
    return false;
}

bool fileNotEmpty(ifstream& file)
{
    int result = true;
    if (file.peek() == EOF)
        result = false;
    return result;
}


void validationForVar(int& x)
{
    while (!(std::cin >> x) || x > 3 || x < 1)
    {
        std::cout << "Ошибка ввода!\n";
        std::cin.clear();
        std::cin.ignore(255, '\n');
        std::cout << "\nВыберите вариант:\n";
    }
}