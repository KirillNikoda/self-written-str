#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class MyString
{
public:
    MyString()
    {
        str = nullptr;
    }
    MyString(char *str)
    {
        int length = strlen(str);
        this->str = new char[length + 1];
        for (int i = 0; i < length; i++)
        {
            this->str[i] = str[i];
        }
        this->str[length] = '\0';
    }
    ~MyString()
    {
        delete[] this->str;
    }

    MyString &operator=(const MyString &other)
    {
        if (this->str != nullptr)
        {
            delete[] this->str;
        }

        int length = strlen(other.str);
        this->str = new char[length + 1];
        for (int i = 0; i < length; i++)
        {
            this->str[i] = other.str[i];
        }
        this->str[length] = '\0';

        return *this;
    }
    MyString operator+(const MyString &other)
    {
        MyString newStr;
        int thisLength = strlen(this->str);
        int otherLength = strlen(other.str);
        newStr.str = new char[thisLength + otherLength + 1];

        int i = 0;
        for (; i < thisLength; i++)
        {
            newStr.str[i] = this->str[i];
        }
        for (int j = 0; j < thisLength; j++)
        {
            newStr.str[i] = other.str[j];
        }
        newStr.str[thisLength + otherLength] = '\0';
        return newStr;
    }

private:
    char *str;
};

int main()
{

    MyString str("testsd");
    MyString str1("test2");
    MyString result;
    result = str + str;
    return 0;
}
