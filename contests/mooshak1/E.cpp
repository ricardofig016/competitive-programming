#include <bits/stdc++.h>

using namespace std;

double compute_min_time(int x, int y, const vector<pair<int, int>> &route, int start_pos)
{
    int n = route.size();
    vector<int> dist(n);
    for (int i = 0; i < n; i++)
        dist[i] = abs(x - route[i].first) + abs(y - route[i].second);

    double min_time = INT_MAX;
    for (int t = 0; t < n; t++)
    {
        int pos = (start_pos + t) % n;
        int time_to_reach = dist[pos];
        if (time_to_reach <= t)
        {
            min_time = t;
            break;
        }
        else if (time_to_reach < min_time)
            min_time = time_to_reach;
    }
    // cout << "start_pos: " << start_pos << ", min_time: " << min_time << endl;
    return min_time;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    int x, y, n;
    cin >> x >> y >> n;

    vector<pair<int, int>> route(n);

    for (int i = 0; i < n; i++)
    {
        cin >> route[i].first >> route[i].second;
    }

    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        double min = compute_min_time(x, y, route, i);
        // cout << min << endl;
        sum += min;
    }

    double expected = sum / n;

    cout << fixed << setprecision(4) << expected << endl;

    return 0;
}