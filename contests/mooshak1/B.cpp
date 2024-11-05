#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    int n, w;
    cin >> n >> w;

    vector<int> hs(n);

    for (int i = 0; i < n; i++)
    {
        cin >> hs[i];
    }

    sort(hs.begin(), hs.end(), greater<int>());

    for (int i = 0; i < n - w; i++)
    {
        if (hs[i] <= hs[i + w])
        {
            cout << "no" << endl;
            return 0;
        }
    }

    cout << "yes" << endl;

    return 0;
}