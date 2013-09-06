// Given an array of integers, find two numbers such that they add up to a specific target number.

// The function twoSum should return indices of the two numbers such that they add up to the target,
// where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

// You may assume that each input would have exactly one solution.

// Input: numbers={2, 7, 11, 15}, target=9
// Output: index1=1, index2=2

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> r(2);

        for (int i = 0, len = numbers.size(); i < len - 1; ++i)
        {
            for (int j = i + 1; j < len; ++j)
            {
                if (numbers[i] + numbers[j] == target)
                {
                    r[0] = i + 1;
                    r[1] = j + 1;
                    return r;
                }
            }
        }
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
