/**
 *
 * Problem:
 * You are given a playlist of a radio station since its establishment. The playlist has a total of n songs.
 * What is the longest sequence of successive songs where each song is unique?
 * The first input line contains an integer n: the number of songs.
 * The next line has n integers k_1,k_2,\ldots,k_n: the id number of each song.
 * Print the length of the longest sequence of unique songs.
 *
 * Solution:
 * the algorithm will use a vector ks to store the input and a map to store the frequency of each number
 * then it will use the sliding window technique to go through the ks vector with two pointers start and end
 *
 * the end pointer will shift to the right until a duplicate number is found,
 * then the start pointer will shift to the right until the duplicate number is removed
 *
 * every time the end pointer shifts to the right, if the window size is greater than the maxs variable, the maxs variable is updated
 *
 * Time complexity: O(n) - n time to go through the input + 2n time to for each pointer to go through the ks vector (n is the size of the input)
 * Space complexity: O(n) - n space to store the input + n space the frequency of each number (n is the size of the input)
 *
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, start = 0, end = 0, maxs = 1, duplicate = 0;
    cin >> n;
    vector<int> ks(n);
    map<int, int> freqs;

    for (int i = 0; i < n; i++)
    {
        cin >> ks[i];
    }

    freqs[ks[0]]++;

    while (end < n - 1)
    {
        if (duplicate != 0)
        {
            if (freqs[ks[start]] == 2)
                duplicate = 0;
            freqs[ks[start]]--;
            start++;
        }
        else
        {
            end++;
            freqs[ks[end]]++;
            if (freqs[ks[end]] > 1)
                duplicate = ks[end];
            else
                maxs = max(maxs, end - start + 1);
        }
        // cout << "(start, end, size, duplicate): (" << start << ", " << end << ", " << end - start + 1 << ", " << duplicate << ')' << endl;
    }

    cout << maxs << endl;

    return 0;
}