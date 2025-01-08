/**
 *
 * Problem: Game of Sum
 *
 * Solution:
 * dp[l][r] represents the maximum difference in points that player A can achieve over player B
 * if both players play optimally and the game is played on the subarray arr[l] to arr[r].
 *
 * Time complexity: O() -
 * Space complexity: O() -
 *
 */

#include <bits/stdc++.h>

using namespace std;

int solve(int l, int r, vector<int> &arr, vector<int> &sum, vector<vector<int>> &dp)
{
    if (l > r)
        return 0;
    if (l == r)
        return arr[l];

    int &ans = dp[l][r];
    if (ans != -1)
        return ans;

    ans = -999999;

    for (int i = l; i <= r; i++)
    {
        ans = max(ans, sum[i] - sum[l - 1] - solve(i + 1, r, arr, sum, dp));
        ans = max(ans, sum[r] - sum[i - 1] - solve(l, i - 1, arr, sum, dp));
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    int n;
    while (cin >> n && n != 0)
    {
        vector<vector<int>> dp(105, vector<int>(105, -1));
        vector<int> arr(105);
        vector<int> sum(105, 0);

        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            sum[i] = sum[i - 1] + arr[i];
        }

        int ans = solve(1, n, arr, sum, dp);
        cout << ans << endl;
    }
}