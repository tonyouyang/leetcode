// Given an array of integers, find two numbers such that they add up to a specific target number.

// The function twoSum should return indices of the two numbers such that they add up to the target,
// where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

// You may assume that each input would have exactly one solution.

// Input: numbers={2, 7, 11, 15}, target=9
// Output: index1=1, index2=2

#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        int len = numbers.size();
        if (len <= 1) return ret;

        map<int, int> complement;

        for (int i = 0; i < len; ++i)
        {
            if (complement.find(numbers[i]) != complement.end())
            {
                int j = complement[numbers[i]];

                if (j < i)
                {
                    ret.push_back(j + 1);
                    ret.push_back(i + 1);
                    return ret;
                }
            }
            else
            {
                complement[target - numbers[i]] = i;
            }
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
