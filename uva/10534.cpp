/**
 *
 * Problem: Wavio Sequence
 *
 * Solution:
 *
 * Time complexity: O() -
 * Space complexity: O() -
 *
 */

#include <bits/stdc++.h>

using namespace std;

// Longest Increasing Subsequence: for each element in the array, length of the longest increasing subsequence ending at that element
vector<int> calcLIS(const vector<int> &arr)
{
    int n = arr.size();
    vector<int> lis(n);
    vector<int> l(n);
    int lisCount = 0;
    for (int i = 0; i < n; ++i)
    {
        int pos = lower_bound(l.begin(), l.begin() + lisCount, arr[i]) - l.begin();
        l[pos] = arr[i];
        if (pos == lisCount)
            ++lisCount;
        lis[i] = pos + 1;
    }
    return lis;
}

// Longest Decreasing Subsequence: for each element in the array, length of the longest decreasing subsequence starting at that element
vector<int> calcLDS(const vector<int> &arr)
{
    int n = arr.size();
    vector<int> lds(n);
    vector<int> l(n);
    int ldsCount = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        int pos = lower_bound(l.begin(), l.begin() + ldsCount, arr[i]) - l.begin();
        l[pos] = arr[i];
        if (pos == ldsCount)
            ++ldsCount;
        lds[i] = pos + 1;
    }
    return lds;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    int n;
    while (cin >> n)
    {
        vector<int> arr(n);
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        vector<int> lis = calcLIS(arr);
        vector<int> lds = calcLDS(arr);

        // for (int i = 0; i < n; ++i)
        //     cout << "LIS[" << i << "] = " << lis[i] << ", LDS[" << i << "] = " << lds[i] << endl;

        int maxLength = 1;
        for (int i = 0; i < n; ++i)
            if (lis[i] > 1 && lds[i] > 1)
                maxLength = max(maxLength, min(lis[i], lds[i]) * 2 - 1);

        cout << maxLength << endl;
    }

    return 0;
}