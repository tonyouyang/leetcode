class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Note: The Solution object is instantiated only once and is reused by each test case.    
        if (!*p) return !*s;
        
        if (*(p + 1) != '*') return (*p == *s || *p == '.' && *s) && isMatch(s + 1, p + 1);

        while (*p == *s || *p == '.' && *s)
        {
            if (isMatch(s, p + 2)) return true;
            s++;
        }
        return isMatch(s, p + 2);
    }
};

// \0 == \0
// . == [!\0]
// ? == ?
// .*
// ?*
