#include <iostream>
#include <vector>
using namespace std;

class Joseph_Game {
private:
    int n, m;
    vector<int> players;
    int index;

public:
    // Constructor
    Joseph_Game(int n, int m) {
        this->n = n;
        this->m = m;
        index = 0;

        // Fill players 0 to n-1
        for (int i = 0; i < n; i++) {
            players.push_back(i);
        }
    }

    // Simulation method (removes players until 1 remains)
    void  simulateGame() {
        while (players.size() > 1) {
            index = (index + m - 1) % players.size();
            cout<<players[index]<<"Is eliminated \n";
            players.erase(players.begin() + index);
        }
         cout<<"Survival "<<players[0]<<endl; // survivor
    }

    // Recurrence method (fast)
    int safePosRecurrence(int n, int m) {
        if (n == 1) return 0;
        return (safePosRecurrence(n - 1, m) + m) % n;
    }

    int getSafePosition() {
        return safePosRecurrence(n, m);
    }



};

int main() {
    int n, m;
    cout << "Enter n (players) and m (step): ";
    cin >> n >> m;

    Joseph_Game game(n, m);

    cout << "Safe Position (Recurrence) = " << game.getSafePosition() << endl;
    game.simulateGame();

    return 0;
}
