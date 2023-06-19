#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
void backtrack(vector<int> &arr, int start, vector<int> &temp)
{
    ans.push_back(temp);
    for (int i = start; i < arr.size(); i++)
    {
        temp.push_back(arr[i]);
        backtrack(arr, i + 1, temp);
        temp.pop_back();
    }
}
vector<vector<int>> subsets(vector<int> &arr)
{
    int n = arr.size();
    vector<int> temp;
    backtrack(arr, 0, temp);
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> matrix = subsets(arr);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}