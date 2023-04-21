#include "DeleteComments.h"
#include"Validations.h"

void deleteComments(ifstream& file)
{
    char charArr[100] = "";
    int k = 0;
    while (!(file.eof()))
    {
        file >> charArr[k];
        k++;
    }
    if (checkCommentsForChar(charArr, k))
    {
        string s = "";
        string s1 = "";
        string s2 = "";
        string s3 = "";
        int i = 0;
        int j = 0;
        int g = 0;
        int h = 0;
        bool flag1 = false;
        bool flag2 = false;
        int size = k;
        for (i = 0; i < size; i++)
        {
            if (charArr[i] == '{')
            {
                g = i;
                break;
            }
        }
        for (j = size - 2; j > 0; j--)
        {
            if (charArr[j] == '}')
            {
                h = j;
                break;
            }
        }
        for (i = g + 1; i < h; i++)
        {
            if (flag1 && (charArr[i] != '{'))
            {
                s3 = s3 + charArr[i];
            }
            if (charArr[i] == '}')
            {
                flag1 = true;
            }
            if (charArr[i] == '{')
            {
                flag1 = false;
            }
        }

        for (i = 0; i < g; i++)
        {
            s1 = s1 + charArr[i];
        }
        for (j = h + 1; j < size - 1; j++)
        {
            s2 = s2 + charArr[j];
        }
        if (flag1)
        {
            s = s1 + s2;
        }
        else
        {
            s = s1 + s3 + s2;
        }
        cout << s;
    }
    else
    {
        cout << "Комментарии отсутствуют." << '\n';
    }
}

void deleteCommentsWithString(ifstream& file)
{
    string s = "";
    file >> s;
    if (checkCommentsForString(s))
    {
        char open = '{';
        string close = "}";
        int index1 = 0;
        int index2 = 0;
        string s1 = "";
        string s2 = "";
        string s3 = "";
        int indexAdd = 0;
        int delSize = 0;
        int i = 0;
        int j = 0;
        int size = s.find('0');
        bool flag1 = false;
        bool flag2 = false;
        index1 = s.find(open);
        index2 = s.find_last_of(close);
        for (i = index1 + 1; i < index2; i++)
        {
            if (flag1 && (s[i] != '{'))
            {
                s2 = s2 + s[i];
            }
            if (s[i] == '}')
            {
                flag1 = true;
            }
            if (s[i] == '{')
            {
                flag1 = false;
            }
        }
        if (flag1)
        {
            delSize = index2 - index1 + 1;
            s.erase(index1, delSize);
        }
        else
        {
            for (j = 0; j < index1; j++)
            {
                s1 = s1 + s[j];
            }
            for (j = index2 + 1; j < size + 1; j++)
            {
                s3 = s3 + s[j];
            }
            s = s1 + s2 + s3;
        }
        cout << s;
    }
    else
    {
        cout << "Комментарии отсутствуют." << '\n';
    }
}

void deleteCommentsWithStringh(ifstream& file)
{
    char charArr[100] = "";
    int k = 0;
    while (!(file.eof()))
    {
        file >> charArr[k];
        k++;
    }
    if (checkCommentsForChar(charArr, k))
    {
        char open[] = "{";
        int x = strcspn(charArr, open);
        int isOpen = x;
        char* close = strrchr(charArr, '}');
        int isClose = (close - charArr);
        char str2[100] = "";
        char str3[100] = "";
        char str4[100] = "";
        char str5[100] = "";
        bool flag1 = false;
        strcpy_s(str5, charArr);
        int d = 0;

        for (int i = isOpen + 1; i < isClose; i++)
        {
            if (flag1 && (charArr[i] != '{'))
            {
                str3[d] = charArr[i];
                d++;
            }
            if (charArr[i] == '}')
            {
                flag1 = true;
            }
            if (charArr[i] == '{')
            {
                flag1 = false;
            }
        }
        if (flag1)
        {
            int j = 0;
            for (int i = isClose + 1; i < k; i++)
            {
                str4[j] = str5[i];
                j++;
            }
            strncpy_s(str2, charArr, isOpen);
            strcat_s(str2, str4);
        }
        else
        {
            int j = 0;
            for (int i = isClose + 1; i < k; i++)
            {
                str4[j] = str5[i];
                j++;
            }
            strncpy_s(str2, charArr, isOpen);
            strcat_s(str2, str3);
            strcat_s(str2, str4);

        }
        int length = strlen(str2);
        for (int i = 0; i < length; i++)
        {
            cout << str2[i];
        }
    }
    else
    {
        cout << "Комментарии отсутствуют." << '\n';
    }
}