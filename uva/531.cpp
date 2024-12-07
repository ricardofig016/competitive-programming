/**
 *
 * Problem: Compromise
 *
 * Solution: dp[i][j] represents the length of the LCS of the first i words of the first text and the first j words of the second text.
 *
 * Time complexity: O() -
 * Space complexity: O() -
 *
 */

#include <bits/stdc++.h>

using namespace std;

vector<string> split(const string &str)
{
    vector<string> words;
    stringstream ss(str);
    string word;
    while (ss >> word)
        words.push_back(word);
    return words;
}

vector<string> longestCommonSubsequence(const vector<string> &text1, const vector<string> &text2)
{
    int m = text1.size();
    int n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    vector<string> lcs;
    int i = m, j = n;
    while (i > 0 && j > 0)
        if (text1[i - 1] == text2[j - 1])
        {
            lcs.push_back(text1[i - 1]);
            --i;
            --j;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            --i;
        else
            --j;
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    string line;
    while (getline(cin, line))
    {
        if (line == "#")
            break;
        vector<string> text1 = split(line);
        while (getline(cin, line) && line != "#")
        {
            vector<string> words = split(line);
            text1.insert(text1.end(), words.begin(), words.end());
        }

        getline(cin, line);
        vector<string> text2 = split(line);
        while (getline(cin, line) && line != "#")
        {
            vector<string> words = split(line);
            text2.insert(text2.end(), words.begin(), words.end());
        }

        vector<string> lcs = longestCommonSubsequence(text1, text2);
        for (size_t i = 0; i < lcs.size(); i++)
            cout << lcs[i] << (i == lcs.size() - 1 ? "\n" : " ");
    }

    return 0;
}