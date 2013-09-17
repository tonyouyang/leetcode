// A message containing letters from A-Z is being encoded to numbers using the following mapping:

// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Given an encoded message containing digits, determine the total number of ways to decode it.

// For example,
// Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

// The number of ways decoding "12" is 2.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.length();
        if (len == 0) return 0;
        if (len == 1) return s[0] == '0' ? 0 : 1; // IMPORTANT!

        int c[3], j, i, i_1, i_2, t;
        c[0] = s[0] == '0' ? 0 : 1;
        c[2] = 1;

        for (j = 1, i = 1, i_1 = 0, i_2 = 2; j < len; ++j)
        {
        	bool valid = s[j - 1] == '1' || s[j - 1] == '2' && s[j] < '7';

            if (valid)
            	c[i] = s[j] == '0' ? c[i_2] : c[i_2] + c[i_1];
            else if (s[j] == '0')
            	c[i] = 0;
            else
            	c[i] = c[i_1];

            t = i_2;
            i_2 = i_1;
            i_1 = i;
            i = t;
        }

        return c[i_1];
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s;

    cin >> s;
    cout << solution.numDecodings(s) << endl;

    return 0;
}
