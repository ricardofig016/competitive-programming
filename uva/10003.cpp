/**
 *
 * Problem: Cutting Sticks
 *
 * Solution:
 *
 * Time complexity: O() -
 * Space complexity: O() -
 *
 */

#include <bits/stdc++.h>

using namespace std;

int recurse(int left, int right, vector<int> &c, vector<vector<int>> &dp)
{
    if (dp[left][right] != -1)
        return dp[left][right];
    if (left + 1 == right)
        return dp[left][right] = 0;

    int best = 1000000;
    for (int i = left + 1; i < right; i++)
        best = min(best, recurse(left, i, c, dp) + recurse(i, right, c, dp) + c[right] - c[left]);
    return dp[left][right] = best;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    while (true)
    {
        int l, n;
        cin >> l >> n;
        if (l == 0)
            break;

        vector<int> c(55);
        c[0] = 0;
        c[n + 1] = l;
        for (int i = 1; i <= n; i++)
            cin >> c[i];

        vector<vector<int>> dp(55, vector<int>(55, -1));
        cout << "The minimum cutting is " << recurse(0, n + 1, c, dp) << "." << endl;
    }
}