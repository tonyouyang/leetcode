class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ret;
        int l = digits.length();
        if (l == 0)
        {
            ret.push_back(""); // NOTICE!
            return ret;
        }
        if (digits.find('1') != string::npos || digits.find('0') != string::npos) return ret;
        
        string letter[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<int> index(l, 0);
        
        for (int m = letter[digits[l - 1] - '0'].length(); index[l - 1] < m; )
        {
            string s;
            for (int i = 0; i < l; ++i) s += letter[digits[i] - '0'][index[i]];
            ret.push_back(s);
            
            ++index[0];
            for (int j = 0; j < l - 1 && index[j] >= letter[digits[j] - '0'].length(); ++j)
            {
                index[j] = 0;
                index[j + 1]++;
            }
        }
        
        return ret;
    }
};
