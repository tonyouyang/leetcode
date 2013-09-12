// Implement int sqrt(int x).

// Compute and return the square root of x.

#include <iostream>
#include <algorithm>
#include <limits>
#include <cmath>
using namespace std;

class Solution
{
public:
    int sqrt(int x)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for (int start = 0, end = min(x, (int)std::sqrt(numeric_limits<int>::max())); ; )
        {
            int mid = start + (end - start) / 2, square = mid * mid;

            if (square > x)
                end = mid - 1;
            else if (square < x)
                start = mid + 1;
            else
            	return mid;

            if (start > end) return end + (start - end) / 2;
        }
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;

	cout << solution.sqrt(3) << endl;
	cout << solution.sqrt(2) << endl;
	cout << solution.sqrt(4) << endl;
	cout << solution.sqrt(0) << endl;
	cout << solution.sqrt(1) << endl;
	cout << solution.sqrt(100) << endl;
	cout << solution.sqrt(2147395599) << endl;

    return 0;
}
