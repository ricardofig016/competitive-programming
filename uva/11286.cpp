#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;
    while (n != 0)
    {
        unordered_map<string, int> cs_freqs;

        for (size_t i = 0; i < n; i++)
        {
            set<int> cs;
            for (size_t i = 0; i < 5; i++)
            {
                int c;
                cin >> c;
                cs.insert(c);
            }

            stringstream ss;
            for (const int &num : cs)
            {
                ss << num;
            }
            string cs_str = ss.str();

            cs_freqs[cs_str]++;
        }

        int max_freq = 0;
        for (const auto &pair : cs_freqs)
            if (pair.second > max_freq)
                max_freq = pair.second;

        int student_count = 0;
        for (const auto &pair : cs_freqs)
            if (pair.second == max_freq)
                student_count += pair.second;

        cout << student_count << endl;

        cin >> n;
    }

    return 0;
}