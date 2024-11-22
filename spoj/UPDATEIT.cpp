/**
 *
 * Problem:
 *
 * Solution:
 *
 * Time complexity: O() -
 * Space complexity: O() -
 *
 */

#include <bits/stdc++.h>

using namespace std;

// primeria tentativa com fenwick tree (nao funcionou)
// void update(vector<int> &arr, vector<int> &fenwick, int idx, int val)
// {
//     arr[idx] += val;
//     for (size_t i = idx; i < fenwick.size(); i += i & -i)
//     {
//         // cout << "i: " << i << " i & -i: " << (i & -i) << endl;
//         fenwick[i] += val;
//     }

//     // cout << "Updated array: ";
//     // for (size_t i = 0; i < arr.size(); i++)
//     //     cout << arr[i] << " ";
//     // cout << endl;

//     // cout << "Updated Fenwick Tree: ";
//     // for (size_t i = 0; i < fenwick.size(); i++)
//     //     cout << fenwick[i] << " ";
//     // cout << endl;
// }

// int prefix_sum(vector<int> &fenwick, int idx)
// {
//     int sum_to_idx = 0;
//     for (size_t i = idx; i > 0; i -= i & -i)
//         // cout << "i: " << i << " | i & -i: " << (i & -i) << endl;
//         sum_to_idx += fenwick[i];
//     return sum_to_idx;
// }

// int query(vector<int> &fenwick, int idx)
// {
//     return prefix_sum(fenwick, idx) - prefix_sum(fenwick, idx - 1);
// }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    int t, n, u, q, idx;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n >> u;

        vector<int> arr(n, 0);
        vector<int> fenwick(n + 1, 0);

        int l, r, val;
        for (int i = 0; i < u; i++)
        {
            cin >> l >> r >> val;
            arr[l] += val;
            arr[r + 1] -= val;
        }

        for (int i = 1; i < n; i++)
            arr[i] += arr[i - 1];

        cin >> q;
        for (int i = 0; i < q; i++)
        {
            cin >> idx;
            cout << arr[idx] << endl;
        }
    }

    return 0;
}