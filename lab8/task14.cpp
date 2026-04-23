#include <iostream>
#include <vector>

using namespace std;

template <typename T>

class Queue
{

private:
    vector<T> q;

public:
    Queue()
    {
    }

    void enqueue(T val)
    {
        q.push_back(val);
    }

    T dequeue()
    {
        if (q.empty())
        {
            cout << "Error: Nothig to dequeue.\n";
            return T();
        }
        T val = q.front();
        q.erase(q.begin());
        return val;
    }
    T front()
    {
        if (q.empty())
        {
            cout << "Error: Empty Queue.\n";
            return T();
        }
        return q.front();
    }
};

int main()
{

    Queue <int> obj;
    obj.enqueue(2);
    obj.enqueue(4);
    obj.enqueue(5);

    cout<<obj.front()<<endl;
    obj.dequeue();
    cout<<obj.front()<<endl;
    return 0;
}