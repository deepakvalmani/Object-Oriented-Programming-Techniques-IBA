#include <iostream>
using namespace std;

class FootballTeam
{
private:
    string name;
    int goals;
    int points;

public:
    FootballTeam()
    {
        name = "Unknown";
        goals = 0;
        points = 0;
    }

    FootballTeam(string name, int goals, int points)
    {
        this->name = name;
        this->goals = goals;
        this->points = points;
    }

    void addGoals(int g)
    {
        goals += g;
    }

    void updatePoints(int p)
    {
        points += p;
    }

    void display()
    {
        cout << "Team Name: " << name << endl;
        cout << "Goals Scored: " << goals << endl;
        cout << "Total Points: " << points << endl;
    }

    ~FootballTeam()
    {
        cout << "Team " << name << " has been removed from the tournament." << endl;
    }

    FootballTeam operator+(FootballTeam &team)
    {
        FootballTeam temp;
        temp.name = this->name + " + " + team.name;
        temp.goals = this->goals + team.goals;
        temp.points = this->points + team.points;
        return temp;
    }

    friend void compareGoal(FootballTeam t1, FootballTeam t2);
};

void compareGoal(FootballTeam t1, FootballTeam t2)
{
    if (t1.goals > t2.goals)
        cout << t1.name << " performed better in the match." << endl;
    else if (t2.goals > t1.goals)
        cout << t2.name << " performed better in the match." << endl;
    else
        cout << "Both teams performed equally." << endl;
}

int main()
{
    FootballTeam team1("team1", 2, 3);
    FootballTeam team2("team2", 1, 1);

    team1.addGoals(1);
    team2.addGoals(2);

    team1.updatePoints(3);
    team2.updatePoints(1);

    team1.display();
    team2.display();

    compareGoal(team1, team2);

    FootballTeam combined = team1 + team2;
    combined.display();

    return 0;
}
