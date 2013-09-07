// Given numRows, generate the first numRows of Pascal's triangle.

// For example, given numRows = 5,
// Return

// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int> > generate(int numRows)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > tri;

        for (int i = 0; i < numRows; ++i)
        {
            vector<int> curr; // current row

            curr.push_back(1);
            for (int j = 1; j < i; ++j)
            {
                curr.push_back(tri[i - 1][j - 1] + tri[i - 1][j]);
            }
            if (i > 0)
            {
                curr.push_back(1);
            }

            tri.push_back(curr);
        }

        return tri;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int numRows;

    cin >> numRows;
    vector<vector<int> > tri = solution.generate(numRows);
    for (int i = 0, l = tri.size(); i < l; ++i)
    {
        for (int j = 0, m = tri[i].size(); j < m; ++j)
        {
            cout << tri[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}