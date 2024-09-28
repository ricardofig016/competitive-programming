#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;

        if (n1 == n2)
        {
            cout << n3 << endl;
        }
        else if (n1 == n3)
        {
            cout << n2 << endl;
        }
        else
        {
            cout << n1 << endl;
        }
    }
    return 0;
}