#include <bits/stdc++.h>
using namespace std;

// Link :- https://leetcode.com/problems/maximum-subarray/

int maxSubArray(vector<int> &nums)
{
    int sum = 0, maxSum = INT_MIN;
    for (auto i : nums)
    {
        sum += i;
        maxSum = max(sum, maxSum);
        if (sum < 0)
            sum = 0;
    }
    return maxSum;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << maxSubArray(arr) << endl;
    return 0;
}