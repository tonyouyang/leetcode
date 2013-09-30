#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = num1.size(), n = num2.size(), l = 1, k, r, s;
        string ret(m + n, '0');
        
        for (int j = n - 1; j >= 0; --j)
        {
            k = n - j - 1;
            
            for (int i = m - 1, c = 0, sc = 0; i >= 0 || c > 0 || sc > 0; --i, ++k)
            {
                r = i >= 0 ? (num1[i] - '0') * (num2[j] - '0') + c : c;
                s = (ret[k] - '0') + (r % 10) + sc;
                ret[k] = (s % 10) + '0';
                sc = s / 10;
                c = r / 10;
            }
            
            l = max(l, k);
        }
        
        while (l > 1 && ret[l - 1] == '0') l--;
        ret.resize(l);
        reverse(ret.begin(), ret.end());
        
        return ret;
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	string num1, num2;

	cin >> num1 >> num2;
	cout << solution.multiply(num1, num2) << endl;

	return 0;
}
