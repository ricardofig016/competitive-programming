#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned long long n;
    cin >> n;

    unsigned long long moves = 0;
    unsigned long long lastnum = 0;

    for (size_t i = 0; i < n; ++i)
    {
        unsigned long long num;
        cin >> num;

        if (num < lastnum)
        {
            moves += lastnum - num;
        }
        else
        {
            lastnum = num;
        }
    }

    cout << moves << endl;

    return 0;
}