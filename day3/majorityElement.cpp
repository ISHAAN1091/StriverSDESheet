#include <bits/stdc++.h>
using namespace std;

// Link :- https://leetcode.com/problems/majority-element/

int majorityElement(vector<int> &nums)
{
    int count = 0;
    int ans = -1;
    for (auto i : nums)
    {
        if (count == 0)
        {
            ans = i;
        }
        count += (i == ans ? 1 : -1);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int ans = majorityElement(arr);
    cout << ans << endl;
    return 0;
}