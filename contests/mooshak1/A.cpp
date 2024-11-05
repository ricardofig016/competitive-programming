#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    string s, result = "yes";

    cin >> s;
    s[0] = tolower(s[0]);

    // alphabetical order
    for (size_t i = 1; i < s.size(); i++)
    {
        if (s[i] < s[i - 1])
        {
            result = "no";
            break;
        }
    }

    if (result == "yes")
    {
        cout << result << endl;
        return 0;
    }

    // reverse alphabetical order
    result = "yes";
    for (size_t i = 1; i < s.size(); i++)
    {
        if (s[i] > s[i - 1])
        {
            result = "no";
            break;
        }
    }

    cout << result << endl;

    return 0;
}