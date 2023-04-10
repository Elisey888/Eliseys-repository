#include <string.h>
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

string fillArrChar(char charArr[]);
bool checkComments(string s);
int validationForString(string s);
string deleteComments(string s);
void deleteCommentsWithString(string s);
void deleteCommentsWithSrtringh(char charArr[]);
void input();

int main()
{
    SetConsoleOutputCP(1251);
    int option;
    char charArr[100];
    input();
    string s = "";
    std::ifstream file("FileNum.txt");
    file >> s;
    fillArrChar(charArr);
    if (validationForString(s) == 1)
    {
        cout << "способ без использования без библотечных функций: " << "\n\n";
        cout << deleteComments(s) << "\n\n";
        cout << "Способ с использованием библиотеки <string>: " << "\n\n";
        deleteCommentsWithString(s);
        cout << "\n\n";
        cout << "Способ с использованием библиотеки <cstring>: " << "\n\n";
        deleteCommentsWithSrtringh(charArr);
        cout << "\n\n";
    }
    else
    {
        cout << s;
    }
    return 0;
}


string fillArrChar(char charArr[])
{
    std::ifstream file("FileNum.txt");
    int i = 0;
    while (!(file.eof()))
    {
        file >> charArr[i];
        i++;
    }
    return charArr;
}

bool checkComments(string s)
{
    bool flag = false;
    bool flag2 = false;
    int i = 0;
    while (s[i] != '\0')
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
    bool flag2 = true;
    string s2 = "";
    string s3 = "";
    while (s[i] != '\0')
    {
        if (s[i] != '{' && flag)
        {
            s2 = s2 + s[i];
            flag = true;
        }
        if (s[i] == '{')
        {
            flag = false;
            s3 = s3 + s[i];
            flag2 = false;
        }
        if (s[i] == '}')
        {
            flag = true;
            flag2 = true;
            s3 = "";
        }
        if (!(flag) && !(flag2) && (s[i] != '{') && (s[i] != '}'))
        {
            s3 = s3 + s[i];
        }
        i++;
    }
    if (!(flag2))
    {
        s2 = s2 + s3;
    }
    return s2;
}


void deleteCommentsWithString(string s)
{
    char openBreket = '{';
    char closeBreket = '}';
    int index1 = 0;
    int index2 = 0;
    int indexAdd = 0;
    int delSize = 0;
    bool flag = true;
        while (index1 != -1 && index2 != -1)
        {
            index1 = s.find(openBreket);
            index2 = s.find(closeBreket);
            indexAdd = index2+1;
            if (index1 > index2)
            {
                while (index1 > index2)
                {
                    index1 = s.find(openBreket);
                    index2 = s.find(closeBreket, indexAdd);
                    indexAdd = index2 + 1;
                }
                int delSize = index2 - index1 + 1;
                if (index1 != -1 && index2 != -1)
                    s.erase(index1, delSize);
                flag = false;
            }
            if (index1 < index2 && flag)
            {
                int delSize = index2 - index1 + 1;
                if (index1 != -1 && index2 != -1)
                    s.erase(index1, delSize);
            }
        }
    cout << s;
}

void deleteCommentsWithSrtringh(char charArr[])
{
    int i = 0;
    bool flag = true;
    bool flag2 = true;
    int sizeArr = strlen(charArr);
    string s2 = "";
    string s3 = "";
    while (charArr[i] != '0')
    {
        if (charArr[i] != '{' && flag)
        {
            s2 = s2 + charArr[i];
            flag = true;
        }
        if (charArr[i] == '{')
        {
            flag = false;
            s3 = s3 + charArr[i];
            flag2 = false;
        }
        if (charArr[i] == '}')
        {
            flag = true;
            flag2 = true;
            s3 = "";
        }
        if (!(flag) && !(flag2) && (charArr[i] != '{') && (charArr[i] != '}'))
        {
            s3 = s3 + charArr[i];
        }
        i++;
    }
    if (!(flag2))
    {
        s2 = s2 + s3;
    }
    s2 = s2 + '0';
    cout << s2;
}

void input()
{
    string in;
    cout << "Введите строку с комментариями типа {...}, оканчивающуюся нулем: " << '\n';
    cin >> in;
    std::ofstream file("FileNum.txt");
    file << in;
    file.close();
}
