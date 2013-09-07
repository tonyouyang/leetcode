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

// suggest solution
class Solution {
public:

    vector<int> getElements(int x)
    {
        vector<int> ret;
        while (x > 0) 
        {
            ret.push_back(x % 10);
            x /= 10;
        }
        return ret;
    }
    
    bool isPalind(const vector<int>& vs)
    {
        int i = 0, j = (int) vs.size() - 1;
        while (i < j)
        {
            if (vs[i] != vs[j]) return false;
            i++; j--;
        }
        return true;
    }
    
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x < 0) return false; 
        else return isPalind(getElements(x));
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
