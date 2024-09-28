#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int w;
    cin >> w;
    cout << (w > 3 && w % 2 == 0 ? "YES" : "NO") << endl;

    return 0;
}