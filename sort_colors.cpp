class Solution {
public:
    void sortColors(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int end[] = {-1, -1, -1};
        
        for (int i = 0, t = 0; i < n; ++i)
        {
            t = A[i];
            for (int j = i; j > end[t] + 1; --j) A[j] = A[j - 1];
            for (int j = 2; j >= t; --j) end[j]++;
            A[end[t]] = t;
        }
    }
};
