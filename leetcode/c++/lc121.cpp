#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = static_cast<int>(prices.size());
        int left_ptr = 0;
        int right_ptr = 1;
        int max_profit = 0;
        while(right_ptr < len) {
            if(prices[left_ptr] > prices[right_ptr]) { // negative profit
                left_ptr++;
                if(left_ptr == right_ptr) {
                    right_ptr++;
                }
            } else {
                max_profit = max(max_profit, prices[right_ptr] - prices[left_ptr]);
                right_ptr++;
            }
        }
        return max_profit;
    }
};