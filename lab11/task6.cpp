#include <iostream>
#include <string>
using namespace std;

int countChar(const string &s, char c, int i = 0)
{
    if (i == s.size())
    {
        return 0;
    }
    if (char(s[i]) == c)
    {
        return 1 + countChar(s, c, i + 1);
    }
    return 0 + countChar(s, c, i + 1);
}

string removeChar(const string &s, char c)
{
    if (s.empty())
    {
        return "";
    }
    if (s[1] == c)
    {
        return removeChar(s.substr(1), c);
    }
    else
    {
        return s[0] + removeChar(s.substr(1), c);
    }
}

string toBinary(int n)
{
    if (n == 0)
        return "0";
    if (n == 1)
        return "1";
    return toBinary(n / 2) + to_string(n % 2);
}

int main()
{
    cout << "Count: " << countChar("banana", 'a') << endl;
    cout << removeChar("hello world", 'l') << endl;
    cout << toBinary(10) << endl;
    return 0;
}