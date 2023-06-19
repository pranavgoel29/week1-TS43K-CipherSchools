#include <bits/stdc++.h>
using namespace std;

vector<int> slice2(int ind, vector<int> &nums)
{
    vector<int> slicedVector;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i == ind)
            continue;
        slicedVector.push_back(nums[i]);
    }
    return slicedVector;
}
vector<vector<int>> findPerm(vector<int> &nums)
{
    // base case
    if (nums.size() == 1)
    {
        return {nums};
    }
    vector<vector<int>> allperms;
    for (int i = 0; i < nums.size(); i++)
    {
        // Remove nums[i] and permute the remaining elements
        vector<int> newVector = slice2(i, nums);
        vector<vector<int>> perms = findPerm(newVector);
        for (int j = 0; j < perms.size(); j++)
        {
            perms[j].push_back(nums[i]);
        }
        for (int j = 0; j < perms.size(); j++)
        {
            allperms.push_back(perms[j]);
        }
    }
    return allperms;
}
vector<vector<int>> permute(vector<int> &nums)
{
    return findPerm(nums);
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> matrix = permute(nums);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}