/**
 *
 * Problem: Traffic Lights
 *
 * Solution:
 * the algorithm will store all the lights in a set, which will automatically insert every ligth ordered (there cant be repeated lights)
 * when a light is inserted, it interrupts the segment that was between the previous and next light, so we remove that segment from the multiset
 * and insert the two new segments that were created by the new light (current-prev and next-current)
 * then the algorithm returns the last segment in segms, which is the biggest
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

    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    int n, x, light;
    cin >> n >> x;
    set<int> lights{0, n};
    multiset<int> segms{n};

    for (int i = 0; i < x; i++)
    {
        cin >> light;
        lights.insert(light);

        // cout << "light: " << light << ", next: " << *next(lights.find(light)) << ", prev: " << *prev(lights.find(light)) << endl;

        auto it = lights.find(light);
        segms.erase(segms.find(*next(it) - *prev(it)));
        segms.insert(light - *prev(it));
        segms.insert(*next(it) - light);

        cout << *segms.rbegin() << " ";
    }

    // for (int i = 0; i < x; i++)
    //     cout << lights[i] << " ";
    // cout << endl;

    return 0;
}