#include <iostream>
#include <vector>
using namespace std;

// Check if it's safe to place robot at (r, c)
bool isSafe(vector<vector<int>>& grid, int N, int r, int c)
{
    // Check column
    for (int i = 0; i < N; i++)
    {
        if (grid[i][c] == 1)
            return false;
    }

    // Directions for adjacency (8 directions)
    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr >= 0 && nr < N && nc >= 0 && nc < N)
        {
            if (grid[nr][nc] == 1)
                return false;
        }
    }

    return true;
}

// Backtracking function
int countRobotPlacements(vector<vector<int>>& grid, int N, int K, int row)
{
    // If we placed all robots
    if (K == 0)
        return 1;

    // If we reached end of grid
    if (row >= N)
        return 0;

    int count = 0;

    // Option 1: Try placing robot in this row
    for (int col = 0; col < N; col++)
    {
        if (isSafe(grid, N, row, col))
        {
            grid[row][col] = 1; // place robot

            count += countRobotPlacements(grid, N, K - 1, row + 1);

            grid[row][col] = 0; // backtrack
        }
    }

    // Option 2: Skip this row
    count += countRobotPlacements(grid, N, K, row + 1);

    return count;
}

int main()
{
    int N = 4;
    int K = 2;

    vector<vector<int>> grid(N, vector<int>(N, 0));

    int result = countRobotPlacements(grid, N, K, 0);

    cout << "Total valid placements: " << result << endl;

    return 0;
}