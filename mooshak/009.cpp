/**
 *
 * Problem: KOPC12A - K12 - Building Construction
 *
 * Solution:
 * the algorithm performs ternary search on the heights of the buildings, tryng to find the lowest cost
 * then it returns the minimum cost between the floor and ceil of the best height
 *
 * Time complexity: O(n log n) - n log n time to sort the buildings + log n for the ternary search
 * Space complexity: O(n) - 2n space for the buildings (height and cost)
 *
 */

#include <bits/stdc++.h>

using namespace std;

long long cost(int k, vector<pair<int, int>> buildings)
{
    long long c = 0;
    for (const auto &building : buildings)
        c += abs(building.first - k) * building.second;
    return c;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> buildings(n); // heights and costs

        for (int j = 0; j < n; j++)
            cin >> buildings[j].first;
        for (int j = 0; j < n; j++)
            cin >> buildings[j].second;

        sort(buildings.begin(), buildings.end(), [](pair<int, int> a, pair<int, int> b)
             { return a.first < b.first; });

        // ternary search
        double low = buildings[0].first, high = buildings[n - 1].first;
        while (high - low > 1e-3)
        {
            double segm_size = (high - low) / 3;
            double mid1 = low + segm_size;
            double mid2 = high - segm_size;

            long long cost1 = 0, cost2 = 0;
            for (const auto &building : buildings)
            {
                cost1 += abs(building.first - mid1) * building.second;
                cost2 += abs(building.first - mid2) * building.second;
            }

            // cout << endl
            //      << "iteartion:" << endl
            //      << "low-high: " << low << "-" << high << endl
            //      << "mid1: " << mid1 << endl
            //      << "mid2: " << mid2 << endl
            //      << "cost1: " << cost1 << endl
            //      << "cost2: " << cost2 << endl;

            if (cost1 > cost2)
                low = mid1;
            else
                high = mid2;
        }

        // check low, low+1, high
        long long lowest_cost = min(cost(floor(low), buildings), cost(ceil(low), buildings));
        cout << lowest_cost << endl;

        // for (const auto &building : buildings)
        //     cout << building.first << " " << building.second << endl;
    }

    return 0;
}