#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int i, j;
    while (cin >> i >> j)
    {
        int ans = 0;
        for (int num = min(i, j); num <= max(i, j); num++)
        {
            int x = num;
            int len = 1;
            while (x != 1)
            {
                if (x % 2 == 0)
                    x /= 2;
                else
                    x = 3 * x + 1;
                len++;
            }
            ans = max(ans, len);
        }

        cout << i << " " << j << " " << ans << endl;
    }

    return 0;
}