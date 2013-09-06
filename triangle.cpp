// Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

// For example, given the following triangle

// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

// Note:
// Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>
// #include <stdio.h>
using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int> > &triangle)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!triangle.size()) return 0;

        vector<int> score(triangle.size(), 0);
        int score_min = numeric_limits<int>::max();

        for (vector<vector<int> >::iterator r = triangle.begin(); r != triangle.end(); ++r)
        {
            for (int len = r->size(), i = len - 1; i >= 0; --i)
            {
                int ls = (*r)[i], rs = ls;

                if (i > 0) ls += score[i - 1];
                if (i < len - 1) rs += score[i];

                if (i == len - 1)
                {
                    score[i] = ls;
                }
                else if (i == 0)
                {
                    score[i] = rs;
                }
                else
                {
                    score[i] = ls > rs ? rs : ls;
                }
            }
        }

        for(vector<int>::size_type i = 0, len = score.size(); i < len; ++i)
        {
            if (score_min > score[i]) score_min = score[i];
        }
        // cout << score_min << endl;
        return score_min;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int> > tri;
    string line("");

    while (getline(cin, line))
    {
        if (line.find_last_not_of(" \n\r\t") != string::npos)
        {
            istringstream iss(line);
            int num;
            vector<int> row;

            while (iss >> num)
            {
                row.push_back(num);
            }

            // cout << "size=" << (int)row.size() << endl;
            tri.push_back(row);
        }
    }

    solution.minimumTotal(tri);

    return 0;
}
