#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    string s;
    getline(cin, s);

    int longest = 0;
    int current = 1;

    for (size_t i = 0; i < s.length(); i++)
    {
        if (s[i] == s[i - 1])
        {
            current++;
        }
        else
        {
            longest = max(longest, current);
            current = 1;
        }
    }

    cout << max(longest, current) << endl;

    return 0;
}