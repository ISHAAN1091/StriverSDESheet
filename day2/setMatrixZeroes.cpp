#include <bits/stdc++.h>
using namespace std;

// Link :- https://leetcode.com/problems/set-matrix-zeroes/

void setZeroes(vector<vector<int>> &matrix)
{
    bool isCol = false;
    for (int i = 0; i < matrix.size(); i++)
    {
        if (matrix[i][0] == 0)
            isCol = true;
        for (int j = 1; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < matrix.size(); i++)
    {
        for (int j = 1; j < matrix[0].size(); j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }
    if (matrix[0][0] == 0)
    {
        for (int i = 0; i < matrix[0].size(); i++)
            matrix[0][i] = 0;
    }
    if (isCol)
    {
        for (int i = 0; i < matrix.size(); i++)
            matrix[i][0] = 0;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    setZeroes(mat);
    for (auto v : mat)
    {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}