/**
 *
 * Problem: String to Palindrome
 *
 * Solution: dp[i][j] represents the minimum number of operations required to convert the substring s[i...j] into a palindrome
 *
 * Time complexity: O() -
 * Space complexity: O() -
 *
 */

#include <bits/stdc++.h>

using namespace std;

int minOperationsToPalindrome(const string &s)
{
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len <= n; ++len)
        for (int i = 0; i <= n - len; ++i)
        {
            int j = i + len - 1;
            if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1];
            else
                dp[i][j] = 1 + min({dp[i + 1][j], dp[i][j - 1], dp[i + 1][j - 1]});
        }

    return dp[0][n - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    int t;
    string s;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cin >> s;
        cout << "Case " << i << ": " << minOperationsToPalindrome(s) << '\n';
    }

    return 0;
}