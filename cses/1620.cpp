/**
 *
 * Problem: Factory Machines
 *
 * Solution:
 * sort the array times and use binary search to find the minimum time to produce t products
 *
 * Time complexity: O(n log(n)) - n log(n) time for sorting the array
 * Space complexity: O(n) - n space for storing the array
 *
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    long long n, t;
    cin >> n >> t;
    vector<long long> times(n);

    for (long long i = 0; i < n; ++i)
    {
        cin >> times[i];
    }
    sort(times.begin(), times.end());

    // binary search
    long long l = 0, h = times[0] * t;
    while (l < h)
    {
        long long mid = l + (h - l) / 2;
        long long total = 0;
        for (long long i = 0; i < n; ++i)
        {
            total += mid / times[i];
            if (total >= t)
                break;
        }
        if (total >= t)
            h = mid;
        else
            l = mid + 1;
    }

    cout << l << endl;

    return 0;
}