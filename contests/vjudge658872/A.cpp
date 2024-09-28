#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    cin.ignore();

    for (size_t i = 0; i < t; i++)
    {
        string h, g;
        getline(cin, h);
        getline(cin, g);

        string m = "bbbbb";
        for (size_t i = 0; i < 5; i++)
        {
            if (h[i] == g[i])
            {
                m[i] = 'g';
            }
        }
        cout << m << endl;
    }

    return 0;
}