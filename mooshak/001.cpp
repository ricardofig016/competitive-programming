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
        string a, b;
        cin >> a >> b;
        int a_pointer = 0;
        int b_pointer = 0;
        while (a_pointer < a.length() && b_pointer < b.length())
        {
            if (a[a_pointer] == b[b_pointer])
            {
                a_pointer++;
                b_pointer++;
            }
            else
            {
                b_pointer++;
            }
        }
        cout << (a_pointer == a.length() ? "yes" : "no") << endl;
    }

    return 0;
}