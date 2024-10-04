/**
 *
 * Problem: [PC002] Cool Sequences
 * You are given a sequence of positive integers of length N, S=(s1​,s2​,...,sN) and your goal is to remove some elements so that it becomes a cool sequence.
 * In this problem, a sequence S is a cool sequence if for all elements x in S, the value x appears exactly x times in S
 * For example, (3,3,3), (4,2,4,1,4,2,4) and () (an empty sequence) are cool sequences, while (3,3,3,3) and (2,4,1,4,2) are not.
 * Given a sequence S with N elements, find the minimum number of elements that needs to be removed so that it will be a cool sequence.
 *
 * Solution:
 * the algorithm will increment 1 to the toremove variable while the frequency of the number is less than the number itself
 * then it will decrement all the incremented values for a specific number when the frequency of the number is equal to the number itself
 * then it will go back to incrementing 1 to the toremove variable every time the number appears again
 *
 * this will make it so that the toremove variable counts the amount of times a number appears before being "cool",
 * and then restarting this count from 0 when the number appears again, after being "cool"
 *
 *
 * Time complexity: O(n) - O(n) time to go through the input once (n is the size of the input)
 * Space complexity: O(n) - O(n) space to store the frequency of each number (n is the size of the input)
 *
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int toremove = 0;

    unordered_map<int, int> freqs;

    int num;

    for (size_t i = 0; i < n; i++)
    {
        cin >> num;

        freqs[num]++;

        if (freqs[num] == num)
            toremove -= num - 1;
        else
            toremove++;
    }

    cout << toremove << endl;

    return 0;
}