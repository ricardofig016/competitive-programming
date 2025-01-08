/**
 *
 * Problem: PRIME PATH
 *
 * Solution:
 * use BFS to find the shortest path between the given primes
 *
 * Time complexity: O() -
 * Space complexity: O() -
 *
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> generatePrimes(int start, int end)
{
    vector<bool> isPrime(end + 1, true);
    vector<int> primes;
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= end; ++i)
    {
        if (isPrime[i])
        {
            if (i >= start)
                primes.push_back(i);
            for (int j = i * 2; j <= end; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    return primes;
}

bool isOneDigitDiff(int a, int b)
{
    string sa = to_string(a);
    string sb = to_string(b);
    int diff = 0;
    for (int i = 0; i < 4; ++i)
    {
        if (sa[i] != sb[i])
            ++diff;
    }
    return diff == 1;
}

int bfs(int start, int end, const vector<int> &primes)
{
    unordered_set<int> primeSet(primes.begin(), primes.end());
    queue<pair<int, int>> q;
    unordered_set<int> visited;
    q.push({start, 0});
    visited.insert(start);

    while (!q.empty())
    {
        auto [current, steps] = q.front();
        q.pop();

        if (current == end)
            return steps;

        string s = to_string(current);
        for (int i = 0; i < 4; ++i)
        {
            char original = s[i];
            for (char c = '0'; c <= '9'; ++c)
            {
                if (c == original)
                    continue;
                s[i] = c;
                int next = stoi(s);
                if (next >= 1000 && primeSet.count(next) && !visited.count(next))
                {
                    q.push({next, steps + 1});
                    visited.insert(next);
                }
            }
            s[i] = original;
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    vector<int> primes = generatePrimes(1000, 9999);

    int t;
    cin >> t;
    while (t--)
    {
        int start, end;
        cin >> start >> end;
        if (start == end)
        {
            cout << 0 << endl;
        }
        else
        {
            int result = bfs(start, end, primes);
            if (result == -1)
            {
                cout << "Impossible" << endl;
            }
            else
            {
                cout << result << endl;
            }
        }
    }

    return 0;
}