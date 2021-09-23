#include <bits/stdc++.h>
using namespace std;

// Link :- https://leetcode.com/problems/next-permutation/

void nextPermutation(vector<int> &nums)
{
    int i;
    for (i = nums.size() - 1; i >= 1; i--)
    {
        if (nums[i] > nums[i - 1])
            break;
    }
    if (i == 0)
    {
        reverse(nums.begin(), nums.end());
        return;
    }
    int j = i;
    while (j < nums.size() && nums[j] > nums[i - 1])
        j++;
    j--;
    swap(nums[i - 1], nums[j]);
    reverse(nums.begin() + i, nums.end());
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    nextPermutation(arr);
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
    return 0;
}