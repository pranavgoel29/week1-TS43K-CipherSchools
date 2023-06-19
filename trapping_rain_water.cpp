#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &nums)
{
    int n = nums.size();
    int a[n];
    int b[n];

    a[0] = nums[0];
    b[n - 1] = nums[n - 1];

    // left
    for (int i = 1; i < n; i++)
    {
        a[i] = max(a[i - 1], nums[i]);
    }
    // right
    for (int i = (n - 2); i >= 0; i--)
    {
        b[i] = max(b[i + 1], nums[i]);
    }

    // final answer
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum = sum + (min(a[i], b[i])) - nums[i];
    }
    return sum;
}

int main()
{
    vector<int> nums = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    int sum = trap(nums);
    cout << "Sum: " << sum;
}