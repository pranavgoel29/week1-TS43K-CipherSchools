#include <bits/stdc++.h>
using namespace std;

vector<string> dialpad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void letterCombinations(string &input, string &strSoFar, vector<string> &result, int start, int end)
{
    if (start > end)
    {
        result.push_back(strSoFar);
        return;
    }
    else
    {
        char digitpressed = input[start];
        string possibleMoves = dialpad[digitpressed - '0'];

        for (int i = 0; i < possibleMoves.length(); i++)
        {
            strSoFar.push_back(possibleMoves[i]);
            letterCombinations(input, strSoFar, result, start + 1, end);
            strSoFar.pop_back();
        }
    }
}

vector<string> generateParenthesis(string &input)
{
    vector<string> result;
    int start = 0, end = input.length() - 1;
    string strSoFar = "";
    letterCombinations(input, strSoFar, result, start, end);
    return result;
}

int main()
{
    string n = "29";
    vector<string> res = generateParenthesis(n);
    for (auto n : res)
        cout << n << " ";
}