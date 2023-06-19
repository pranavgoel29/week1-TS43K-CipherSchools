#include <bits/stdc++.h>
using namespace std;

int minSwaps(string s)
{
    int left = 0, right = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '[')
            left++;
        else
        {
            if (left > 0)
            { // if a closing bracket arrives we can balance the the string by removing this closing bracket and an opening bracket with came just before this closing bracket
                left--;
            }
            else
            {
                right++;
            }
        }
    }
    int len = 2 * left; // new string length that will be formed by us after removing the closed square bracket with equal number of open brackets
    string samp = "";
    while (left + right > 0)
    { // new string getting formed of type "]]]]][[[[["
        if (left > 0)
        {
            samp += "]";
            left--;
        }
        else
        {
            samp += "[";
            right--;
        }
    }
    int swaps = 0; // counter for no. of swaps we have to do
    int i = 0;     // index necessary for swapping
    while (len > 0)
    {
        swaps++;
        samp[i] = '[';
        samp[samp.size() - i - 1] = ']';
        i = i + 2;
        len -= 4;
    }
    return swaps;
}

int main()
{
    string s = "][][";
    cout << minSwaps(s) << endl;
}