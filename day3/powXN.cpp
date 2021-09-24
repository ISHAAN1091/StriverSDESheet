#include <bits/stdc++.h>
using namespace std;

// Link :- https://leetcode.com/problems/powx-n/

double myPow(double x, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    if (n == -1)
        return 1 / x;
    double ans = myPow(x, n / 2);
    ans *= ans;
    if (n % 2 != 0 && n < 0)
        return ans / x;
    else if (n % 2 != 0)
        return x * ans;
    else
        return ans;
}

int main()
{
    double x;
    int n;
    cin >> x >> n;
    cout << myPow(x, n) << endl;
    return 0;
}