/**
 *
 * Problem: Trouble of 13-Dots
 *
 * Solution:
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

    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int m, n;
    while (cin >> m >> n)
    {
        vector<pair<int, int>> items(n);
        for (int i = 0; i < n; ++i)
            cin >> items[i].first >> items[i].second;

        int maxBudget = m;
        if (maxBudget > 1800)
            maxBudget += 200;

        vector<int> dp(maxBudget + 1, 0);

        for (int i = 1; i <= n; ++i)
            for (int j = maxBudget; j >= items[i].first; --j)
                if (dp[j - items[i].first] > 0 || j == items[i].first)
                    dp[j] = max(dp[j], dp[j - items[i].first] + items[i].second);

        int result = 0;
        if (m >= 1801 && m <= 2000)
        {
            result = *max_element(dp.begin(), dp.begin() + m);
            for (int j = 2001; j <= maxBudget; ++j)
                result = max(result, dp[j]);
        }
        else
            result = *max_element(dp.begin(), dp.end());

        cout << result << endl;
    }

    return 0;
}