#include <iostream>
#include <exception>
#include <string>
#include <sstream>
using namespace std;

class Stack
{
    int *array;
    int count, topIndex, maxCapacity;

public:
    Stack(int capacity = 10)
    {
        maxCapacity = capacity;
        array = new int[maxCapacity];
        topIndex = 0;
        count = 0;
    }

    Stack(const Stack &other)
    {
        maxCapacity = other.maxCapacity;
        count = other.count;
        topIndex = other.topIndex;
        array = new int[maxCapacity];
        for (int i = 0; i < count; i++)
        {
            *(array + i) = *(other.array + i);
        }
    }

    Stack &operator=(const Stack &other)
    {
        if (this != &other)
        {
            delete[] array;
            maxCapacity = other.maxCapacity;
            count = other.count;
            topIndex = other.topIndex;
            array = new int[maxCapacity];
            for (int i = 0; i < count; i++)
            {
                *(array + i) = *(other.array + i);
            }
        }
        return *this;
    }

    void push(int value)
    {
        if (isFull())
        {
            expand();
        }
        *(array + topIndex) = value;
        topIndex++;
        count++;
    }

    int pop()
    {
        if (isEmpty())
        {
            throw underflow_error("Stack is empty!");
        }
        topIndex--;
        int topValue = *(array + topIndex);
        count--;
        return topValue;
    }

    int peek()
    {
        if (isEmpty())
        {
            throw underflow_error("Stack is empty!");
        }
        return *(array + topIndex - 1);
    }

    int top() const
    {
        if (isEmpty())
        {
            throw underflow_error("Stack is empty!");
        }
        return *(array + topIndex - 1);
    }

    int size() const
    {
        return count;
    }

    int sum() const
    {
        int total = 0;
        for (int i = 0; i < count; i++)
        {
            total += *(array + i);
        }
        return total;
    }

    bool isFull() const
    {
        return count == maxCapacity;
    }

    bool isEmpty() const
    {
        return count == 0;
    }

    void reverseMiddleHalf()
    {
        if (count < 4)
        {
            throw underflow_error("Stack should have more than 4 elements to reverse.");
        }
        for (int left = count / 4, right = (3 * count) / 4 - 1; left < right;)
        {
            if (count % 2 && (left == count / 2 || right == count / 2))
            {
                if (left == count / 2)
                    left++;
                if (right == count / 2)
                    right--;
                continue;
            }
            swap(*(array + left), *(array + right));
            left++;
            right--;
        }
    }

    string toString() const
    {
        if (isEmpty())
        {
            return "[]";
        }
        stringstream ss;
        ss << "[";
        for (int i = 0; i < count; i++)
        {
            ss << *(array + i);
            if (i < count - 1)
            {
                ss << ", ";
            }
        }
        ss << "]";
        return ss.str();
    }

    void expand()
    {
        int newCapacity = maxCapacity * 2;
        int *newArray = new int[newCapacity];
        for (int i = 0; i < count; i++)
        {
            *(newArray + i) = *(array + i);
        }
        delete[] array;
        array = newArray;
        maxCapacity = newCapacity;
    }

    bool operator<(const Stack &other) const
    {
        if (count != other.count)
        {
            return count < other.count;
        }

        int sumThis = 0, sumOther = 0;
        for (int i = 0; i < count; i++)
        {
            sumThis += *(array + i);
            sumOther += *(other.array + i);
        }

        if (sumThis != sumOther)
        {
            return sumThis < sumOther;
        }

        if (count > 0)
        {
            return *(array + topIndex - 1) < *(other.array + other.topIndex - 1);
        }

        return false;
    }

    bool operator==(const Stack &other) const
    {
        if (count != other.count)
            return false;
        for (int i = 0; i < count; i++)
        {
            if (*(array + i) != *(other.array + i))
                return false;
        }
        return true;
    }

    bool operator!=(const Stack &other) const
    {
        return !(*this == other);
    }

    bool operator>(const Stack &other) const
    {
        return other < *this;
    }

    bool operator<=(const Stack &other) const
    {
        return (*this < other) || (*this == other);
    }

    bool operator>=(const Stack &other) const
    {
        return (*this > other) || (*this == other);
    }

    ~Stack()
    {
        delete[] array;
    }
};

int main()
{
    Stack alpha, beta, gamma, delta, omega;

    alpha.push(12);
    alpha.push(7);
    alpha.push(45);
    alpha.push(18);
    alpha.push(33);
    alpha.push(29);
    alpha.push(90);
    alpha.push(61);

    beta.push(4);
    beta.push(22);

    gamma.push(9);
    gamma.push(14);
    gamma.push(27);

    delta.push(11);
    delta.push(35);

    omega.push(12);
    omega.push(7);
    omega.push(45);
    omega.push(18);
    omega.push(33);
    omega.push(29);
    omega.push(90);
    omega.push(61);

    cout << "Stack Alpha: " << alpha.toString() << endl;
    cout << "Stack Beta: " << beta.toString() << endl;
    cout << "Stack Gamma: " << gamma.toString() << endl;
    cout << "Stack Delta: " << delta.toString() << endl;
    cout << "Stack Omega: " << omega.toString() << endl
         << endl;

    cout << "Alpha < Beta: " << (alpha < beta ? "true" : "false") << endl;
    cout << "Alpha < Gamma: " << (alpha < gamma ? "true" : "false") << endl;
    cout << "Gamma < Delta: " << (gamma < delta ? "true" : "false") << endl;
    cout << "Alpha < Omega: " << (alpha < omega ? "true" : "false") << endl;
    cout << "Alpha == Omega: " << (alpha == omega ? "true" : "false") << endl
         << endl;

    cout << "Original Alpha: " << alpha.toString() << endl;
    try
    {
        alpha.reverseMiddleHalf();
        cout << "After reverse: " << alpha.toString() << endl;
    }
    catch (const exception &e)
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
