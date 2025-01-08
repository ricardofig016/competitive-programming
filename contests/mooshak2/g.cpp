/*
Cruise Photos
Leo is looking at the photos his last cruise on the Mediterranean Sea, remembering unforgettable moments. The TV is on in the background, broadcasting news about the latest proposals for measures to slow down sea level rise. Looking at his photos of the coast, Leop asks himself what the photos would have looked like if sea level had risen a certain amount. There are so many pictures, and even more questions, so he needs your help.

We imagine the coast as a sequence of N numbers h1, 2, ... , hN, where the i-th number represents relief height at the i-th point. Leo has Q queries, where the i-th query is as following: how many islands would there be between the li-th and ri-th point if the sea level rose by xi meters?


The first query of the first sample test case.
The islands correspond to intervals [2, 2] and [4, 5].		The second query of the second sample test case
The islands correspond to intervals [1, 1], [4, 4], [8, 8] and [10, 10]
An island is defined as the maximal interval where every hi is strictly greater than the sea level. A maximal interval is one that cannot be extended in either direction while keeping the mentioned condition true. Initially, the sea level is at 0 meters.

Task
Given the sequence of heights representing the coast, your task is to answwer all Leo's queries, indicating the number of islands between the li-th and ri-th point if the sea level rose by xi meters.

Input
The first line contains integers N and Q, the length of the sequence and the number of queries.

The second line contains N integers h1, 2, ... , hN that describe the relief of the coast.

In each of the next Q lines there are three integers li, ri and xithat describe the i-th query.

Output
In the i-th of the Q lines print the answer to the i-th query. Each of the queries is independent of the others.

Constraints
The following limits are guaranteed in all the test cases that will be given to your program:

1 ≤ N ≤ 200 000	     	Length of the sequence
1 ≤ Q ≤ 200 000	     	Number of queries
0 ≤ hi ≤ 109	     	Height of a position on the coast
1 ≤ li ≤ ri ≤ N	     	Positions of queries
0 ≤ xi ≤ 109	     	Height of sea on a querie

Example Input 1	Example Output 1
6 3
2 4 2 3 4 1
2 5 2
3 5 3
3 4 4
2
1
0
Explanation of Example 1

The first query is shown in the left image in the task description, islands correspond to intervals [2, 2] and [4, 5]. In the second query island corresponds to interval [5, 5]. In the third query there are no islands because everything is under water


Example Input 2	Example Output 2
10 3
5 0 3 4 2 0 1 6 3 5
3 9 1
1 10 3
1 10 2
2
4
3
Explanation of Example 2

In the first query islands correspond to intervals [3, 5] and [8, 9]. In the second query (shown in the right image in the task description) islands correspond to intervals [1, 1], [4, 4], [8, 8] and [10, 10], while in the third query islands correspond to intervals [1, 1], [3, 4] and [8, 10].

Distribution of Points
The test cases of this problem are organized as follows:

Group	% Points	Explanation
1	10%	N,Q ≤ 2000
2	20%	li = 1, ri = n for all i = 1, 2, ... , Q
3	20%	There exists an integer p (1 ≤ p ≤ n) such that the following holds:
h1 ≥ h2 ≥ ... ≥ hp and hp ≤ hp+1 ≤ ... ≤ hN
4	50%	No additional constraints.
Time Limit on Mooshak: 8s
*/

#include <bits/stdc++.h>

using namespace std;

class SegmentTree
{
    vector<int> tree;
    int n;

public:
    SegmentTree(const vector<int> &heights)
    {
        n = heights.size();
        tree.resize(4 * n);
        build(heights, 0, 0, n - 1);
    }

    void build(const vector<int> &heights, int node, int start, int end)
    {
        if (start == end)
            tree[node] = heights[start];
        else
        {
            int mid = (start + end) / 2;
            build(heights, 2 * node + 1, start, mid);
            build(heights, 2 * node + 2, mid + 1, end);
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    int query(int l, int r, int node, int start, int end)
    {
        if (r < start || end < l)
            return INT_MIN;
        if (l <= start && end <= r)
            return tree[node];
        int mid = (start + end) / 2;
        int left_query = query(l, r, 2 * node + 1, start, mid);
        int right_query = query(l, r, 2 * node + 2, mid + 1, end);
        return max(left_query, right_query);
    }

    int query(int l, int r)
    {
        return query(l, r, 0, 0, n - 1);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    int n, q;
    cin >> n >> q;

    vector<int> heights(n);
    for (int i = 0; i < n; ++i)
        cin >> heights[i];

    SegmentTree segTree(heights);

    while (q--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        --l; // Convert to 0-based index
        --r; // Convert to 0-based index

        int islands = 0;
        bool inIsland = false;

        for (int i = l; i <= r; ++i)
        {
            if (heights[i] > x)
            {
                if (!inIsland)
                {
                    inIsland = true;
                    ++islands;
                }
            }
            else
                inIsland = false;
        }

        cout << islands << '\n';
    }

    return 0;
}
