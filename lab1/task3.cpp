#include <iostream>
using namespace std;

class Book
{
private:
    string title;
    int code;
    double price;
    float totalGrade; 
    int reviewCount;  

public:
    // Constructor
    Book(string t, int c, double p)
    {
        title = t;
        code = c;
        price = p;
        totalGrade = 0;
        reviewCount = 0;
    }

    // Review function
    void review(float grd)
    {
        totalGrade += grd;
        reviewCount++;
    }

    // Getters
    int getCode() const
    {
        return code;
    }

    double getPrice() const
    {
        return price;
    }

    float getScore() const
    {
        if (reviewCount == 0)
            return 0;
        return totalGrade / reviewCount;
    }
};

int main()
{

    Book books[5] = {
        Book("The C++ Programming Language", 1, 60),
        Book("The Mythical Man-month", 2, 40),
        Book("The Pragmatic Programmer: Your Journey to Mastery", 3, 50),
        Book("The Art of Computer Programming", 4, 50),
        Book("C++ For Dummies", 5, 30)};

    books[0].review(5);
    books[0].review(4);
    books[1].review(4);
    books[2].review(2);
    books[3].review(5);

    int code;
    cout << "Enter code: ";
    cin >> code;

    for (int i = 0; i < 5; i++)
    {
        if (books[i].getCode() == code)
        {
            if (books[i].getScore() == 0)
            {
                cout << "The book has not been graded yet" << endl;
            }
            else
            {
                cout << "The book has score "
                     << books[i].getScore()
                     << " and price "
                     << books[i].getPrice() << endl;
            }
            return 0;
        }
    }

    cout << "The book does not exist" << endl;
    return 0;
}
