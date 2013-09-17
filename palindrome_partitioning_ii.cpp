// Given a string s, partition s such that every substring of the partition is a palindrome.

// Return the minimum cuts needed for a palindrome partitioning of s.

// For example, given s = "aab",
// Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
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

        bool p[len][len]; // whether s_i ~ s_j is palindrom
        int c[len + 1]; // min #partition of s_i ~ end
        memset(p, false, sizeof(p));
        memset(c, 0, sizeof(c));

        // tips : calc c[] from larger index, so it can be calc simultaneously with p[]
        for (int i = len - 1; i >= 0; --i)
            for (int j = i; j < len; ++j)
                if (s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1]))
                {
                	p[i][j] = true;
                	c[i] = c[i] == 0 ? c[j + 1] + 1 : min(c[i], c[j + 1] + 1);
                }

        return c[0] - 1;
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
