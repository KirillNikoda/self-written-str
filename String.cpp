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
        cout << length << endl;
    }
    ~MyString()
    {
    }

private:
    char *str;
};

int main()
{

    MyString str("testsd");
    return 0;
}
