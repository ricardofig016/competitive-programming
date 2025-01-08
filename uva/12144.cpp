/**
 *
 * Problem: Almost Shortest Path
 *
 * Solution:
 * run Dijkstra's algorithm to find the shortest path,
 * remove the shortest path edges,
 * and then run Dijkstra's algorithm again to find the almost shortest path
 *
 * Time complexity: O() -
 * Space complexity: O() -
 *
 */

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

void dijkstra(int S, const vector<vector<pair<int, int>>> &adj, vector<int> &dist, vector<vector<int>> &parent)
{
    int N = adj.size();
    dist.assign(N, INF);
    parent.assign(N, vector<int>());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[S] = 0;
    pq.push({0, S});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto &edge : adj[u])
        {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
                parent[v].clear();
                parent[v].push_back(u);
            }
            else if (dist[u] + w == dist[v])
            {
                parent[v].push_back(u);
            }
        }
    }
}

void removeShortestPathEdges(int D, const vector<vector<int>> &parent, vector<vector<pair<int, int>>> &adj)
{
    queue<int> q;
    q.push(D);
    vector<bool> visited(adj.size(), false);
    visited[D] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int p : parent[u])
        {
            if (!visited[p])
            {
                visited[p] = true;
                q.push(p);
            }
            adj[p].erase(remove_if(adj[p].begin(), adj[p].end(), [u](const pair<int, int> &edge)
                                   { return edge.first == u; }),
                         adj[p].end());
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    while (true)
    {
        int N, M;
        cin >> N >> M;
        if (N == 0 && M == 0)
            break;

        int S, D;
        cin >> S >> D;

        vector<vector<pair<int, int>>> adj(N);
        for (int i = 0; i < M; ++i)
        {
            int U, V, P;
            cin >> U >> V >> P;
            adj[U].emplace_back(V, P);
        }

        vector<int> dist;
        vector<vector<int>> parent;
        dijkstra(S, adj, dist, parent);

        if (dist[D] == INF)
        {
            cout << -1 << endl;
            continue;
        }

        removeShortestPathEdges(D, parent, adj);

        dijkstra(S, adj, dist, parent);

        if (dist[D] == INF)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << dist[D] << endl;
        }
    }

    return 0;
}