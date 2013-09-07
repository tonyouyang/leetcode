// Given an index k, return the kth row of the Pascal's triangle.

// For example, given k = 3,
// Return [1,3,3,1].

// Note:
// Could you optimize your algorithm to use only O(k) extra space?

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> row(rowIndex + 1);

        for (int i = 0; i <= rowIndex; ++i)
        {
        	row[i] = 1;
        	for (int j = i - 1; j > 0; --j)
        	{
        		row[j] = row[j] + row[j - 1];
        	}
        	row[0] = 1;
        }

        return row;
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	int r;

	cin >> r;
	vector<int> row = solution.getRow(r);
	for (int i = 0, l = row.size(); i < l; ++i)
	{
		cout << row[i] << " ";
	}
	cout << endl;

	return 0;
}
