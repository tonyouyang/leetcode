class Solution {
public:
    // bool isScramble(string s1, string s2) {
    //     // Start typing your C/C++ solution below
    //     // DO NOT write int main() function
    //     if (s1.size() != s2.size()) return false;
        
    //     int n = s1.size();
    //     bool f[n][n][n];
    //     memset(f, false, sizeof(f));
        
    //     for (int i = 0; i < n; ++i)
    //         for (int j = 0; j < n; ++j)
    //             f[i][j][0] = s1[i] == s2[j];
    //     for (int k = 0; k < n; ++k)
    //         for (int i = 0; i + k < n; ++i)
    //             for (int j = 0; j + k < n; ++j)
    //                 for (int l = 0; l < k; ++l)
    //                 {
    //                     f[i][j][k] = f[i][j][k] || 
    //                         f[i][j][l] && f[i + l + 1][j + l + 1][k - l - 1] || 
    //                         f[i][j + k - l][l] && f[i + l + 1][j][k - l - 1];
    //                     if (f[i][j][k]) break;
    //                 }
                    
    //     return f[0][0][n - 1];
    // }
    
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        int n = s1.size();
        
        // end of recursion
        if (n == 1) return s1[0] == s2[0];
        
        // redundant
        vector<int> c(26, 0);
        for (int i = 0; i < n; ++i)
        {
            c[s1[i] - 'a']++;
            c[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; ++i) if (c[i]) return false;
        
        // recursion
        for (int i = 1; i < n; ++i)
        {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) return true;
            if (isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i, n - i), s2.substr(0, n - i))) return true;
        }
        
        return false;
    }
};

// 3 dim dp
// f[i][j][k] := s1[i:i+k-1] is a scrambled string of s2[j:j+k-1]
// i ... i + l - 1 , i + l ... i + k - 1
// j ... j + l - 1 , j + l ... j + k - 1 (case 1)
// j ... j + k - l - 1 , j + k - l ... j + k - 1 (case 2)

// recursion with redundant(character count)
