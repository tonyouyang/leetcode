class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for (int i = 0; i < n; ++i)
            for ( ; A[i] != i + 1 && A[i] > 0 && A[i] <= n && A[i] != A[A[i] - 1]; swap(A[i], A[A[i] - 1]));
            
        for (int i = 0; i < n; ++i)
            if (A[i] != i + 1) return i + 1;
            
        return n + 1;
    }
};
