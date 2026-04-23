#include <iostream>

using namespace std;

class Date
{
private:
    int Day;
    int Month;
    int Year;

public:
    friend class AgeCalculator;

    Date(int d, int m, int y)
    {
        Day = d;
        Month = m;
        Year = y;
    }
    void displayDate()
    {
        cout << Day << "/" << Month << "/" << Year << endl;
    }
};

class AgeCalculator
{
public:
    void calculateAge(Date DOB, int Curr_year)
    {
        cout << "Age: " << Curr_year - DOB.Year << " years" << endl;
    }

    // void calculateAge(Date DOB, Date Curr)
    // {
    //     cout << "Age: " << endl;
    //     cout << Curr.Day - DOB.Day << "Days" << Curr.Month - DOB.Month << "Months" << Curr.Year - DOB.Year << " years" << endl;
    // }
};

// Date Test
int main()
{
    Date dateOfBirth(14, 2, 2006);


    AgeCalculator ageCalc;

    cout << "Date of Birth: ";
    dateOfBirth.displayDate();

    ageCalc.calculateAge(dateOfBirth, 2026);

    return 0;
}