/**
 *
 * Problem: Bridge Building
 *
 * Solution:
 * Use DFS to determine the lowest and highest points of land on each column that can be connected by a bridge.
 * The mincost function calculates the minimum total length of bridges required,
 * ensuring that the bridges are separated by at least a specified number of columns.
 *
 * Note to self: Start using global variables (instead of declearing them inside main)
 * so that I don't have to pass them as arguments to functions.
 *
 * Time complexity: O() -
 * Space complexity: O() -
 *
 */

#include <bits/stdc++.h>

using namespace std;

void dfs_up(int i, int j, int N, int M, vector<vector<bool>> &grid, vector<vector<bool>> &visited, vector<int> &mostdown, const vector<int> &di, const vector<int> &dj)
{
    if (i < 0 || i >= N || j < 0 || j >= M || visited[i][j] || !grid[i][j])
        return;
    visited[i][j] = true;
    if (i + 1 < N && !grid[i + 1][j])
        mostdown[j] = max(mostdown[j], i + 1);
    for (int d = 0; d < 4; d++)
        dfs_up(i + di[d], j + dj[d], N, M, grid, visited, mostdown, di, dj);
}

void dfs_down(int i, int j, int N, int M, vector<vector<bool>> &grid, vector<vector<bool>> &visited, vector<int> &mostup, const vector<int> &di, const vector<int> &dj)
{
    if (i < 0 || i >= N || j < 0 || j >= M || visited[i][j] || !grid[i][j])
        return;
    visited[i][j] = true;
    if (i - 1 >= 0 && !grid[i - 1][j])
        mostup[j] = min(mostup[j], i - 1);
    for (int d = 0; d < 4; d++)
        dfs_down(i + di[d], j + dj[d], N, M, grid, visited, mostup, di, dj);
}

int mincost(int j, int b, int M, int S, vector<int> &mostup, vector<int> &mostdown, vector<vector<int>> &dp)
{
    const int INF = 1e9;
    if (j >= M)
        return b == 0 ? 0 : INF;
    if (b < 0)
        return INF;
    if (b == 0)
        return 0;
    if (dp[j][b] != -1)
        return dp[j][b];
    return dp[j][b] = min(mincost(j + 1, b, M, S, mostup, mostdown, dp), mincost(j + S + 1, b - 1, M, S, mostup, mostdown, dp) + mostup[j] - mostdown[j] + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    const vector<int> di = {1, 0, -1, 0};
    const vector<int> dj = {0, 1, 0, -1};

    int N, M, B, S;
    while (cin >> N >> M)
    {
        cin >> B >> S;
        vector<vector<bool>> grid(N, vector<bool>(M, false));
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        vector<int> mostdown(M, 0);
        vector<int> mostup(M, INT_MAX);
        vector<vector<int>> dp(M, vector<int>(B + 1, -1));

        char tmp;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> tmp;
                if (tmp == '#')
                    grid[i][j] = true;
            }
        }

        dfs_up(0, 0, N, M, grid, visited, mostdown, di, dj);
        fill(visited.begin(), visited.end(), vector<bool>(M, false)); // Reset visited array
        dfs_down(N - 1, 0, N, M, grid, visited, mostup, di, dj);

        cout << mincost(0, B, M, S, mostup, mostdown, dp) << endl;
    }

    return 0;
}