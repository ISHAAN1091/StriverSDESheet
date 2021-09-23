#include <bits/stdc++.h>
using namespace std;

// Link :- https://leetcode.com/problems/pascals-triangle/

vector<vector<int>> generate(int numRows)
{
    if (numRows == 0)
        return {};
    vector<vector<int>> output;
    output.push_back({1});
    for (int i = 1; i < numRows; i++)
    {
        vector<int> temp;
        temp.push_back(1);
        for (int j = 1; j < output.back().size(); j++)
        {
            temp.push_back(output.back().at(j) + output.back().at(j - 1));
        }
        temp.push_back(1);
        output.push_back(temp);
    }
    return output;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> output = generate(n);
    for (auto v : output)
    {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}