#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);
    map<int, int> cache;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        auto index = cache.find(a[i]);
        if (index == cache.end())
        {
            cache[a[i]] = i + 1;
            b[i] = -1;
        }
        else
        {
            b[i] = index->second;
            cache[a[i]] = i + 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << b[i];
        if (i != n - 1)
            cout << " ";
    }
    cout << endl;

    return 0;
}