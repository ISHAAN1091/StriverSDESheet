#include <bits/stdc++.h>
using namespace std;

// Link :- https://leetcode.com/problems/rotate-image/solution/

void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; i++, j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            swap(matrix[i][j], matrix[i][n - j - 1]);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    rotate(arr);
    for (auto v : arr)
    {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}