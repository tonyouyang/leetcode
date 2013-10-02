class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (n == 0) return 0;
        for (int i = 1; i < n; ++i) A[0] ^= A[i];
        return A[0];
    }
};

// 2 2 3 3 x 4 4
// 2 3 4 4 3 2 x x x

// 2 ^ 2
// 1 0
// 1 0
// 0 0
// 1 1
// 1 1

// 0 0 0
// 1 0 0

