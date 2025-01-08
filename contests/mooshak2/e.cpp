/*
Wall of Numbers
Mary came across a wall completely covered with numbers, arranged in a table of N rows and M columns. Soon she noticed that there was a frame leaning against the wall large enough to frame R rows and C columns of the table on the wall. And next to the frame she found a pencil and a piece of paper containing an empty table.

Mary is sad that the table on the piece of paper is empty, so she decided to play around with the frame to fill it.

She leaned the frame against the wall so that the number in the i-th row and j-th column is in the upper left corner, and the borders of the frame are parallel to the edges of the wall. Considering the numbers inside the frame, and since she like large numbers, she has decided to write the largest among them in the i-th row and j-th column of the table on the piece of paper.

Mary repeated the process for every possible position of the frame on the wall (such that the frame is entirely on the wall, and that there are exactly R×C numbers inside it), making sure that the edges of the frame are parallel to the edges of the wall.

When she was done, the table on the piece of paper was even more beautiful than the one on the wall!

Task
Your task is to compute the numbers that will be on the piece of the paper after she placed the frame on every possible position.

Input
The first line contains two integers N and M, the number of rows and columns of the table on the wall.

Each of the following N lines contain M integers ai,j, where ai,j is the number in the i-th row and j-th column of the table on the wall.

The last line contains two integers R and C, the size of the frame.

Output
Output the numbers written in the table on the piece of paper.

Constraints
The following limits are guaranteed in all the test cases that will be given to your program:

1 ≤ N,M ≤ 4 000	     	Dimensions of table on the wall
0 ≤ |ai,j| ≤ 10 000	     	Numbers on the wall
1 ≤ R ≤ N	     	Number of rows of the frame
1 ≤ C ≤ M	     	Number of columns of the frame

Example Input 1	Example Output 1
3 3
1 1 2
2 3 4
4 3 2
3 3
4
Explanation of Example 1

The frame is big enough to fit the entire table on the wall. The largest number inside the frame is 4, so that is the only number written on the table on the piece of paper.


Example Input 2	Example Output 2
3 3
1 1 2
2 3 4
4 3 2
2 1
2 3 4
4 3 4
Explanation of Example 2

All possible frame positions are shown in the picture below. The largest number for each of the positions is written in red:




Example Input 3	Example Output 3
5 5
-1 -3 -4 -2 4
-8 -7 -9 -10 11
5 2 -8 -2 1
13 -3 -2 -6 -9
11 6 2 7 4
2 3
-1 -2 11
5 2 11
13 2 1
13 7 7
Distribution of Points
The test cases of this problem are organized as follows:

Group	% Points	Explanation
1	10%	N, M ≤ 40, R = N, C = M
2	15%	N, M ≤ 40
3	25%	N, M ≤ 1 000
4	50%	No additional constraints.
Time Limit on Mooshak: 8s
*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> getMaxInRows(const vector<vector<int>> &matrix, int R, int C)
{
    int N = matrix.size();
    int M = matrix[0].size();
    vector<vector<int>> rowMax(N, vector<int>(M - C + 1));

    for (int i = 0; i < N; ++i)
    {
        deque<int> dq;
        for (int j = 0; j < M; ++j)
        {
            if (!dq.empty() && dq.front() == j - C)
            {
                dq.pop_front();
            }
            while (!dq.empty() && matrix[i][dq.back()] <= matrix[i][j])
            {
                dq.pop_back();
            }
            dq.push_back(j);
            if (j >= C - 1)
            {
                rowMax[i][j - C + 1] = matrix[i][dq.front()];
            }
        }
    }
    return rowMax;
}

vector<vector<int>> getMaxInColumns(const vector<vector<int>> &rowMax, int R, int C)
{
    int N = rowMax.size();
    int M = rowMax[0].size();
    vector<vector<int>> result(N - R + 1, vector<int>(M));

    for (int j = 0; j < M; ++j)
    {
        deque<int> dq;
        for (int i = 0; i < N; ++i)
        {
            if (!dq.empty() && dq.front() == i - R)
            {
                dq.pop_front();
            }
            while (!dq.empty() && rowMax[dq.back()][j] <= rowMax[i][j])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= R - 1)
            {
                result[i - R + 1][j] = rowMax[dq.front()][j];
            }
        }
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    int N, M, R, C;
    cin >> N >> M;
    vector<vector<int>> matrix(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> matrix[i][j];
        }
    }
    cin >> R >> C;

    vector<vector<int>> rowMax = getMaxInRows(matrix, R, C);
    vector<vector<int>> result = getMaxInColumns(rowMax, R, C);

    for (const auto &row : result)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}