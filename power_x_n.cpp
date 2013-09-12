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
        if (n == 1) return x;
        if (x < 1e-8 && x > -1e-8) return n > 0 ? 0 : numeric_limits<double>::max();
        if (x < 1 + 1e-8 && x > 1 - 1e-8) return 1;
        if (x < -1 + 1e-8 && x > -1 - 1e-8) return n & 1 ? -1 : 1;
        if (n == -1) return 1 / x;

        int m = abs(n);
        double p = m & 1 ? x : 1, t = x;

        do
        {
            m = m >> 1;
            t *= t;
            if (m & 1) p *= t;
        }
        while (m);

        return n > 0 ? p : 1 / p;
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
    cout << solution.pow(0, -1) << endl;

    return 0;
}
