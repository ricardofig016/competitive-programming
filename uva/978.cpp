/**
 *
 * Problem: Lemmings Battle!
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

    int n, b, sg, sb, power;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> b >> sg >> sb;
        multiset<int> green, blue;
        vector<int> g_insert, b_insert;
        for (int i = 0; i < sg; i++)
        {
            cin >> power;
            green.insert(power);
        }
        for (int i = 0; i < sb; i++)
        {
            cin >> power;
            blue.insert(power);
        }

        while (!green.empty() && !blue.empty())
        {
            for (int j = 0; j < b; j++)
            {
                if (green.empty() || blue.empty())
                    break;

                auto it_green = prev(green.end());
                auto it_blue = prev(blue.end());
                int green_power = *it_green;
                int blue_power = *it_blue;
                green.erase(it_green);
                blue.erase(it_blue);

                if (green_power > blue_power)
                    g_insert.push_back(green_power - blue_power);
                else if (blue_power > green_power)
                    b_insert.push_back(blue_power - green_power);
            }

            green.insert(g_insert.begin(), g_insert.end());
            g_insert.clear();
            blue.insert(b_insert.begin(), b_insert.end());
            b_insert.clear();
        }

        if (!green.empty())
        {
            cout << "green wins" << endl;
            for (auto it = green.rbegin(); it != green.rend(); it++)
                cout << *it << endl;
        }
        else if (!blue.empty())
        {
            cout << "blue wins" << endl;
            for (auto it = blue.rbegin(); it != blue.rend(); it++)
                cout << *it << endl;
        }
        else
            cout << "green and blue died" << endl;
        if (i < n - 1)
            cout << endl;
    }

    return 0;
}