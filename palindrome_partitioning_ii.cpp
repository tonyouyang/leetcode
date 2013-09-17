// Given a string s, partition s such that every substring of the partition is a palindrome.

// Return the minimum cuts needed for a palindrome partitioning of s.

// For example, given s = "aab",
// Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minCut(string s)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.length();
        if (len == 0) return 0;

        vector<set<int> > p(len, set<int> ()); // {j} st. s_i ~ s_j is palindrom
        vector<int> c(len + 1, 0); // #partition before s_i

        for (int d = 0; d < len; ++d)
            for (int i = 0; i + d < len; ++i)
                if (s[i] == s[i + d])
                    if (d <= 1 || p[i + 1].find(i + d - 1) != p[i + 1].end())
                        p[i].insert(i + d);

        for (int i = 0; i < len; ++i)
            for (int j : p[i])
                c[j + 1] = c[j + 1] == 0 ? c[i] + 1 : min(c[j + 1], c[i] + 1);

        return c[len] - 1;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s;

    cin >> s;
    cout << solution.minCut(s) << endl;

    return 0;
}
