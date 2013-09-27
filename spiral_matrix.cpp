class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        if (matrix.empty() || matrix[0].empty()) return ret;
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        
        for (int m = matrix[0].size(), n = matrix.size() - 1, i = 0, j = -1, d = 0, count = 0; m > 0; )
        {
            i += dr[d];
            j += dc[d];
            ret.push_back(matrix[i][j]);
            if (++count == m)
            {
                d = d + 1 & 3;
                swap(m, n);
                n--;
                count = 0;
            }
        }
        
        return ret;
    }
};
