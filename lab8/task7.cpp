#include <iostream>
#include <stdexcept> 

using namespace std;

template <typename T>
class Matrix {
private:
    int rows, cols;
    T** data;

public:
    Matrix(int r, int c) {
        if (r <= 0 || c <= 0)
            throw invalid_argument("Invalid matrix size");

        rows = r;
        cols = c;

        data = new T*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new T[cols]();
        }
    }

    Matrix(const Matrix& other) {
        rows = other.rows;
        cols = other.cols;

        data = new T*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new T[cols];
            for (int j = 0; j < cols; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    T& at(int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            throw out_of_range("Index out of bounds");

        return data[r][c];
    }

    T* operator[](int r) {
        if (r < 0 || r >= rows)
            throw out_of_range("Row index out of bounds");

        return data[r];
    }

    Matrix operator+(const Matrix& other) {
        if (rows != other.rows || cols != other.cols)
            throw invalid_argument("Dimension mismatch for addition");

        Matrix result(rows, cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }

        return result;
    }

    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    try {
        Matrix<int> A(2, 2);
        Matrix<int> B(2, 2);

        A[0][0] = 1; A[0][1] = 2;
        A[1][0] = 3; A[1][1] = 4;

        B[0][0] = 5; B[0][1] = 6;
        B[1][0] = 7; B[1][1] = 8;

        Matrix<int> C = A + B;

        C.display();

        cout << A.at(5, 5); 

    } catch (exception& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}