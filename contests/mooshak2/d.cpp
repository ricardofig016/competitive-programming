/*
Door Maze
Emma and Thomas are in a maze consisting of N×M rooms, all of the same size. The rooms form a grid. The top-left room is labeled with (1, 1), and the bottom-right with (N, M). Between each pair of adjacent rooms, there is a door colored in one of four colors: blue (marked with 'B'), red (marked with 'R'), green (marked with 'G') and orange (marked with 'O').


Illustration of the third example. The black circle marks the start room of the fourth at in the fourth question, and the white circle marks the end room. The gray path is one of the possible paths that passes through three different door colors.

Thomas asks Emma several questions of the type: if we are currently in room (ai, bi) and want to go to room (ci, di), what is the minimum number of door colors we have to go through?

Emma needs your help to answer the questions!

Task
Given the maze and several questions from Thomas, your task is to find for each one what is the minimium number of door colors you need to pass through to go from the start to the end room.

Input
The first line contains integers N and M, the dimensions of the maze

The i-th of the following N lines contains M-1 characters ('B', 'R', 'G' or 'O'), where the j-th character marks the colour of the door that connects rooms (i, j) and (i, j+1).

The i-th of the following N-1 lines contains M characters ('B', 'R', 'G' or 'O'), where the j-th character marks the colour of the door that connects rooms (i, j) and (i + 1, j).

The next line contains the integer Q, the number of Thomas' questions.

In the i-th of the following Q lines, there are four integers ai, bi, ci and di, the description of Thomas' i-th question. It is guaranteed that (ai, bi) ≠ (ci, di).

Output
The output should have Q lines. In the i-th of the lines, output the answer to Thomas' i-th question.

Constraints
The following limits are guaranteed in all the test cases that will be given to your program:

1 ≤ N,M ≤ 100	     	Dimensions of the maze
1 ≤ Q ≤ 100	     	Number of questions

Example Input 1	Example Output 1
1 8
RBGORRB
4
1 1 1 8
1 3 1 5
1 8 1 4
1 2 1 3
4
2
3
1

Example Input 2	Example Output 2
3 3
BB
BB
BB
RRR
RRR
3
1 1 3 3
3 3 2 2
1 1 1 3
2
2
1

Example Input 3	Example Output 3
4 4
RRR
RBR
BBB
ROB
GGGG
BBBB
RBGR
4
3 1 2 3
1 1 4 4
2 2 3 3
1 4 4 1
1
2
1
3
Explanation of Example 3

This example is illustrated in the problem statement:

For the first question we can can use just the blue doors.
For the second question, we can use blue and green doors.
For the third again only blue is enough.
For the fourth, we can use blue, green and red doors.
Distribution of Points
The test cases of this problem are organized as follows:

Group	% Points	Explanation
1	15%	N=1
2	15%	All doors that connect rooms (i,j) with (i,j+1) are blue
and all doors that connect rooms (i,j) with (i+1,j) are red.
3	35%	Every door is either red or blue.
4	35%	No additional constraints.
Time Limit on Mooshak: 2s
*/

#include <bits/stdc++.h>

using namespace std;

struct Room
{
    int x, y;
    set<char> colors;
    bool operator>(const Room &other) const
    {
        return colors.size() > other.colors.size();
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    int N, M;
    cin >> N >> M;

    vector<vector<char>> horizontalDoors(N, vector<char>(M - 1));
    vector<vector<char>> verticalDoors(N - 1, vector<char>(M));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M - 1; ++j)
        {
            cin >> horizontalDoors[i][j];
        }
    }

    for (int i = 0; i < N - 1; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> verticalDoors[i][j];
        }
    }

    int Q;
    cin >> Q;

    vector<tuple<int, int, int, int>> queries(Q);
    for (int i = 0; i < Q; ++i)
    {
        int ai, bi, ci, di;
        cin >> ai >> bi >> ci >> di;
        queries[i] = make_tuple(ai - 1, bi - 1, ci - 1, di - 1);
    }

    auto bfs = [&](int sx, int sy, int ex, int ey)
    {
        priority_queue<Room, vector<Room>, greater<Room>> pq;
        vector<vector<set<char>>> visited(N, vector<set<char>>(M));
        pq.push({sx, sy, {}});
        visited[sx][sy] = {};

        while (!pq.empty())
        {
            Room current = pq.top();
            pq.pop();

            if (current.x == ex && current.y == ey)
            {
                return current.colors.size();
            }

            vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
            for (auto [dx, dy] : directions)
            {
                int nx = current.x + dx;
                int ny = current.y + dy;
                if (nx >= 0 && nx < N && ny >= 0 && ny < M)
                {
                    char doorColor;
                    if (dx == 0 && dy == 1)
                        doorColor = horizontalDoors[current.x][current.y];
                    else if (dx == 1 && dy == 0)
                        doorColor = verticalDoors[current.x][current.y];
                    else if (dx == 0 && dy == -1)
                        doorColor = horizontalDoors[current.x][current.y - 1];
                    else if (dx == -1 && dy == 0)
                        doorColor = verticalDoors[current.x - 1][current.y];

                    set<char> newColors = current.colors;
                    newColors.insert(doorColor);

                    if (visited[nx][ny].empty() || visited[nx][ny].size() > newColors.size())
                    {
                        visited[nx][ny] = newColors;
                        pq.push({nx, ny, newColors});
                    }
                }
            }
        }
        return pq.top().colors.size(); // should never reach here
    };

    for (auto [ai, bi, ci, di] : queries)
    {
        cout << bfs(ai, bi, ci, di) << '\n';
    }

    return 0;
}