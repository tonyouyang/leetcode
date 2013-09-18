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
        vector<vector<int> > tuples;
        int len = num.size();
        if (len < 3) return tuples;
        
        sort(num.begin(), num.end());
        for (int i = 0; i < len - 2; ++i)
        {
            int sum = -num[i];
            int j = i + 1, k = len - 1;
            
            while (j < k)
            {
                if (num[j] + num[k] > sum)
                {
                    k--;
                }
                else if (num[j] + num[k] < sum)
                {
                    j++;
                }
                else
                {
                    vector<int> tuple;
                    tuple.push_back(num[i]);
                    tuple.push_back(num[j]);
                    tuple.push_back(num[k]);
                    tuples.push_back(tuple);
                    j++;
                    k--;
                    while (num[j - 1] == num[j] && j < k) j++;
                    while (num[k] == num[k + 1] && j < k) k++;
                }
            }
            while (i + 1 < len - 2 && num[i] == num[i + 1]) i++;
        }
        
        return tuples;
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
