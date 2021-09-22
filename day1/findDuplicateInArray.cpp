#include <bits/stdc++.h>
using namespace std;

// Link :- https://leetcode.com/problems/find-the-duplicate-number/

int findDuplicate(vector<int> &nums)
{
    int slow = nums[0], fast = nums[0];
    slow = nums[slow];
    fast = nums[nums[fast]];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    fast = nums[0];
    while (fast != slow)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return fast;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int ans = findDuplicate(arr);
    cout << ans << endl;
    return 0;
}