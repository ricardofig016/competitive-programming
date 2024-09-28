#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (size_t i = 0; i < t; i++)
    {
        string n, rn;
        cin >> n;
        rn = n;
        reverse(rn.begin(), rn.end());
        if (n == rn)
        {
            cout << "wins" << endl;
        }
        else
        {
            cout << "loses" << endl;
        }
    }

    return 0;
}