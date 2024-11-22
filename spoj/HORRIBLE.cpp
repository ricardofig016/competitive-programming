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

#define MAX_SIZE 4 * 100000

void update(int node, int l, int r, int a, int b, int x, vector<long long> &sum, vector<long long> &child_sum)
{
    if (l > b || r < a)
        return;

    if (a <= l && r <= b)
        sum[node] += x;
    else
    {
        int mi = (l + r) >> 1;

        update(2 * node + 1, l, mi, a, b, x, sum, child_sum);
        update(2 * node + 2, mi + 1, r, a, b, x, sum, child_sum);

        child_sum[node] = child_sum[2 * node + 1] + child_sum[2 * node + 2] + (mi - l + 1) * sum[2 * node + 1] + (r - mi) * sum[2 * node + 2];
    }
}

long long query(int node, int l, int r, int a, int b, vector<long long> &sum, vector<long long> &child_sum)
{
    if (l > b || r < a)
        return 0;

    long long ret = (min(b, r) - max(a, l) + 1) * sum[node];
    if (a <= l && r <= b)
        ret += child_sum[node];
    else
    {
        int mi = (l + r) >> 1;
        ret += query(2 * node + 1, l, mi, a, b, sum, child_sum) + query(2 * node + 2, mi + 1, r, a, b, sum, child_sum);
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    int t, n, c;
    cin >> t;

    while (t--)
    {
        cin >> n >> c;
        vector<long long> sum(MAX_SIZE, 0);
        vector<long long> child_sum(MAX_SIZE, 0);

        int op, p, q, v;
        for (int i = 0; i < c; ++i)
        {
            cin >> op;

            if (op == 0)
            {
                cin >> p >> q >> v;
                update(0, 1, n, p, q, v, sum, child_sum);
            }
            else
            {
                cin >> p >> q;
                cout << query(0, 1, n, p, q, sum, child_sum) << endl;
            }
        }
    }

    return 0;
}