/**
 *
 * Problem:
 *
 * Solution:
 *
 * Time complexity: O(log n) for both update and query operations
 * Space complexity: O(n) for the segment tree
 *
 */

#include <bits/stdc++.h>

using namespace std;

#define MAX 200005
#define MAX_ST 800005

#define NEUTRAL {0, 0, 0, 0, 0}

struct Node
{
    int value, freq, leftValue, leftFreq, rightValue, rightFreq;
};

int n;           // Number of elements in the segtree
int v[MAX];      // Array of values
Node st[MAX_ST]; // Segtree (in this case storing interval sums)

// Merge contents of nodes a and b
Node merge(Node a, Node b)
{
    Node res;
    res.value = a.value;
    res.freq = a.freq;
    res.leftValue = a.leftValue;
    res.leftFreq = a.leftFreq;
    res.rightValue = b.rightValue;
    res.rightFreq = b.rightFreq;

    if (a.rightValue == b.leftValue)
    {
        int combinedFreq = a.rightFreq + b.leftFreq;
        if (combinedFreq > res.freq)
        {
            res.value = a.rightValue;
            res.freq = combinedFreq;
        }
    }

    if (a.leftValue == b.leftValue)
    {
        res.leftFreq += b.leftFreq;
    }

    if (a.rightValue == b.rightValue)
    {
        res.rightFreq += a.rightFreq;
    }

    if (b.freq > res.freq)
    {
        res.value = b.value;
        res.freq = b.freq;
    }

    return res;
}

// Build initial segtree (in position pos, interval [start,end])
void build(int pos, int start, int end)
{
    if (start == end)
    {
        st[pos] = {v[start], 1, v[start], 1, v[start], 1};
    }
    else
    {
        int middle = start + (end - start) / 2;
        build(pos * 2, start, middle);
        build(pos * 2 + 1, middle + 1, end);
        st[pos] = merge(st[pos * 2], st[pos * 2 + 1]);
    }
}

// Make a query of interval [x,y]
Node query(int pos, int start, int end, int x, int y)
{
    if (start > y || end < x)
        return NEUTRAL;
    if (start >= x && end <= y)
        return st[pos];

    int middle = start + (end - start) / 2;
    Node a = query(pos * 2, start, middle, x, y);
    Node b = query(pos * 2 + 1, middle + 1, end, x, y);
    return merge(a, b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    int q;
    while (true)
    {
        cin >> n;
        if (n == 0)
            break;
        cin >> q;

        for (int i = 0; i < n; i++)
            cin >> v[i];

        build(1, 0, n - 1);

        for (int i = 0; i < q; ++i)
        {
            int l, r;
            cin >> l >> r;
            Node res = query(1, 0, n - 1, l - 1, r - 1);
            cout << res.freq << '\n';
        }
    }

    return 0;
}