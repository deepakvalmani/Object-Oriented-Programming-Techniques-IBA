#include <iostream>
using namespace std;

class Student
{

    string name;
    int Age;
    int student_ID;
    string gender;
    int marks[3];
    int marks_p_fund;
    float GradePoints[4];
    float GPA;
    float CGPA;


public:
    Student()
    {
        GetInfo();
        Getmarks();
    }
    void GetInfo()
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "\nEnter Age: ";
        cin >> Age;
        cout << "\nEnter gender: ";
        cin >> gender;
        cout << "\nEnter ERP: ";
        cin >> student_ID;
    }

    void Getmarks()
    {
        cout << "\nEnter marks for Programming Fundamentals: ";
        cin >> marks_p_fund;

        for (int i = 0; i < 3; i++)
        {
            cout << "\nEnter marks for subject " << i + 1;
            cin >> marks[i];
        }
    }

    void display()
    {
        cout << "Student name: " << name << endl;
        cout <<"ERP: " << student_ID << endl;
        cout <<"Age: " << Age << endl;
        cout << "Gender: " << gender << endl;
        cout<<"GPA: "<<GPA<<endl;


    }

    void CalcGrade()
    {

        for (int i = 0; i < 3; i++)
        {
            if (marks[i] > 90)
                GradePoints[i + 1] = 4.0;
            else if (marks[i] > 80)
                GradePoints[i + 1] = 3.5;
            else if (marks[i] > 70)
                GradePoints[i + 1] = 3.0;
            else if (marks[i] > 60)
                GradePoints[i + 1] = 2.5;
            else if (marks[i] > 50)
                GradePoints[i + 1] = 2.0;
        }

        if (marks_p_fund > 90)
            GradePoints[0] = 4.0;
        else if (marks_p_fund > 80)
            GradePoints[0] = 3.5;
        else if (marks_p_fund > 70)
            GradePoints[0] = 3.0;
        else if (marks_p_fund > 60)
            GradePoints[0] = 2.5;
        else if (marks_p_fund > 50)
            GradePoints[0] = 2.0;
    }

    void CalcGPA(){
        GPA = 0;
        for (int i = 0; i<4; i++){
            GPA += GradePoints[i];
        }
        GPA /= 4;
        
    }


};

int main()
{
    // Create student object
    Student s1;
    
    // Calculate grades and GPA
    s1.CalcGrade();
    s1.CalcGPA();
    
    // Display student information
    cout << "\n=== Student Information ===" << endl;
    s1.display();
    
    return 0;
}