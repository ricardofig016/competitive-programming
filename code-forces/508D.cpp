/**
 *
 * Problem: Tanya and Password
 *
 * Solution:
 * 1. check the in-degrees and out-degrees of the nodes to determine if an Eulerian path is possible
 * 2. find the Eulerian path using a recursive function
 * 3. construct the password from the Eulerian path
 *
 * Time complexity: O() -
 * Space complexity: O() -
 *
 */

#include <bits/stdc++.h>

using namespace std;

unordered_map<string, vector<string>> adj;
unordered_map<string, int> in_degree, out_degree;
vector<string> path;

void findEulerianPath(string u)
{
    while (!adj[u].empty())
    {
        string v = adj[u].back();
        adj[u].pop_back();
        findEulerianPath(v);
    }
    path.push_back(u);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<string> substrings(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> substrings[i];
        string prefix = substrings[i].substr(0, 2);
        string suffix = substrings[i].substr(1, 2);
        adj[prefix].push_back(suffix);
        out_degree[prefix]++;
        in_degree[suffix]++;
    }

    string start_node;
    int start_nodes = 0, end_nodes = 0;
    for (auto &p : out_degree)
    {
        string node = p.first;
        int out = p.second;
        int in = in_degree[node];
        if (out - in == 1)
        {
            start_node = node;
            start_nodes++;
        }
        else if (in - out == 1)
        {
            end_nodes++;
        }
        else if (in != out)
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    if (start_nodes > 1 || end_nodes > 1)
    {
        cout << "NO" << endl;
        return 0;
    }

    if (start_nodes == 0)
    {
        start_node = substrings[0].substr(0, 2);
    }

    findEulerianPath(start_node);
    reverse(path.begin(), path.end());

    if (static_cast<int>(path.size()) != n + 1)
    {
        cout << "NO" << endl;
        return 0;
    }

    string result = path[0];
    for (size_t i = 1; i < path.size(); ++i)
    {
        result += path[i][1];
    }

    cout << "YES" << endl;
    cout << result << endl;

    return 0;
}