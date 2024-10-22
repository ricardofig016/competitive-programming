/**
 *
 * Problem: Interval Product
 *
 * Solution:
 *
 * Time complexity: O() -
 * Space complexity: O() -
 *
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    int n, k, x;
    while (cin >> n >> k)
    {
        // preprocessing
        vector<int> xs(n);
        vector<int> blocks(sqrt(n) + 1, 1);
        // cout << xs.size() << endl;
        // cout << blocks.size() << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            xs[i] = x == 0 ? 0 : x / abs(x);
            blocks[i / (int)ceil(sqrt(n))] *= xs[i];
            // cout << "i: " << i << ", i / sqrt(n): " << i / sqrt(n) << endl;
        }
        // cout << endl
        //      << "Test Case: " << endl
        //      << "n: " << n << endl
        //      << "sqrt(n): " << sqrt(n) << endl
        //      << "block_size: " << (int)ceil(sqrt(n)) << endl
        //      << "k: " << k << endl;
        // cout << "xs: ";
        // for (size_t i = 0; i < xs.size(); i++)
        //     cout << xs[i] << " ";
        // cout << endl
        //      << "blocks: ";
        // for (size_t i = 0; i < blocks.size(); i++)
        //     cout << blocks[i] << " ";
        // cout << endl;

        // queries and updates
        char command;
        int a, b;
        for (int i = 0; i < k; i++)
        {
            cin >> command >> a >> b;
            // update
            if (command == 'C')
            {
                a--; // offset
                int block_size = (int)ceil(sqrt(n)), block_i = a / block_size;
                xs[a] = b == 0 ? 0 : b / abs(b);
                blocks[block_i] = 1;
                // cout << "command: " << command << " " << a << " " << b << endl
                //      << "block_i: " << block_i << endl
                //      << "block_size: " << block_size << endl;
                for (int j = block_i * block_size; j < min(n, (block_i + 1) * block_size); j++)
                {
                    blocks[block_i] *= xs[j];
                    // cout << "j: " << j << endl
                    //      << "xs[j]: " << xs[j] << endl;
                }
                // cout << "Blocks: ";
                // for (size_t i = 0; i < blocks.size(); i++)
                //     cout << blocks[i] << " ";
                // cout << endl;
            }
            // querry
            else
            {
                // cout << "xs: ";
                // for (size_t i = 0; i < xs.size(); i++)
                //     cout << xs[i] << " ";
                // cout << endl
                //      << "blocks: ";
                // for (size_t i = 0; i < blocks.size(); i++)
                //     cout << blocks[i] << " ";
                // cout << endl;
                a--;
                b--;
                int result = 1;
                int block_size = (int)ceil(sqrt(n));
                while (a % block_size != 0 && a <= b)
                {
                    result *= xs[a];
                    a++;
                }
                while (a + block_size <= b)
                {
                    result *= blocks[a / sqrt(n)];
                    a += block_size;
                }
                while (a <= b)
                {
                    result *= xs[a];
                    a++;
                }
                cout << (result == -1  ? '-'
                         : result == 1 ? '+'
                         : result == 0 ? '0'
                                       : '?');
            }
        }
        cout << endl;
    }
    return 0;
}