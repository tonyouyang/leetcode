class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int one = 0, two = 0, tmp;
        
        for (int i = 0; i < n; ++i)
        {
            tmp = one;
            one = (~two) & (one ^ A[i]);
            two = (tmp & A[i]) | (two & ~A[i]);
        }
        
        return one;
    }
};
