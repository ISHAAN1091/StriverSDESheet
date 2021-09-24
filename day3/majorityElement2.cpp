#include <bits/stdc++.h>
using namespace std;

// Link :- https://leetcode.com/problems/majority-element-ii/

vector<int> majorityElement(vector<int> &nums)
{
    int n = nums.size();
    int count1 = 0, count2 = 0;
    int ans1 = -1, ans2 = -1;
    for (auto i : nums)
    {
        if (count1 == 0 && count2 == 0)
        {
            ans1 = i;
            count1++;
        }
        else if (count1 == 0)
        {
            if (i == ans2)
                count2++;
            else
            {
                ans1 = i;
                count1++;
            }
        }
        else if (count2 == 0)
        {
            if (i == ans1)
                count1++;
            else
            {
                ans2 = i;
                count2++;
            }
        }
        else
        {
            if (i == ans1)
                count1++;
            else if (i == ans2)
                count2++;
            else
                count1--, count2--;
        }
    }
    count1 = 0, count2 = 0;
    for (auto i : nums)
    {
        if (i == ans1)
            count1++;
        else if (i == ans2)
            count2++;
    }
    vector<int> output;
    if (count1 > n / 3)
        output.push_back(ans1);
    if (count2 > n / 3)
        output.push_back(ans2);
    return output;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> ans = majorityElement(arr);
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}