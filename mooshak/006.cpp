/**
 *
 * Problem: [PC006] Special Sort
 *
 * Solution:
 * the algorithm will read from input n elements and
 * sort them in descending order by the number of bits set to 1, using the __builtin_popcount function
 * if two numbers have the same number of bits set to 1, the smaller number will come first (ascending order)
 *
 * Time complexity: O(n log n) - n log n time to sort the input
 * Space complexity: O(n) - n space to store the input
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

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), [&](int a, int b)
         {
        int countA = __builtin_popcount(a);
        int countB = __builtin_popcount(b);
        if (countA == countB) {
            return a < b;
        }
        return countA > countB; });

    for (int i = 0; i < n; ++i)
    {
        if (i > 0)
            cout << " ";
        cout << arr[i];
    }
    cout << endl;

    return 0;
}