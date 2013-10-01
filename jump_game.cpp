class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = 0;
        for (int i = 0; i <= m && m < n; ++i) m = max(m, i + A[i]);
        return m >= n - 1;
    }
};
