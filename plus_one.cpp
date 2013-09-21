class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        if  (digits.size() == 0) return ret;
        
        digits[digits.size() - 1] += 1;
        int carry, i, j;
        for (j = 0; j < digits.size() && digits[j] == 0; ++j);
        
        for (i = digits.size() - 1, j = max(0, j - 1), carry = 0; i >= j; --i)
        {
            ret.push_back((digits[i] + carry) % 10);
            carry = (digits[i] + carry) / 10;
        }
        for ( ; carry > 0; carry /= 10) ret.push_back(carry % 10);
        reverse(ret.begin(), ret.end());
        
        return ret;
    }
};
