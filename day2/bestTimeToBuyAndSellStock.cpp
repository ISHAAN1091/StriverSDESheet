#include <bits/stdc++.h>
using namespace std;

// Link :- https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

int maxProfit(vector<int> &prices)
{
    int buy = prices[0], maxProfit = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        maxProfit = max(maxProfit, prices[i] - buy);
        buy = min(prices[i], buy);
    }
    return maxProfit;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int ans = maxProfit(arr);
    cout << ans << endl;
    return 0;
}