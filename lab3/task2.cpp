#include <iostream>
using namespace std;

class Student
{
    string name;
    int scores[5];

public:
    Student(string name)
    {
        this->name = name;
    }
    void input(int a, int b, int c, int d, int e)
    {
        scores[0] = a;
        scores[1] = b;
        scores[2] = c;
        scores[3] = d;
        scores[4] = e;
    }
    int calculateTotalScore()
    {
        return scores[0] + scores[1] + scores[2] + scores[3] + scores[4];
    }

    void display()
    {
        cout << "Student: " << name << endl;
        cout << "Scores: ";
        for (int i = 0; i < 5; i++)
        {
            cout << scores[i];
            if (i < 4)
                cout << ", ";
        }
        cout << endl;
        cout << "Total Score: " << calculateTotalScore() << endl
             << endl;
    }
};

int main()
{
    Student s1("Alice");
    Student s2("Bob");
    Student s3("Charlie");
    Student s4("Diana");
    Student s5("Eve");

    s1.input(85, 90, 78, 92, 88);
    s2.input(76, 82, 80, 85, 79);
    s3.input(95, 93, 97, 90, 94);
    s4.input(70, 75, 72, 78, 74);
    s5.input(88, 86, 90, 85, 87);
    s1.display();
    s2.display();
    s3.display();
    s4.display();
    s5.display();

    int maxScore = s1.calculateTotalScore();
    string topStudent = "Alice";

    if (s2.calculateTotalScore() > maxScore)
    {
        maxScore = s2.calculateTotalScore();
        topStudent = "Bob";
    }
    if (s3.calculateTotalScore() > maxScore)
    {
        maxScore = s3.calculateTotalScore();
        topStudent = "Charlie";
    }
    if (s4.calculateTotalScore() > maxScore)
    {
        maxScore = s4.calculateTotalScore();
        topStudent = "Diana";
    }
    if (s5.calculateTotalScore() > maxScore)
    {
        maxScore = s5.calculateTotalScore();
        topStudent = "Eve";
    }

    cout << "Top Student: " << topStudent << " with " << maxScore << " total points!" << endl;

    return 0;
}