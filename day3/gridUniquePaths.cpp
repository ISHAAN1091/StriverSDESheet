#include <bits/stdc++.h>
using namespace std;

// Link :- https://leetcode.com/problems/unique-paths/

int uniquePaths(int m, int n)
{
    if (m == 1 || n == 1)
        return 1;
    m--, n--;
    long res = 1;
    int j = 1;
    for (int i = m + 1; i <= m + n; i++, j++)
    {
        res *= i;
        res /= j;
    }
    return (int)res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << uniquePaths(n, m) << endl;
    return 0;
}