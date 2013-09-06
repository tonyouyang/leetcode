// Determine whether an integer is a palindrome. Do this without extra space.

#include <iostream>
using namespace std;

class Solution
{
public:
    bool f(int x, int &y)
    {
        if (x == 0) return true;

        if (f(x / 10, y) && x % 10 == y % 10)
        {
        	y /= 10;
        	return true;
        }
        else
        {
        	return false;
        }
    }

    bool isPalindrome(int x)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x < 0) return false;

        return f(x, x);
    }
};

int main(int argc, char const *argv[])
{
    int x = 0;
    Solution solution;

    cin >> x;
    cout << solution.isPalindrome(x) << endl;

    return 0;
}

// NOTE
// no extra space => recursion
// usage of reference
