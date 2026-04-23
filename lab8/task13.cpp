#include <iostream>
#include <vector>

using namespace std;

template <typename T>

class Stack
{

private:
    vector<T> s;

public:
    Stack()
    {
    }

    void push(T obj)
    {
        s.push_back(obj);
    }

    T pop()
    {
        if (s.empty())
        {
            cout << "Error: Stack is Empty\n";
            return T();
        }

        T val = s.back();
        s.pop_back();
        return val;
    }

    T top()
    {
        if (s.empty())
        {
            cout << "Error: Stack is Empty\n";
            return T();
        }
        return s.back();
    }
};
int main()
{
    Stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.top() << endl; // 30
    cout << st.pop() << endl; // 30
    cout << st.top() << endl; // 20

    return 0;
}