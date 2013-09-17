// Write a function to find the longest common prefix string amongst an array of strings.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ns = strs.size();
        if (ns == 0) return "";
        if (ns == 1) return strs[0];

        int i = 0;
        sort(strs.begin(), strs.end());
        for (int l = min(strs[0].length(), strs[ns - 1].length()); i < l && strs[0][i] == strs[ns - 1][i]; ++i);
        return strs[0].substr(0, i);
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<string> a(2); a[0] = "aaa"; a[1] = "aa";
    vector<string> b(2); b[0] = "aaa"; b[1] = "";
    vector<string> c(4); c[1] = "aaab"; c[0] = "aaac"; c[3] = "aad"; c[2] = "ae";

    cout << solution.longestCommonPrefix(a) << endl;
    cout << solution.longestCommonPrefix(b) << endl;
    cout << solution.longestCommonPrefix(c) << endl;

    return 0;
}
