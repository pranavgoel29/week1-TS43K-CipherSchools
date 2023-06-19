#include <bits/stdc++.h>
using namespace std;

#define POSSIBLEMOVES 4

int xMoves[] = {0, 0, 1, -1};
int yMoves[] = {1, -1, 0, 0};

bool isSafe(vector<vector<int>> &mat, vector<vector<bool>> &visited, int x, int y, const int &R, const int &C)
{
    return ((x >= 0 && x < R && y >= 0 && y < C) && !visited[x][y] && mat[x][y] == 1);
}

bool ratInMaze(vector<vector<int>> &mat, vector<vector<bool>> &visited, int x, int y, const int &R, const int &C)
{
    if (x == R - 1 && y == C - 1 && mat[R - 1][C - 1] == 1)
    {
        visited[x][y] = true;
        return true;
    }

    if (isSafe(mat, visited, x, y, R, C))
    {
        visited[x][y] = true;
        for (int i = 0; i < POSSIBLEMOVES; i++)
        {
            int nextX = x + xMoves[i];
            int nextY = y + yMoves[i];
            if (ratInMaze(mat, visited, nextX, nextY, R, C))
            {
                return true;
            }
        }
        visited[x][y] = false;
    }
    return false;
}

bool ranInMaze(vector<vector<int>> &mat)
{
    int R = mat.size();
    if (R == 0)
        return true;
    int C = mat[0].size();
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    return ratInMaze(mat, visited, 0, 0, R, C);
}

int main()
{
    vector<vector<int>> mat = {{1, 0, 0, 0}, {1, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 1, 1}};
    cout << ranInMaze(mat) << endl;
}