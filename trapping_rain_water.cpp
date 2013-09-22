class Solution {
public:
    int trap(int A[], int n, int right)
    {
        int ret = 0;
        
        for (int i = n - 1; i >= 0; --i)
        {
            right = max(right, A[i]);
            ret +=  right - A[i];
        }
        
        return ret;
    }
    
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ret = 0, l = 0;
        
        for (int i = 1; i < n; ++i)
        {
            if (A[i] >= A[l])
            {
                ret += trap(A + l, i - l, A[l]);
                l = i;
            }
        }
        ret += trap(A + l, n - l, 0);
        
        return ret;
    }
};
