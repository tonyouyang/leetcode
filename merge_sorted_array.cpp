class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        while (n > 0)
        {
            if (m == 0 || A[m - 1] < B[n - 1]) A[m + n - 1] = B[--n];
            else A[m + n - 1] = A[--m];
        }
    }
};
