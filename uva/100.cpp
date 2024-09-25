#include <iostream>

using namespace std;

unsigned long long cyclelen(unsigned long long num)
{
    unsigned long long len = 1;
    while (num != 1)
    {
        if (num % 2 == 0)
            num /= 2;
        else
            num = 3 * num + 1;
        len++;
    }
    return len;
}

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