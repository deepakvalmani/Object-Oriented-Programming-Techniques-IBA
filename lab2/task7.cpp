#include <iostream>
using namespace std;

class Player
{
private:
    string firstName;
    string lastName;
    double monthlyContract;

public:
    Player(string f_name, string l_name, double m_sal)
    {
        firstName = f_name;
        lastName = l_name;
        if (m_sal < 0)
        {
            monthlyContract = 0.0;
        }
        else
        {
            monthlyContract = m_sal;
        }
    }

    double yearly_earnings()
    {
        return 12 * monthlyContract;
    }

    void display()
    {
        cout << "First Name: " << firstName << endl;
        cout << "Last Name: " << lastName << endl;
        cout << "yearly salary: " << monthlyContract << endl;
    }

    void update_contract(double val)
    {
        if (val > 0)
        {
            monthlyContract *= (val + 1);
        }
        else
        {
            cout << "please enter a valid percentage of increase." << endl;
        }
    }
};

// Player Test
int main()
{
    Player p1("Lionel", "Messi", 50000);
    Player p2("Cristiano", "Ronaldo", 60000);

    cout << "Initial Yearly Earnings:\n";
    p1.display();
    cout << endl;
    p2.display();

    // Increase contracts by 10%
    p1.update_contract(0.10);
    p2.update_contract(0.10);

    cout << "\nAfter 10% Increase:\n";
    p1.display();
    cout << endl;
    p2.display();

    return 0;
}