#include <string.h>
#include <iostream>
#include <Windows.h>
#include <iomanip>

using namespace std;

bool checkComments(string s);
int validationForString(string s);
string deleteComments(string s);
string deleteComments2(string s);

int main()
{
    SetConsoleOutputCP(1251);
    int option;
    string s = "";
    cout << "Введите строку, содержащую комментарии типа {...}: \n";
    cin >> s;
    if (validationForString(s) == 1)
    {
        cout << deleteComments(s) << "\n\n";
        cout << deleteComments2(s);
    }
    else
    {
        cout << s;
    }
    return 0;
}


bool checkComments(string s)
{
    bool flag = false;
    bool flag2 = false;
    /*for (int i = 0; i < s.size(); i++)*/
    int i = 0;
        while (s[i]!='\0') 
    {
        if (s[i] == '{')
        {
            flag = true;
        }
        if (s[i] == '}' && flag)
        {
            flag2 = true;
        }   
        i++;
    }
    return (flag && flag2);
}
int validationForString(string s)
{
    if (checkComments(s) == 0)
    {
        cout << "В строке не содержится коментариев\n";
        return checkComments(s);
    }
    return checkComments(s);
}
string deleteComments(string s)
{
    int i = 0;
    int k = 0;
    bool flag = true;
    string s2 = "";
    while (s[i] != '\0')
    {
        k = k + 1;
        i++;
    }
    for (int i = 0; i < k; i++)
    {
        if (s[i] != '{' && flag)
        {
            s2 = s2+s[i];
            flag = true;
        }
        if (s[i] == '{')
        {
            flag = false;
        }
        if (s[i] == '}')
        {
            flag = true;
        }
    }
    return s2;
}
string deleteComments2(string s)
{
    int i = 0;
    double k = 0;
    bool flag = true;
    bool flag2 = true;
    string s2 = "";
    string s3 = "";
    string s4 = "";
    while (s[i] != '\0')
    {
        k = k + 1;
        i++;
    }
    for (int i = 0; i < int(k / 2); i++)
    {
        if (s[i] != '{' && flag)
        {
            s2 = s2 + s[i];
            flag = true;
        }
        if (s[i] == '{')
        {
            flag = false;
        }
    }
        for (int j = k; j > int (k/2); j--)
        {
            if (s[j] != '}' && flag2)
            {
                s3 = s[j]+s3;
                flag2 = true;
            }
            if (s[j] == '}')
            {
                flag2 = false;
            }
        }
        s2 = s2 + s3;
    return s2;
}
