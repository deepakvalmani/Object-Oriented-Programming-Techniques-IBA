#include <iostream>

using namespace std;

class Date
{
public:
    int day;
    int month;
    int year;

    // constructor
    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
        if (month > 12 || month < 1)
        {
            this->month = 1;
        }
    }
    // get set functions
    void getDay()
    {
        cout << "Enter Day: ";
        cin >> day;
    }
    void getMonth()
    {
        cout << "Enter Month: ";
        cin >> month;
    }
    void getYear()
    {
        cout << "Enter Year: ";
        cin >> year;
    }
    void setDay(int day)
    {
        this->day = day;
    }
    void setMonth(int month)
    {
        this->month = month;
        if (month > 12 || month < 1)
        {
            this->month = 1;
        }
    }
    void setYear(int year)
    {
        this->year = year;
    }
    string formatdate()
    {
        cout << "formating date..." << endl;
        string s;
        s = to_string(day) + "/" + to_string(month) + "/" + to_string(year);
        return s;
    }
};

int main()
{
    Date d1(19, 1, 2024);
    cout << d1.formatdate() << endl; // should print 19/1/2024
    d1.setDay(17);
    cout << d1.formatdate() << endl; // should print 17/1/2024
    d1.setMonth(5);
    cout << d1.formatdate() << endl; // should print 17/5/2024
    Date d2(29, 13, 2024);           // should set month to 1
    cout << d2.formatdate() << endl; // should print 29/1/2024
    return 0;
}