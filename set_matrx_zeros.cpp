class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (matrx.empty()) return;
        
        int m = matrx.size(), n = matrx[0].size(), r = -1, c = -1;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (!matrix[i][j])
                {
                    if (x == -1)
                    {
                        r = i;
                        c = j;
                    }
                    matrix[r][j] = 0;
                    matrix[i][c] = 0;
                }
                
        if (x == -1)  return;
        
        for (int i = 0; i < m; ++i)
            if (!matrix[i][c] && i != r)
                for (int j = 0; j < n; ++j) matrix[i][j] = 0;
                
        for (int j = 0; j < n; ++j)
            if (!matrix[r][j] && j != c)
                for (int i = 0; i < m; ++i) matrix[i][j] = 0;
                
        for (int j = 0; j < n; ++j) matrix[r][j] = 0;
        for (int i = 0; i < m; ++i) matrix[i][c] = 0;
    }
};
