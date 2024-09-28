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
        string d, n;
        cin >> d >> n;

        if (n.find('0') != string::npos || n.find('5') != string::npos)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}