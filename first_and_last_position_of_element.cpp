#include <bits/stdc++.h>
using namespace std;

int firstOccurrence(vector<int> &nums, int start, int end, int target)
{
    if (start > end)
        return -1;
    else if (start == end)
    {
        return (nums[start] == target ? start : -1);
    }
    else
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] < target)
        {
            return firstOccurrence(nums, mid + 1, end, target);
        }
        else if (nums[mid] > target)
        {
            return firstOccurrence(nums, start, mid - 1, target);
        }
        else
        {
            if ((mid == 0) || (mid >= 1 && nums[mid - 1] < nums[mid]))
                return mid;
            return firstOccurrence(nums, start, mid - 1, target);
        }
    }
}

int lastOccurrence(vector<int> &nums, int start, int end, int target)
{
    if (start > end)
        return -1;
    else if (start == end)
    {
        return nums[start] == target ? start : -1;
    }
    else
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] < target)
        {
            return lastOccurrence(nums, mid + 1, end, target);
        }
        else if (nums[mid] > target)
        {
            return lastOccurrence(nums, start, mid - 1, target);
        }
        else
        {
            if ((mid == nums.size()-1) || (mid + 1 <= nums.size()-1 && nums[mid] < nums[mid + 1]))
                return mid;
            return lastOccurrence(nums, mid + 1, end, target);
        }
    }
}

vector<int> firstAndLastOccurrence(vector<int> &nums, int target)
{
    int first = firstOccurrence(nums, 0, nums.size() - 1, target);
    int last = lastOccurrence(nums, first, nums.size() - 1, target);
    // return {first, last};
    cout<<"First index: "<<first<<"\nEnd index: "<<last<<endl;
}

int main()
{
    system("cls");
    vector<int> nums = {1,2,3,4,4,5,5,7};
    int target = 4;
    firstAndLastOccurrence(nums, target);
    
}