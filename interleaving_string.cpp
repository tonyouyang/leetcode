// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

// For example,
// Given:
// s1 = "aabcc",
// s2 = "dbbca",

// When s3 = "aadbbcbcac", return true.
// When s3 = "aadbbbaccc", return false.

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int s1_len = s1.length(), s2_len = s2.length(), s3_len = s3.length();

        if (s1_len + s2_len != s3_len) return false;
        if (s1_len == 0 && s2_len == 0) return true;

        if (s1_len > s2_len) {
            swap(s1, s2);
            swap(s1_len, s2_len);
        }

        bool v[2][s1_len + 1];
        bool ret;
        memset(v, false, sizeof(v));

        v[0][0] = true;
        for (int i = 1, j_min = 0; i != s3_len + 1; ++i)
        {
            int curr = i & 1, prev = curr ^ 1;

            ret = false;
            for (int j = max(j_min, i - s2_len); j <= s1_len; ++j)
            {
                v[curr][j] = j > 0 && v[prev][j - 1] && s1[j - 1] == s3[i - 1];
                v[curr][j] = v[curr][j] || (v[prev][j] && s2[i - j - 1] == s3[i - 1]);
                ret = ret || v[curr][j];
            }
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string a0("abc"), b0("def"), c0("abdefc"); // true
    string a1("abc"), b1("def"), c1("abfedc"); // false
    string a2("aabcc"), b2("dbbca"), c2("aadbbcbcac"); // true
    string a3(""), b3(""), c3(""); // true
    string a4("aaa"), b4("bb"), c4("abbaa"); // true

    cout << a0 << " + " << b0 << " = " << c0 << " ? " << solution.isInterleave(a0, b0, c0) << endl;
    cout << a1 << " + " << b1 << " = " << c1 << " ? " << solution.isInterleave(a1, b1, c1) << endl;
    cout << a2 << " + " << b2 << " = " << c2 << " ? " << solution.isInterleave(a2, b2, c2) << endl;
    cout << a3 << " + " << b3 << " = " << c3 << " ? " << solution.isInterleave(a3, b3, c3) << endl;
    cout << a4 << " + " << b4 << " = " << c4 << " ? " << solution.isInterleave(a4, b4, c4) << endl;

    return 0;
}
