/**
 *
 * Problem: Pie
 *
 * Solution:
 *
 * Time complexity: O() -
 * Space complexity: O() -
 *
 */

#include <bits/stdc++.h>

using namespace std;

constexpr double pi = 3.14159265358979323846;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, f;
        cin >> n >> f;
        vector<double> pies(n);
        f++; // the owner also gets a piece of pie

        for (int i = 0; i < n; i++)
        {
            int r;
            cin >> r;

            pies[i] = pi * r * r;
        }
        sort(pies.begin(), pies.end());

        // for (const auto &pie : pies)
        // {
        //     cout << pie << " ";
        // }
        // cout << endl;

        // binary search
        double l = 0, h = pies[n - 1];
        while (fabs(h - l) > 1e-5)
        {
            double mid = l + (h - l) / 2;
            // cout << "l: " << l << " mid: " << mid << " h: " << h << endl;
            int total = 0;
            for (int i = 0; i < n; i++)
            {
                total += static_cast<int>(pies[i] / mid);
                if (total >= f)
                    break;
            }
            if (total >= f)
            {
                cout << "with mid = " << mid << " (low = " << l << " and high = " << h << "), the total (" << total << ") surpasses the number of people (f+1 = " << f << "), so low will be updated to mid" << endl;
                l = mid;
            }
            else
            {
                cout << "with mid = " << mid << " (low = " << l << " and high = " << h << "), the total (" << total << ") does not reach the number of people (f+1 = " << f << "), so high will be updated to mid" << endl;
                h = mid;
            }
        }

        cout << fixed << setprecision(4) << l << endl;
    }

    return 0;
}