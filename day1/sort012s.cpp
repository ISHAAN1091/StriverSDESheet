#include <bits/stdc++.h>
using namespace std;

// Link :- https://leetcode.com/problems/sort-colors/

void sortColors(vector<int> &nums)
{
    int n = nums.size();
    int i = 0, j = 0, k = n - 1;
    while (j <= k)
    {
        if (nums[j] == 0)
        {
            swap(nums[i++], nums[j++]);
        }
        else if (nums[j] == 2)
        {
            swap(nums[k--], nums[j]);
        }
        else
            j++;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sortColors(arr);
    for (auto i : arr)
        cout << i << ' ';
    cout << endl;
    return 0;
}