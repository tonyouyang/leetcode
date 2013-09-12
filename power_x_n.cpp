// Implement pow(x, n).

#include <iostream>
#include <limits>
#include <cstdlib>
using namespace std;

class Solution
{
public:
    double pow(double x, int n)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) return 1;
        if (x < 1 + 1e-8 && x > 1 - 1e-8) return 1;
        if (x < -1 + 1e-8 && x > -1 - 1e-8) return n & 1 ? -1 : 1;
        
        int m = abs(n);
        double p = 1;

        for ( ; m; x *= x, m >>= 1)
        {
            if (m & 1) p *= x;
        }

        return n < 0 ? 1 / p : p;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;

    cout << solution.pow(0, 10) << endl;
    cout << solution.pow(0, 0) << endl;
    cout << solution.pow(1, 0) << endl;
    cout << solution.pow(10, 0) << endl;
    cout << solution.pow(-1, 0) << endl;
    cout << solution.pow(1, 100) << endl;
    cout << solution.pow(-1, 100) << endl;
    cout << solution.pow(-1, 101) << endl;
    cout << solution.pow(2, 10) << endl;
    cout << solution.pow(-2, 9) << endl;
    cout << solution.pow(0.2, 10) << endl;
    cout << solution.pow(10, -1) << endl;
    cout << solution.pow(-10, -1) << endl;
    cout << solution.pow(1, -1) << endl;
    cout << solution.pow(-1, -1) << endl;
    // cout << solution.pow(0, -1) << endl;

    return 0;
}
