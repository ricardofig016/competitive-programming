/**
 *
 * Problem: Maximum Sum
 *
 * Solution:
 * 1. Create a 2D array 'sum' such that sum[i][j] is the sum of elements from the start of row i to column j-1.
 * 2. Create an array 'dp' such that dp[i] is the maximum sum of a subarray ending at column i.
 * 3. For each row k, calculate the sum of elements between columns i and j using the prefix sum array.
 * 4. Use Kadane's algorithm to calculate the maximum sum of a subarray ending at row k.
 *
 * Time complexity: O() -
 * Space complexity: O() -
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

    int n;
    cin >> n;

    int matrix[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];

    int sum[n][n + 1];
    for (int i = 0; i < n; i++)
    {
        sum[i][0] = 0;
        for (int j = 1; j <= n; j++)
            sum[i][j] = sum[i][j - 1] + matrix[i][j - 1];
    }

    int ans = -(1 << 30); // large negative value
    int dp[n + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            dp[0] = 0;
            for (int k = 0; k < n; k++)
            {
                dp[k + 1] = max(sum[k][j + 1] - sum[k][i] + dp[k], sum[k][j + 1] - sum[k][i]);
                ans = max(ans, dp[k + 1]);
                // cout << "i: " << i << ", j: " << j << ", k: " << k << ", sum: " << dp[k + 1] << endl;
            }
        }
    }

    cout << ans << endl;

    return 0;
}