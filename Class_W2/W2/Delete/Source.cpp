#include <iostream>
using namespace std;
class MyString {
    char* str;
    int num;
public:
    MyString() = default;
    MyString(const char* chars) {
        num = strlen(chars);
        str = new char[num + 1];
        strcpy_s(str, num + 1, chars);
    }
    friend ostream& operator<<(ostream& out, const MyString& s) {
        out << s.str;
        return out;
    }
    friend istream& operator >> (istream& in, MyString& s) {
        char* ptr = new char[100];
        in >> ptr;
        s = MyString(ptr);
        delete ptr;
        return in;
    }
    int length()
    {
        return strlen(str);
    }
    MyString& ope(const MyString& newstr) {
        int len = strlen(newstr.str) + strlen(str);
        char* tmp = new char[len + 1];

        strcpy_s(tmp, len + 1, str);
        strcat_s(tmp, len + 1, newstr.str);
        tmp[len] = '\0';

        MyString res;
        strcpy_s(res.str, len + 1, tmp);
        delete[] tmp;
        return res;
    }
    bool insertString(char* str1, char* str2, const int& position)
    {
        int shiftedPos = position - 1;
        int str2Size = strlen(str2);
        int str1Size = strlen(str1);
        int newSize = str2Size + str1Size + 1;

        char* newStr = new char[newSize];
        int k = 0;
        while (k == 0) {
            for (int i = 0; i < shiftedPos; i++) newStr[i] = str1[i];

            for (int i = 0; i < str2Size; i++) newStr[shiftedPos + i] = str2[i];
            for (int i = 0; i < newSize; i++) newStr[shiftedPos + str2Size + i] = str1[shiftedPos + i];
            k = 1;
        }

        newStr[newSize] = '\0';
        if (k == 1)
        {
            return true;
        }
        return false;

    }
    bool erase(int pos, int num)
    {
        if (pos < 0 || pos >= strlen(str) || num<0 || num>strlen(str) - 1)
            return false;
        char* tmp = str;
        int count=0;
        while (count < num) {
            for (int i = pos; i < strlen(str) - 1; i++)
            {
                tmp[i] = tmp[i + 1];
            }
            count++;
        }
        tmp[strlen(str) - num] = '\0';
        cout << tmp << endl;
        delete[]tmp;
        return true;
    }
    bool replace(int pos, int numCh, const char* ptr) {
        if (pos >= strlen(ptr) || numCh > strlen(ptr) - 1)
            return false;
        char* tmp = new char[strlen(str) - numCh + strlen(ptr)];
        int j = 0;
        for (int i = 0; i < strlen(str); i++)
        {
            if (pos == i) {
                for (int k = 0; k < strlen(ptr); k++)
                {
                    tmp[j++] = ptr[k];
                }
                i = numCh + pos;
            }
            tmp[j++] = str[i];
        }
        tmp[strlen(str) - numCh + strlen(ptr)] = '\0';
        cout << tmp << endl;
        delete[]tmp;
        return true;
    }
};

int main()
{
    MyString k;
    cout << "Nhap ki tu: ";
    cin >> k;
    cout << k.erase(0, 2);
   
   /* cout << k.replace(0,2,"abc");*/
  
    return 0;
}

