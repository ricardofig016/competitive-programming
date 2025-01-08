/*
Drawing Snowflakes
Sarah likes to draw snowflakes. A snowflake of size k can be defined as follows:

The center of the snowflake is the character '+'
Above and below the center there are k characters '|'
To the right and left the center there are k characters '-'
On the diagonals from the center to the upper left and to the bottom right there are k characters '\'
On the diagonals from the center to the upper right and to the bottom left there are k characters '/'
Sarah sometimes draws several connectes sknowflakes, but even then the size of each snowflake is determined separately (even if different snowflakes may share some characters.

.......
.......
..\|/..
..-+-..
../|\..
.......
.......
\.|./..
.\|/...
--+--..
./|\...
/.|.\|/
....-+-
..../|\
.......
.\.|./.
..\|/..
.--+---
../|\..
./...\.
.......
A snowflake of size 1	Two connectd skowflakes:
one of size 1 and another of size 2	A snowflake of size 1
(it's missing a '|' to be of size 2)
Sarah is currently drawing snowflakes on a piece of paper. However, she did not draw all snowflakes completely, and some are missing some characters (their size is equal to the smallest length of the corresponding character sequence from the center in one of the eight directions). Moreover, she drew some characters that are not part of any snowflake.

Task
Your task is to find the size of the largest snowflake in Sarah's drawing.

Input
The first line of input contains T, the number of test cases.

Each test case starts with a line containing two integers R and C indicating that the drawing is of R rows by and C columns.

In each of the following R lines there are C characters describing the drawing. The characters that can appear in the drawing are: '+', '-', '|', '\', '/' and '.'

Output
Output T lines, each one of them indicating the largest size of a snowflake on the respective input.

Constraints
The following limits are guaranteed in all the test cases that will be given to your program:

1 ≤ T ≤ 15	     	Number of test cases
1 ≤ R ≤ 50	     	Number of rows
1 ≤ C ≤ 50	     	Number of columns

Example Input	Example Output
3
5 6
\.\|/.
---+--
/./|\.
./.|.\
/..|..
7 7
\.|./..
.\|/...
--+--..
./|\...
/.|.\|/
....-+-
..../|\
7 7
\|/|\|/
-+-|-+-
/|\|/|\
---+---
\|/|\|/
-+-|-+-
/|\|/|\
1
2
1
Explanation of Example

1st case: Only one snowflake is drawn and of size 1
2nd case: Two connected snowflakes are drawn, the left one of size 2 and the right one of size 1
3rd case: Four snowflakes of size 1 are drawn
Distribution of Points
The test cases of this problem are organized as follows:

Group	% Points	Explanation
1	25%	There won't be any snowflake, or the largest snowflake will be of size 1.
2	25%	There will be at most one character '+' in the drawing.
3	50%	No additional constraints.
Time Limit on Mooshak: 1s
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    int t;
    cin >> t; // test cases

    while (t--)
    {
        int r, c; // rows, columns
        cin >> r >> c;

        vector<string> drawing(r);
        vector<pair<int, int>> centers; // center positions of snowflakes

        for (int i = 0; i < r; i++)
        {
            cin >> drawing[i];
            for (int j = 0; j < c; j++)
                if (drawing[i][j] == '+')
                    centers.push_back({i, j});
        }

        // for (const auto &line : drawing)
        //     cout << line << '\n';
        // cout << '\n';

        int max_size = 0;
        for (const pair<int, int> &center : centers)
        {
            int row = center.first;
            int col = center.second;

            int size = 0;
            while (row - size - 1 >= 0 && row + size + 1 < r && col - size - 1 >= 0 && col + size + 1 < c)
            {
                if (drawing[row - size - 1][col] == '|' && drawing[row + size + 1][col] == '|' &&
                    drawing[row][col - size - 1] == '-' && drawing[row][col + size + 1] == '-' &&
                    drawing[row - size - 1][col - size - 1] == '\\' && drawing[row + size + 1][col + size + 1] == '\\' &&
                    drawing[row - size - 1][col + size + 1] == '/' && drawing[row + size + 1][col - size - 1] == '/')
                    size++;
                else
                    break;
            }

            max_size = max(max_size, size);
        }

        cout << max_size << '\n';
    }

    return 0;
}