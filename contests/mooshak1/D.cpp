#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    string s;
    getline(cin, s);

    char prev = s[0];

    int cost = 1 + 1 * (isupper(prev) ? 1 : 0);

    for (size_t i = 1; i < s.size(); i++)
    {
        if (s[i] == ' ')
            cost += 1 * (s[i - 1] != ' ');
        else if (s[i] == prev)
            cost += 1 * (s[i - 1] == ' ');
        else if (tolower(s[i]) == prev)
            cost += 1 + 1 * (s[i - 1] == ' ');
        else if (s[i] == tolower(prev))
            cost += 1 * (s[i - 1] == ' ');
        else if (isupper(s[i]) && islower(prev))
            cost += 2;
        else
            cost += 1;

        if (s[i] != ' ')
            prev = s[i];
    }

    cout << cost << endl;

    return 0;
}