#include <bits/stdc++.h>
using namespace std;

// Link :- https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/

int *findTwoElement(int *arr, int n)
{
    // code here
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res ^= (i + 1);
        res ^= arr[i];
    }
    int idx = res & (~(res - 1));
    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        if ((i + 1) & idx)
            a ^= (i + 1);
        else
            b ^= (i + 1);
        if (arr[i] & idx)
            a ^= arr[i];
        else
            b ^= arr[i];
    }
    int *output = new int[2];
    if (count(arr, arr + n, a))
    {
        output[0] = a;
        output[1] = b;
    }
    else
    {
        output[0] = b;
        output[1] = a;
    }
    return output;
}

int main()
{
    int n;
    cin >> n;
    int arr[n] = {0};
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int *output = findTwoElement(arr, n);
    cout << "The repeating number is : " << output[0] << " \nThe missing number is : " << output[1] << endl;
    return 0;
}