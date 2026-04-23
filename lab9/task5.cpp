#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    double score;
};

int main() {

    // Input data (at least 6 students)
    vector<Student> students = {
        {"Alice", 85},
        {"Bob", 60},
        {"Charlie", 72},
        {"David", 45},
        {"Eve", 90},
        {"Frank", 50}
    };

    int n = students.size();

    // (i) Grades vector
    vector<string> grades(n);

    transform(students.begin(), students.end(), grades.begin(),
        [](Student s) {
            if (s.score >= 80) return string("A");
            else if (s.score >= 65) return string("B");
            else if (s.score >= 50) return string("C");
            else return string("F");
        }
    );

    // (ii) Curved scores (+5, max 100)
    vector<double> curved(n);

    transform(students.begin(), students.end(), curved.begin(),
        [](Student s) {
            double newScore = s.score + 5;
            if (newScore > 100) newScore = 100;
            return newScore;
        }
    );

    // (iii) Name + Grade
    vector<string> result(n);

    transform(students.begin(), students.end(),
              grades.begin(),
              result.begin(),
        [](Student s, string g) {
            return s.name + ": " + g;
        }
    );

    // Print all results

    cout << "Grades:\n";
    for (auto g : grades) cout << g << " ";
    cout << endl;

    cout << "Curved Scores:\n";
    for (auto c : curved) cout << c << " ";
    cout << endl;

    cout << "Name + Grade:\n";
    for (auto r : result) cout << r << endl;

    return 0;
}