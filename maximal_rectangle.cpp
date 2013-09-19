class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!matrix.size() || !matrix[0].size()) return 0;
        
        int n = matrix[0].size(), area = 0;
        vector<int> left(n, 0), right(n, n - 1), top(n, 0);
        
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0, left_zero_index = 0; j < n; ++j)
            {
                if (matrix[i][j] == '1')
                {
                    top[j]++;
                    left[j] = max(left[j], left_zero_index);
                }
                else
                {
                    left_zero_index = j + 1;
                    top[j] = 0;
                    left[j] = 0; // s.t. NOT affect on left[j] of row i + 1
                }
            }
            
            for (int j = n - 1, right_zero_index = n - 1;  j >= 0; --j)
            {
                if (matrix[i][j] == '1')
                {
                    right[j] = min(right[j], right_zero_index);
                    area = max(area, top[j] * (right[j] - left[j] + 1));
                }
                else
                {
                    right_zero_index = j - 1;
                    right[j] = n; // s.t. NOT affect on right[j] of row i + 1
                }
            }
        }
        
        return area;
    }
};
