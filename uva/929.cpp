/**
 *
 * Problem: Number Maze
 *
 * Solution:
 *
 * Time complexity: O() -
 * Space complexity: O() -
 *
 */

#include <bits/stdc++.h>

using namespace std;

struct Cell
{
    int x, y, cost;
    bool operator>(const Cell &other) const
    {
        return cost > other.cost;
    }
};

int dijkstra(const vector<vector<int>> &maze, int N, int M)
{
    vector<vector<int>> dist(N, vector<int>(M, INT_MAX));
    priority_queue<Cell, vector<Cell>, greater<Cell>> pq;
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    dist[0][0] = maze[0][0];
    pq.push({0, 0, maze[0][0]});

    while (!pq.empty())
    {
        Cell current = pq.top();
        pq.pop();

        if (current.x == N - 1 && current.y == M - 1)
        {
            return current.cost;
        }

        for (int i = 0; i < 4; ++i)
        {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M)
            {
                int newCost = current.cost + maze[nx][ny];
                if (newCost < dist[nx][ny])
                {
                    dist[nx][ny] = newCost;
                    pq.push({nx, ny, newCost});
                }
            }
        }
    }

    return -1; // Should never reach here if the maze is valid
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    int T;
    cin >> T;
    while (T--)
    {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> maze(N, vector<int>(M));

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                cin >> maze[i][j];
            }
        }

        cout << dijkstra(maze, N, M) << endl;
    }

    return 0;
}