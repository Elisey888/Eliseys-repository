#include "Menus.h"
#include "Validations.h"
#include "DeleteComments.h"



void menuOfVar()
{
    cout << "�������� �������: " << '\n';
    cout << "��� ������������� ��������� - 1" << '\n';
    cout << "� �������������� ��������� <String> - 2" << '\n';
    cout << "� �������������� ���������� <Cstring> - 3" << '\n';
    int choice = 0;
    validationForVar(choice);
    string fileName = "";
    cout << "������� �������� �����: " << '\n';
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