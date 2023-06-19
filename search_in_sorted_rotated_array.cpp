#include <bits/stdc++.h>
using namespace std;

int searchSortedRotated(vector<int> &nums, int t)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] > nums[high])
            low = mid + 1;
        else
            high = mid;
    }
    int rot = low;
    low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int realmid = (mid + rot) % n;
        if (nums[realmid] == t)
            return realmid;
        if (nums[realmid] < t)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int t = 0;
    cout << searchSortedRotated(nums, t) << endl;
}