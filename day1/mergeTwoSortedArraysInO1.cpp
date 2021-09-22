#include <bits/stdc++.h>
using namespace std;

// Link :- https://www.geeksforgeeks.org/merge-two-sorted-arrays-o1-extra-space/

int nextGap(int gap)
{
    if (gap == 1)
        return 0;
    return gap / 2 + gap % 2;
}

void merge(long long arr1[], long long arr2[], int n, int m)
{
    // code here
    for (int gap = (n + m) / 2; gap > 0; gap = nextGap(gap))
    {
        int i = 0, j = gap;
        for (; i < n && j < n; i++, j++)
        {
            if (arr1[i] > arr1[j])
                swap(arr1[i], arr1[j]);
        }
        j %= n;
        for (; i < n && j < m; i++, j++)
        {
            if (arr1[i] > arr2[j])
                swap(arr1[i], arr2[j]);
        }
        i %= n;
        for (; i < m && j < m; i++, j++)
        {
            if (arr2[i] > arr2[j])
                swap(arr2[i], arr2[j]);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    long long arr1[n], arr2[m];
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    for (int i = 0; i < m; i++)
        cin >> arr2[i];
    merge(arr1, arr2, n, m);
    for (int i = 0; i < n; i++)
        cout << arr1[i] << " ";
    for (int i = 0; i < m; i++)
        cout << arr2[i] << " ";
    cout << endl;
    return 0;
}