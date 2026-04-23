#include <iostream>
#include <string>

using namespace std;

class Tic_Tac_Toe
{
private:
    int arr[3][3];
    string name1;
    string name2;

public:
    Tic_Tac_Toe()
    {
        ClearBoard();
    }

    void ClearBoard()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                arr[i][j] = 0;
            }
        }
    }

    string To_string()
    {
        string s = "";
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (arr[i][j] == 0)
                    s += ".";
                else if (arr[i][j] == 1)
                    s += "X";
                else
                    s += "O";

                if (j < 2)
                {
                    s += " | ";
                }
            }
            if (i < 2)
            {
                s += "\n---------\n";
            }
        }
        return s;
    }

    bool move(int player, int row, int col)
    {

        if (row < 0 || row >= 3 || col < 0 || col >= 3)
            return false;

        if (arr[row][col] != 0)
            return false;

        arr[row][col] = player;
        return true;
    }

    int gameStatus()
    {

        for (int i = 0; i < 3; i++)
        {
            if (arr[i][0] != 0 && arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2])
                return arr[i][0];
        }

        for (int j = 0; j < 3; j++)
        {
            if (arr[0][j] != 0 && arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j])
                return arr[0][j];
        }

        if (arr[0][0] != 0 && arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2])
            return arr[0][0];

        if (arr[0][2] != 0 && arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])
            return arr[0][2];

        bool boardFull = true;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (arr[i][j] == 0)
                {
                    boardFull = false;
                    break;
                }
            }
            if (!boardFull)
                break;
        }

        if (boardFull)
            return 3;
        return 0;
    }
};

int main()
{
    Tic_Tac_Toe t;
    string play = "yes";
    int currentPlayer = 1;

    while (play == "yes" || play == "Yes")
    {
        t.ClearBoard();
        cout << "New Tic-Tac-Toe Game!\n";

        int status = 0;
        int moves = 0;

        while (true)
        {
            cout << t.To_string() << endl;

            status = t.gameStatus();
            if (status == 1)
            {
                cout << "Player 1 (X) wins!\n";
                break;
            }
            else if (status == 2)
            {
                cout << "Player 2 (O) wins!\n";
                break;
            }
            else if (status == 3)
            {
                cout << "It's a draw!\n";
                break;
            }

            cout << "Player " << currentPlayer << " ("
                 << (currentPlayer == 1 ? "X" : "O") << ") turn.\n";

            int r, c;
            cout << "Enter row (0-2) and column (0-2): ";
            cin >> r >> c;

            if (!t.move(currentPlayer, r, c))
            {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            currentPlayer = (currentPlayer == 1) ? 2 : 1;
            moves++;
        }

        cout << "\nDo you want to play again? (yes/no): ";
        cin >> play;
    }

    cout << "Thanks for playing!\n";
    return 0;
}