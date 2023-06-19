#include <bits/stdc++.h>
using namespace std;

void mergeSortedArrays(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int k = m + n - 1, i = m - 1, j = n - 1;
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k] = nums1[i];
            i--;
            k--;
        }
        else
        {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
    while (j >= 0)
    {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

int main()
{
    vector<int> nums1 = {1,3,4,0,0,0};
    vector<int> nums2 = {6,8,9};

    mergeSortedArrays(nums1, 3, nums2, 3);
    for(auto i:nums1){
        cout<<i<<" ";
    }
}