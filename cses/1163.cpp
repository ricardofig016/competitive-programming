/**
 *
 * Problem: Traffic Lights
 *
 * Solution:
 *
 * Time complexity: O() -
 * Space complexity: O() -
 *
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, x, p, start = 0, end = 0, longest = 0;
    set<int> ps;
    cin >> n >> x;

    while (cin >> p)
    {
        ps.insert(p);
        auto it = ps.find(p);
    }

    return 0;
}