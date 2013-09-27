class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) return vector<vector<int> > ();
        
        int delta[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int> > ret = vector<vector<int> > (n, vector<int> (n));
        
        for (int i = 0, j = -1, k = 1, d = 0, c = 0, m = n, v = 0; m > 0; )
        {
            i += delta[d][0];
            j += delta[d][1];
            ret[i][j] = ++v;
            if (++c == m)
            {
                d = d + 1 & 3;
                c = 0;
                if (--k == 0)
                {
                    m--;
                    k = 2;
                }
            }
        }
        
        return ret;
    }
};
