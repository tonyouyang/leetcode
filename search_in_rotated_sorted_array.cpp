class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = 0, r = n - 1, m;
        
        while (l <= r)
        {
            m = l + (r - l >> 1);
            if (A[m] == target) return m;
            if (A[m] >= A[l])
            {
                if (A[l] <= target && target < A[m]) r = m - 1;
                else l = m + 1;
            }
            else
            {
                if (A[m] < target && target <= A[r]) l = m + 1;
                else r = m - 1;
            }
        }
        
        return -1;
    }
};
