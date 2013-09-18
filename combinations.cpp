// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

// For example,
// If n = 4 and k = 2, a solution is:

// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<vector<int> > combine(int n, int k)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > combines;

        if (n < k) return combines;
        if (k == 0) return vector<vector<int> > (1, vector<int> ());

        for (int i = n; i > k - 1; i--)
        {
            vector<vector<int> > c = combine(i - 1, k - 1);

            for (int j = 0, l = c.size(); j < l; ++j)
            {
                c[j].push_back(i);
                combines.push_back(c[j]);
            }
        }

        return combines;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n, k;

    cin >> n >> k;
    vector<vector<int> > combines = solution.combine(n, k);
    for (int i = 0, l = combines.size(); i != l; ++i)
    {
        for (int j = 0; j < k; ++j) cout << combines[i][j] << " ";
        cout << endl;
    }

    return 0;
}
