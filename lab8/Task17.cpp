#include <iostream>
#include <vector>
using namespace std;

template <typename T, typename BinaryOperation>

vector<vector<T>> matrix_operation(
    const vector<vector<T>> &m1,
    const vector<vector<T>> &m2,
    size_t rows, size_t cols,
    BinaryOperation op)
{
    vector<vector<T>> result(rows, vector<T>(cols));

    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < cols; ++j)
        {
            result[i][j] = op(m1[i][j], m2[i][j]);
        }
    }

    return result;
}
int main()
{
    vector<vector<int>> m1 = {
        {3, 4, 3},
        {1, 7, 6}};

    vector<vector<int>> m2 = {
        {9, 8, 1},
        {1, 0, 2}};
    auto add = [](const int &a, const int &b)
    {
        return a + b;
    };

    vector<vector<int>> result = matrix_operation(m1, m2, 2, 3, add);
    
    for (size_t i = 0; i < 2; ++i)
    {
        for (size_t j = 0; j < 3; ++j)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}