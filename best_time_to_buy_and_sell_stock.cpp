// Say you have an array for which the ith element is the price of a given stock on day i.

// If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock),
// design an algorithm to find the maximum profit.

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
        if (prices.empty()) return 0;

        int profit = 0;
        
        for (int i = 0, min_price = prices[0], len = prices.size(); i < len; ++i)
        {
        	profit = max(prices[i] - min_price, profit);
        	min_price = min(prices[i], min_price);
        }

        return profit;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
