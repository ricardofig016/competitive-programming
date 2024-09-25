#include <iostream>

using namespace std;

unsigned long long reverse(unsigned long long num)
{
    unsigned long long rev = 0;
    while (num > 0)
    {
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    return rev;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned long long n;
    cin >> n;

    for (size_t i = 0; i < n; i++)
    {
        unsigned long long a, b;
        cin >> a >> b;
        cout << reverse(reverse(a) + reverse(b)) << endl;
    }

    return 0;
}