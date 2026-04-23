#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Data
{
public:
    int rows;
    int cols;
    T value;
};

template <class T>
class sparse_mattrix
{
private:
    int total_rows;
    int total_col;
    
    vector<Data<T>> data;

public:
    sparse_mattrix(int total_rows, int total_col)
    {
        this->total_rows = total_rows;
        this->total_col = total_col;
    }

    void insert(int rows, int cols, T value)
    {
        if (value != 0)
        {
            data.push_back({rows, cols, value});
        }
    }

    T getValue(int rows, int cols) const
    {
        for (auto element : data)
        {
            if (element.rows == rows && element.cols == cols)
            {
                return element.value;
            }
        }
        return 0;
    }

    sparse_mattrix<T> operator+(const sparse_mattrix<T> &other)
    {
        sparse_mattrix<T> result(total_rows, total_col);
        for (int i = 0; i < total_rows; i++)
        {
            for (int j = 0; j < total_col; j++)
            {
                T sum = this->getValue(i, j) + other.getValue(i, j);
                if (sum != 0)
                {
                    result.insert(i, j, sum);
                }
            }
        }
        return result;
    }

    sparse_mattrix<T> operator-(const sparse_mattrix<T> &other)
    {
        sparse_mattrix<T> result(total_rows, total_col);
        for (int i = 0; i < total_rows; i++)
        {
            for (int j = 0; j < total_col; j++)
            {
                T diff = this->getValue(i, j) - other.getValue(i, j);
                if (diff != 0)
                {
                    result.insert(i, j, diff);
                }
            }
        }
        return result;
    }

    sparse_mattrix<T> operator*(const sparse_mattrix<T> &other)
    {

        sparse_mattrix<T> result(this->total_rows, other.total_col);
        for (int i = 0; i < this->total_rows; i++)
        {
            for (int j = 0; j < other.total_col; j++)
            {
                T sum = 0;
                for (int k = 0; k < this->total_col; k++)
                {
                    sum = sum + (this->getValue(i, k) * other.getValue(k, j));
                }
                if (sum != 0)
                {
                    result.insert(i, j, sum);
                }
            }
        }
        return result;
    }

    void print()
    {
        for (int i = 0; i < total_rows; i++)
        {
            for (int j = 0; j < total_col; j++)
            {
                cout << getValue(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    sparse_mattrix<int> m1(2, 2);
    sparse_mattrix<int> m2(2, 2);

    m1.insert(0, 0, 5);
    m1.insert(1, 0, 2);

    m2.insert(0, 0, 3);
    m2.insert(1, 0, 2);

    sparse_mattrix<int> obj1 = m1 + m2;
    cout << "ADD:" << endl;
    obj1.print();

    sparse_mattrix<int> obj2 = m1 * m2;
    cout << "MULTIPY:" << endl;
    obj2.print();

    sparse_mattrix<int> obj3 = m1 - m2;
    cout << "SUBTRACT:" << endl;
    obj3.print();

    return 0;
}