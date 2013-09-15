// Say you have an array for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit.
// You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times).
// However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

class Solution
{
public:
	// slower version
    // int maxProfit(vector<int> &prices)
    // {
    //     if (prices.empty()) return 0;

    //     int profit = 0;

    //     for (int i = 1, len = prices.size(); i < len; ++i)
    //     {
    //         int delta = prices[i] - prices[i - 1];

    //         if (delta > 0) profit += delta;
    //     }

    //     return profit;
    // }

    int maxProfit(vector<int> &prices)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.empty()) return 0;

        int profit = 0, len = prices.size(), bid_price = prices[0];
        bool hold = false;

        for (int i = 1; i < len; ++i)
        {
            if (prices[i] <= prices[i - 1])
            {
                if (hold)
                {
                    profit += prices[i - 1] - bid_price;
                    hold = false;
                }
            }
            else if (!hold)
            {
                bid_price = prices[i - 1];
                hold = true;
            }
        }
        if (hold) profit += prices[len - 1] - bid_price;

        return profit;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
