/*
Sudoku Checker
Sudoku is a logic-based, combinatorial number-placement puzzle. The objective is to fill a 9×9 grid with digits from 1 to 9 in such a way that the following conditions hold:

Each row contains exactly one occurrence of each digit from 1 to 9.
Each column contains exactly one occurrence of each digit from 1 to 9.
Each of the nine 3×3 subgrids contains exactly one occurrence of each digit from 1 to 9.
Task
For a given (not yet finished) sudoku grid, determine if there is a mistake in it, that is, if one of the previous three conditions is not held). Note that is not necessary to check whether the sudoku grid is solvable, but simply if the already filled in cells obey the conditions.

Input
The first line of input contains T, the number of test cases.

Each test case starts has 13 lines describing the sudoku grid:

The characters '|', '-' and '+' frame the 3×3 subgrids.
The character '.' represents an empty cell.
All the other characters in the input will be digits from '1' to '9'.
Check the example input for clarification.

Output
Output T lines, each one of them with the word MISTAKE if there is a mistake on the board or OK if there isn't.

Constraints
The following limits are guaranteed in all the test cases that will be given to your program:

1 ≤ T ≤ 15	     	Number of test cases

Example Input	Example Output
3
+---+---+---+
|52.|...|.81|
|.39|58.|...|
|.8.|.9.|...|
+---+---+---+
|24.|...|1.3|
|1..|43.|86.|
|.63|..7|.24|
+---+---+---+
|...|1.9|35.|
|..8|.74|6..|
|31.|86.|7.9|
+---+---+---+
+---+---+---+
|3..|6..|..4|
|4.9|8.1|..7|
|..7|.49|6..|
+---+---+---+
|946|157|8.2|
|.2.|3..|745|
|.7.|28.|...|
+---+---+---+
|...|4..|..5|
|8.5|.6.|.2.|
|734|..8|5..|
+---+---+---+
+---+---+---+
|5..|98.|67.|
|6..|...|.31|
|.2.|613|.4.|
+---+---+---+
|.96|8.2|1.7|
|.28|..5|.9.|
|7.3|19.|6..|
+---+---+---+
|962|.7.|.1.|
|1.5|...|76.|
|.7.|5..|9..|
+---+---+---+
OK
MISTAKE
MISTAKE
Explanation of Example

1st case: There is no mistake, so the input is OK.
2nd case: There is a mistake in the 9th column: the digit 5 appears twice; there is also a mistake in the lower right 3×3 subgrid: the digit 5 appears twice.
3rd case: There are two mistakes: the digit 2 appears twice in the 2nd column, and the digit 6 appears twice in the 7th column.
Distribution of Points
The test cases of this problem are organized as follows:

Group	% Points	Explanation
1	25%	It's possible to determine whether there is a mistake by only checking the 1st condition
2	25%	It's possible to determine whether there is a mistake by only checking the 2nd condition
3	25%	It's possible to determine whether there is a mistake by only checking the 3rd condition
4	25%	No additional constraints.
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
        vector<string> grid;
        for (int i = 0; i < 13; i++)
        {
            string line;
            getline(cin, line);
            // cout << line << '\n';
            if (line.empty() || line[0] == '+')
            {
                continue;
            }

            line.erase(remove(line.begin(), line.end(), '|'), line.end());
            grid.push_back(line);
        }

        // cout << "GRID\n";
        // for (const auto &row : grid)
        // {
        //     cout << row << '\n';
        // }

        bool mistake = false;
        for (int i = 0; i < 9; i++)
        {
            string row = grid[i];
            string col = "";
            for (int j = 0; j < 9; j++)
                col += grid[j][i];

            sort(row.begin(), row.end());
            sort(col.begin(), col.end());

            for (int j = 0; j < 9; j++)
            {
                if (row[j] != '.' && row[j] == row[j + 1])
                {
                    mistake = true;
                    break;
                }

                if (col[j] != '.' && col[j] == col[j + 1])
                {
                    mistake = true;
                    break;
                }
            }

            for (int k = 0; k < 9; k += 3)
            {
                for (int l = 0; l < 9; l += 3)
                {
                    string square = "";
                    for (int m = 0; m < 3; m++)
                    {
                        for (int n = 0; n < 3; n++)
                        {
                            square += grid[k + m][l + n];
                        }
                    }
                    sort(square.begin(), square.end());
                    for (int p = 0; p < 9; p++)
                    {
                        if (square[p] != '.' && square[p] == square[p + 1])
                        {
                            mistake = true;
                            break;
                        }
                    }
                    if (mistake)
                        break;
                }
                if (mistake)
                    break;
            }
        }

        if (mistake)
        {
            cout << "MISTAKE\n";
        }
        else
        {
            cout << "OK\n";
        }
    }

    return 0;
}