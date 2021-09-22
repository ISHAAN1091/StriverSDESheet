#include <bits/stdc++.h>
using namespace std;

// Link :- https://leetcode.com/problems/merge-intervals/

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    if (intervals.size() <= 1)
        return intervals;
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> output;
    for (auto i : intervals)
    {
        if (!output.empty() && output.back()[1] >= i[0])
        {
            output.back()[1] = max(output.back()[1], i[1]);
        }
        else
            output.push_back(i);
    }
    return output;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }
    vector<vector<int>> output = merge(arr);
    for (auto v : output)
    {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}