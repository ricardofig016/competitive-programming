/*
Lego Cubes
For his birthday, Peter's parents bought him a brand-new set of Lego cubes. In the set, there are N cubes of equal size, where the i-th cube came in color i. Using these cubes he decided to build a wall.

Peter will build his wall on a row-like Lego base that has K places where cubes can be put in. He puts the cubes in the following way:

First, he puts the cube with color 1 on an arbitrary spot on the base.
For each cube from 2 to N, he places it in a spot neighboring (left or right) the previously placed cube. If that spot isn't empty, he puts the new cube on top of all the others on that spot.
After he built the wall, Peter wrote on a piece of paper a sequence of length K: on the i-th position in the sequence he wrote the color of the top cube in the i-th place, or 0 if there isn’t a cube in that place.

He immediately asked himself how many different sequences could he have written on the piece of paper. Two sequences are considered different if there exists a position in which they differ. After some time, he has managed to calculate the solution, but he is not sure whether it is correct, so he asks for your help.

Task
Given N and K, your task is to compute the number of different sequences Peter could have written on the paper, modulo 109+7.

Input
The first line of input contains T, the number of test cases.

Each of the following T lines specifies a test case, by giving two integers N and K the number of cubes, and the length of the base.

Output
Output T lines, one for each test case, indicating thehe answer to Peter's question, modulo 109+7.

Constraints
The following limits are guaranteed in all the test cases that will be given to your program:

1 ≤ T ≤ 3	     	Number of test cases
2 ≤ N ≤ 5 000	     	Number of cubes
2 ≤ K ≤ 5 000	     	Length of the base

Example Input	Example Output
3
4 3
3 5
100 200
8
14
410783331
Explanation of Example

For the first case, with N=3 and K=3, the eight possible sequences are: (0, 3, 4), (2, 3, 4), (0, 4, 3), (1, 4, 3), (4, 3, 0), (4, 3, 2), (3, 4, 0), (3, 4, 1)

For the second case, with N=3 and K=5, one of the possible sequences is (0, 3, 2, 0, 0). Peter can achieve that by putting the first cube on the second place, second cube on the third place, and third cube on the second place (on top of the first cube).

Distribution of Points
The test cases of this problem are organized as follows:

Group	% Points	Explanation
1	20%	N,K ≤ 18
2	20%	N,K ≤ 50
3	30%	N,K ≤ 500
4	30%	No additional constraints.
Time Limit on Mooshak: 3s
*/

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    int T;
    cin >> T;
    while (T--)
    {
        int N, K;
        cin >> N >> K;

        vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= N; ++i)
        {
            for (int j = 0; j < K; ++j)
            {
                if (dp[i - 1][j] > 0)
                {
                    if (j > 0)
                    {
                        dp[i][j - 1] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
                    }
                    if (j < K - 1)
                    {
                        dp[i][j + 1] = (dp[i][j + 1] + dp[i - 1][j]) % MOD;
                    }
                }
            }
        }

        for (int i = 0; i <= N; ++i)
        {
            for (int j = 0; j <= K; ++j)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        int result = 0;
        for (int j = 0; j < K; ++j)
        {
            result = (result + dp[N][j]) % MOD;
        }

        cout << result << endl;
    }

    return 0;
}