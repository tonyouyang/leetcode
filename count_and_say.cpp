class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) return "";
        
        string s("1");
        for (int i = 1; i < n; ++i)
        {
            string t("");
            for (int j = 0, k = 0; k < s.size(); ++k)
            {
                if (k == s.size() - 1 || s[k] != s[k + 1])
                {
                    t += to_string(k - j + 1) + s[k];
                    j = k + 1;
                }
            }
            s = t;
        }
        
        return s;
    }
};
