// The gray code is a binary numeral system where two successive values differ in only one bit.

// Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

// For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

// 00 - 0
// 01 - 1
// 11 - 3
// 10 - 2
// Note:
// For a given n, a gray code sequence is not uniquely defined.

// For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

// For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> grayCode(int n)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> a((1 << n), 0);

        for (int i = 1, j = 1; i <= n; ++i, j = j << 1)
        {
            if (i > 1)
            {
                copy(a.begin(), a.begin() + j, a.begin() + j);
                reverse(a.begin() + j, a.begin() + (j << 1));
            }
            for (int k = j, l = (j << 1); k < l; ++k) a[k] |= j;
        }

        return a;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n;

    cin >> n;
    vector<int> gc = solution.grayCode(n);
    for (int i = 0, l = gc.size(); i < l; ++i) cout << gc[i] << " ";
    cout << endl;

    return 0;
}
