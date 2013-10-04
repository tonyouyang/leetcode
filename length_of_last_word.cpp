class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ret = 0, i = 0, j = 0;
        
        for (const char *c = s; *c; ++c, ++j)
        {
            if (*c == ' ')
            {
                if (i != j) ret = j - i;
                i = j + 1;
            }
        }
        if (i != j) ret = j - i;
        
        return ret;
    }
};
