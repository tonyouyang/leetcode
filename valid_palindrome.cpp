// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

// For example,
// "A man, a plan, a canal: Panama" is a palindrome.
// "race a car" is not a palindrome.

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for (int len = s.length(), i = 0, j = len - 1; i < j; )
        {
            if (isalnum(s[i]) && isalnum(s[j]))
            {
                if (tolower(s[i]) != tolower(s[j]))
                {
                    return false;
                }
                else
                {
                    i++;
                    j--;
                }
            }
            else if (!isalnum(s[i]))
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string str("");

    cin >> str;
    cout << solution.isPalindrome(str) << endl;

    return 0;
}