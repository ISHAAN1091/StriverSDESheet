#include <bits/stdc++.h>
using namespace std;

// Link :- https://www.geeksforgeeks.org/counting-inversions/

long long int merge(long long arr[], int start, int end)
{
    long long output[end - start + 1];
    int i = start, mid = start + (end - start) / 2, j = mid + 1;
    int k = 0;
    long long int count = 0;
    while (i <= mid && j <= end)
    {
        if (arr[i] > arr[j])
        {
            output[k++] = arr[i++];
            count += end - j + 1;
        }
        else
        {
            output[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        output[k++] = arr[i++];
    }
    while (j <= end)
    {
        output[k++] = arr[j++];
    }
    for (int x = start; x <= end; x++)
    {
        arr[x] = output[x - start];
    }
    return count;
}

long long int mergeSort(long long arr[], int start, int end)
{
    if (start >= end)
        return 0;
    int mid = start + (end - start) / 2;
    long long int count = 0;
    count += mergeSort(arr, start, mid);
    count += mergeSort(arr, mid + 1, end);
    count += merge(arr, start, end);
    return count;
}

long long int inversionCount(long long arr[], int n)
{
    return mergeSort(arr, 0, n - 1);
}

int main()
{
    int n;
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    long long int ans = inversionCount(arr, n);
    cout << ans << endl;
    return 0;
}