// Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

// For example,
// Given n = 3, there are a total of 5 unique BST's.

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution
{
public:
    int numTrees(int n)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int c[n + 1];
        memset(c, 0, sizeof(c));

        for (int i = 1; i <= n; ++i)
            for (int r = 1; r <= i; ++r)
                c[i] += max(c[r - 1], 1) * max(c[i - r], 1);

        return c[n];
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	int n;

	cin >> n;
	cout << solution.numTrees(n) << endl;

    return 0;
}
