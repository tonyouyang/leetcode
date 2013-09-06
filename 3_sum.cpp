// Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
// Find all unique triplets in the array which gives the sum of zero.

// Note:

// Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ? b ? c)
// The solution set must not contain duplicate triplets.
//     For example, given array S = {-1 0 1 2 -1 -4},

//     A solution set is:
//     (-1, 0, 1)
//     (-1, -1, 2)

#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        // sort
        sort(num.begin(), num.end());

    	// find tuples
    	set<vector<int> > tuples;

    	for (int i = 0, len = num.size(); i < len - 2; ++i)
    	{
    		int j = i + 1;
    		int k = len - 1;

    		while (j < k)
    		{
    			int sum2 = num[i] + num[j];
    			if (sum2 + num[k] > 0)
    			{
    				k--;
    			}
    			else if (sum2 + num[k] < 0)
    			{
    				j++;
    			}
    			else
    			{
    				vector<int> t(3);
    				t[0] = num[i];
    				t[1] = num[j];
    				t[2] = num[k];
    				tuples.insert(t);
    				j++;
    				k--;
    			}
    		}
    	}

    	return vector<vector<int> >(tuples.begin(), tuples.end());
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	int n;
	vector<int> v;

	while (cin >> n)
	{
		v.push_back(n);
	}
	cout << solution.threeSum(v).size() << endl;

	return 0;
}
