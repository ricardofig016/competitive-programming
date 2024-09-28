#include <bits/stdc++.h>

using namespace std;

bool is_vowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (size_t i = 0; i < t; i++)
    {
        string n, s;
        cin >> n >> s;

        int counter = 0;
        for (size_t j = 0; j < s.length(); j++)
        {
            if (!is_vowel(s[j]))
            {
                counter++;
                if (counter == 4)
                {
                    cout << "no" << endl;
                    break;
                }
            }
            else
                counter = 0;
            if (j == s.length() - 1)
                cout << "yes" << endl;
        }
    }

    return 0;
}