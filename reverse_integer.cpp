// Reverse digits of an integer.

// Example1: x = 123, return 321
// Example2: x = -123, return -321

#include <iostream>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int r = 0, d = 0;

        while (x)
        {
            d = x % 10;
            r = r * 10 + d;
            x /= 10;
        }

        return r;
    }
};

int main(int argc, char const *argv[])
{
    int x;
    Solution solution;

    cin >> x;
    cout << solution.reverse(x) << endl;
    return 0;
}
