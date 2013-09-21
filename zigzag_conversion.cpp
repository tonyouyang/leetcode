class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if  (s.length() == 0 || nRows <= 0) return "";
        if (nRows == 1) return s;
        string ret("");
        
        for (int i = 0, m = (nRows << 1) - 2; i < nRows; ++i)
        {
            for (int p = i, q = m - i; p < s.length() || q < s.length(); p += m, q += m) 
            {
                if (p < s.length()) ret += s[p];
                if (p != q && i != 0 && q < s.length()) ret += s[q];
            }
        }
        
        return ret;
    }
};
