// Implement int sqrt(int x).

// Compute and return the square root of x.

#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int sqrt(int x)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for (double start = 0, end = (double)x; ; )
        {
            double mid = start + (end - start) / 2, residule = mid * mid - x;

            if (residule > 1e-8)
                end = mid;
            else if (residule < -1e-8)
                start = mid;
            else
            	return (int)(mid + 1e-8); // important to add 1e-8, e.g x = 1

            if (start > end - 1e-8) return (int)(mid + 1e-8);
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
