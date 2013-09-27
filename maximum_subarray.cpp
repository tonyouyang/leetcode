class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!n) return 0;
        
        int a = A[0], b = a;
        for (int i = 1; i < n; ++i)
        {
        	b = max(a, b);
        	a = max(A[i], a + A[i]);
        }
        
        return max(a, b);
    }
};
