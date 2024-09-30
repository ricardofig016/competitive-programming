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
        int n, k;
        cin >> n >> k;

        int counter = 0;

        if (k <= 1)
        {
            cout << n << endl;
            continue;
        }

        while (n > 0)
        {
            int exponent = static_cast<int>(log(n) / log(k));
            int largestPower = static_cast<int>(pow(k, exponent));

            n -= largestPower;
            counter++;
        }

        cout << counter << endl;
    }

    return 0;
}