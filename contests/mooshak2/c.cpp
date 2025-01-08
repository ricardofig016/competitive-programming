/*
Learning to Fly
Steve, the penguin wants to learn how to fly!

The space in which he will learn to fly can be imagined as a cube of dimensions N×N×N, divided into N3 unit cubes. Each unit cube can be described with three coordinates (x, y, z), where x, y and z are integers between 1 and N. The coordinate x denotes the distance from the left edge of the space, the coordinate y denotes the distance from the front edge of the space, and the coordinate z denotes the height.

Some of these unit cubes contain clouds, and some do not. Steve is afraid of clouds, so he will learn to fly only where there are no clouds. He initially finds himself at a position (xs, ys, zs), such that zs = 1 (i.e. at height 1), and wants to get to position (xe, ye, ze).

At the moment, he is perfecting the skill of flying in directions that are parallel to one of the axes of space (i.e. in the direction of the x-axis, y-axis or z-axis), and in one wing flap he can cross at most one unit cube. Before he decides to fly, Steve wants to know how many wing flaps he needs to get to the desired position. While he is preparing for the flight, help him answer that question.

Task
Given the start and the end positions of Steve and the positions of the clouds, your task is to compute the minimum number of wing flaps to go from the start to the end position.

Input
The first line of input contains T, the number of test cases.

Each test case is described as follows:

The first line contains an integer B, the dimension of the space in which Steve learns to fly.
The second line contains three integers xs, ys and zs, the start position of Steve (zs=1).
The third line contains three integers xe, ye and ze, the end position of Steve.
This is followed by B binary matrices of dimensions B× B that describe the space, where the i-th matrix describes the space at height i. The upper-left corner has the coordinates (1, 1, i). The row and column of the matrix correspond to the x and y coordinates, respectively.
'0' denotes a unit cube in which there are no clouds, and '1' denotes a unit cube in which there are clouds.
The start and end position of Steve will not be a cloud.
Output
Output T lines, each one of them indicating the the smallest number of wing flaps that Steve must make to reach the desired position. If Steve cannot reach the desired position, print -1.

Constraints
The following limits are guaranteed in all the test cases that will be given to your program:

1 ≤ T ≤ 10	     	Number of test cases
1 ≤ N ≤ 100	     	Dimension of space
1 ≤ xs, ys, xe, ye,ze ≤ N	     	Coordinates of start and end position

Example Input	Example Output
3
2
1 1 1
1 1 2
00
10
01
00
3
2 3 1
1 1 1
000
010
000
111
111
111
111
111
111
3
2 1 1
3 2 2
000
010
110
010
001
001
101
110
000
1
3
3
Explanation of Example

1st case: Steve can reach the desired position in one wing flap by moving in the direction of the z-axis for one unit cube.
2nd case: Steve can reach the desired position in three wing flaps by first moving to position (1, 3, 1), then to (1, 2, 1) and finally to (1, 1, 1).
3rd case: Steve can reach the desired position in three wing flaps by first moving to position (2, 1, 2), then to (2, 2, 2) and finally to (3, 2, 2).
Distribution of Points
The test cases of this problem are organized as follows:

Group	% Points	Explanation
1	10%	N=2
2	20%	There are no clouds.
3	30%	All positions with z-coordinate greater than 1 will be clouds.
4	40%	No additional constraints.
Time Limit on Mooshak: 3s
*/

#include <bits/stdc++.h>

using namespace std;

struct Position
{
    int x, y, z, moves;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    int t; // test cases
    cin >> t;
    while (t--)
    {
        int b;          // size of the space
        int xs, ys, zs; // start position
        int xe, ye, ze; // end position
        cin >> b >> xs >> ys >> zs >> xe >> ye >> ze;

        // cout << "test case: " << t << "\n";

        vector<vector<vector<int>>> space(b, vector<vector<int>>(b, vector<int>(b)));
        for (int i = 0; i < b; i++)
            for (int j = 0; j < b; j++)
            {
                string row;
                cin >> row;
                for (int k = 0; k < b; k++)
                {
                    // cout << row[k] - '0' << " ";
                    space[j][k][i] = row[k] - '0'; // convert char to int
                }
                // cout << "\n";
            }
        // cout << "\n\n";

        queue<Position> q;
        vector<vector<vector<bool>>> visited(b, vector<vector<bool>>(b, vector<bool>(b, false)));

        q.push({xs - 1, ys - 1, zs - 1, 0});
        visited[xs - 1][ys - 1][zs - 1] = true;

        int directions[6][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
        int result = -1;

        // cout << "Start Position: (" << xs << ", " << ys << ", " << zs << ")\n";
        // cout << "cloud?: " << space[zs - 1][ys - 1][xs - 1] << "\n";
        // cout << "End Position: (" << xe << ", " << ye << ", " << ze << ")\n";
        // cout << "cloud?: " << space[ze - 1][ye - 1][xe - 1] << "\n";

        while (!q.empty())
        {
            Position current = q.front();
            q.pop();

            if (current.x == xe - 1 && current.y == ye - 1 && current.z == ze - 1)
            {
                result = current.moves;
                break;
            }

            for (auto &dir : directions)
            {
                int nx = current.x + dir[0];
                int ny = current.y + dir[1];
                int nz = current.z + dir[2];

                if (nx >= 0 && nx < b && ny >= 0 && ny < b && nz >= 0 && nz < b && !visited[nx][ny][nz] && space[nz][ny][nx] == 0)
                {
                    visited[nx][ny][nz] = true;
                    q.push({nx, ny, nz, current.moves + 1});
                }
            }
        }

        cout << result << "\n";
    }

    return 0;
}