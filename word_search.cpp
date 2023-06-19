#include <bits/stdc++.h>
using namespace std;

bool word_search(vector<vector<char>> &board, string word, int i, int j, int k)
{
    int n = board.size();
    int m = board[0].size();
    if (k == word.size())
        return true;
    if (i < 0 || i >= n || j < 0 || j >= m || word[k] != board[i][j] || board[i][j] == '#')
        return false;
    char ch = board[i][j];
    board[i][j] = '#'; // we dont want to revisit the previous char
    // checking the next char in all four directions
    bool op1 = word_search(board, word, i - 1, j, k + 1);
    bool op2 = word_search(board, word, i, j + 1, k + 1);
    bool op3 = word_search(board, word, i + 1, j, k + 1);
    bool op4 = word_search(board, word, i, j - 1, k + 1);
    board[i][j] = ch;                // putting back the real value of visited char
    return op1 || op2 || op3 || op4; // if one of them is true then it's true
}

bool exist(vector<vector<char>> &board, string word)
{
    int n = board.size();
    int m = board[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (word_search(board, word, i, j, 0))
                return true;
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    cout<<exist(board, word);
}