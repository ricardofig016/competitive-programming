/**
 *
 * Problem: Rank the Languages
 *
 * Solution:
 * use DFS to count the number of connected components (states) for each language in the map
 *
 * Time complexity: O() -
 * Space complexity: O() -
 *
 */

#include <bits/stdc++.h>

using namespace std;

void dfs(vector<string> &map, vector<vector<bool>> &visited, int x, int y, char lang)
{
    int H = map.size();
    int W = map[0].size();
    stack<pair<int, int>> s;
    s.push({x, y});
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!s.empty())
    {
        auto [cx, cy] = s.top();
        s.pop();
        for (int i = 0; i < 4; ++i)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && map[nx][ny] == lang)
            {
                visited[nx][ny] = true;
                s.push({nx, ny});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int t = 1; t <= n; ++t)
    {
        int h, w;
        cin >> h >> w;
        vector<string> map(h);
        for (int i = 0; i < h; ++i)
        {
            cin >> map[i];
        }

        unordered_map<char, int> language_count;
        vector<vector<bool>> visited(h, vector<bool>(w, false));

        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                if (!visited[i][j])
                {
                    char lang = map[i][j];
                    visited[i][j] = true;
                    dfs(map, visited, i, j, lang);
                    language_count[lang]++;
                }
            }
        }

        vector<pair<int, char>> result;
        for (const auto &[lang, count] : language_count)
        {
            result.push_back({count, lang});
        }

        sort(result.begin(), result.end(), [](const pair<int, char> &a, const pair<int, char> &b)
             {
            if (a.first != b.first) return a.first > b.first;
            return a.second < b.second; });

        cout << "World #" << t << "\n";
        for (const auto &[count, lang] : result)
        {
            cout << lang << ": " << count << "\n";
        }
    }

    return 0;
}
