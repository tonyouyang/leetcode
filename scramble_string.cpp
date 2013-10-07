class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s1.size() != s2.size()) return false;
        
        int n = s1.size();
        bool f[n][n][n];
        memset(f, false, sizeof(f));
        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                f[i][j][0] = s1[i] == s2[j];
        for (int k = 0; k < n; ++k)
            for (int i = 0; i + k < n; ++i)
                for (int j = 0; j + k < n; ++j)
                    for (int l = 0; l < k; ++l)
                    {
                        f[i][j][k] = f[i][j][k] || 
                            f[i][j][l] && f[i + l + 1][j + l + 1][k - l - 1] || 
                            f[i][j + k - l][l] && f[i + l + 1][j][k - l - 1];
                        if (f[i][j][k]) break;
                    }
                    
        return f[0][0][n - 1];
    }
};

// 3 dim dp
// f[i][j][k] := s1[i:i+k-1] is a scrambled string of s2[j:j+k-1]
// i ... i + l - 1 , i + l ... i + k - 1
// j ... j + l - 1 , j + l ... j + k - 1 (case 1)
// j ... j + k - l - 1 , j + k - l ... j + k - 1 (case 2)
