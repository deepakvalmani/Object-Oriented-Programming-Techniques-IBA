#include <iostream>
#include <string>
#include <stack>

using namespace std;

class String
{
    string str;
    stack<char> st;

public:
    void get_string(string str)
    {
        this->str = str;
    }

    bool Is_valid()
    {
        for (int i = 0; i < str.size(); i++)
        {
            if ((str[i] == '(') || (str[i] == '{') || (str[i] == '['))
            {
                st.push(str[i]);
            }
            else
            {
                if (st.size() == 0)
                {
                    return false;
                }
                if ((st.top() == '(' && str[i] == ')') ||
                    (st.top() == '{' && str[i] == '}') ||
                    (st.top() == '[' && str[i] == ']'))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main()
{
    String str;

    str.get_string("{[()]}");
    if (str.Is_valid())
    {
        cout << "Is valid" << endl;
    }
    else
    {
        cout << "not valid\n";
    }

    return 0;
}