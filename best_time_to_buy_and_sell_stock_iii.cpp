// Say you have an array for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete at most two transactions.

// Note:
// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = prices.size();
        if (len < 2) return 0;

        int before_profit[len], total_profit = 0;
        before_profit[0] = 0;

        for (int i = 1, min_price = prices[0]; i < len; ++i)
        {
            before_profit[i] = max(prices[i] - min_price, before_profit[i - 1]);
            min_price = min(prices[i], min_price);
        }
        for (int i = len - 1, max_price = prices[len - 1], after_profit = 0; i >= 0; --i)
        {
            after_profit = max(after_profit, max_price - prices[i]);
            max_price = max(prices[i], max_price);
            total_profit = max(total_profit, i > 0 ? before_profit[i - 1] + after_profit : after_profit);
        }

        return total_profit;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int a[] = {3, 6, 4, 10, 7, 8};
    int b[] = {3, 6, 4, 8, 7, 9, 3, 10};
    int c[] = {5};
    int d[] = {1, 8};
    int e[] = {8, 1};
    vector<int> va(a, a + sizeof(a) / sizeof(int));
    vector<int> vb(b, b + sizeof(b) / sizeof(int));
    vector<int> vc(c, c + sizeof(c) / sizeof(int));
    vector<int> vd(d, d + sizeof(d) / sizeof(int));
    vector<int> ve(e, e + sizeof(e) / sizeof(int));

    cout << solution.maxProfit(va) << endl;
    cout << solution.maxProfit(vb) << endl;
    cout << solution.maxProfit(vc) << endl;
    cout << solution.maxProfit(vd) << endl;
    cout << solution.maxProfit(ve) << endl;

    return 0;
}
