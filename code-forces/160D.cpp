/**
 *
 * Problem: Edges in MST
 *
 * Solution:
 *
 * Time complexity: O() -
 * Space complexity: O() -
 *
 */

#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int u, v, w, index;
    bool operator<(const Edge &other) const
    {
        return w < other.w;
    }
};

vector<int> parent, rankVec;

int find(int u)
{
    if (parent[u] != u)
    {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

bool unite(int u, int v)
{
    int rootU = find(u);
    int rootV = find(v);
    if (rootU != rootV)
    {
        if (rankVec[rootU] > rankVec[rootV])
        {
            parent[rootV] = rootU;
        }
        else if (rankVec[rootU] < rankVec[rootV])
        {
            parent[rootU] = rootV;
        }
        else
        {
            parent[rootV] = rootU;
            rankVec[rootU]++;
        }
        return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].index = i;
    }

    sort(edges.begin(), edges.end());

    parent.resize(n + 1);
    rankVec.resize(n + 1, 0);
    iota(parent.begin(), parent.end(), 0);

    vector<string> result(m);
    vector<Edge> mstEdges;

    for (const auto &edge : edges)
    {
        if (unite(edge.u, edge.v))
        {
            mstEdges.push_back(edge);
            result[edge.index] = "at least one";
        }
    }

    for (const auto &edge : mstEdges)
    {
        parent.assign(n + 1, 0);
        iota(parent.begin(), parent.end(), 0);
        rankVec.assign(n + 1, 0);

        bool isCritical = true;
        for (const auto &e : edges)
        {
            if (e.index != edge.index && unite(e.u, e.v))
            {
                if (find(edge.u) == find(edge.v))
                {
                    isCritical = false;
                    break;
                }
            }
        }
        if (isCritical)
        {
            result[edge.index] = "any";
        }
    }

    for (const auto &res : result)
    {
        if (res.empty())
        {
            cout << "none\n";
        }
        else
        {
            cout << res << "\n";
        }
    }

    return 0;
}