class Solution {
public:
    int searchInsert(int A[], int start, int end, int target)
    {
        if (start == end) return target > A[start] ? start + 1 : start;
        int mid = start + (end - start >> 1);
        
        if (A[mid] > target) return searchInsert(A, start, max(start, mid - 1), target);
        else if (A[mid] < target) return searchInsert(A, mid + 1, end, target);
        else return mid;
    }
    
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!n) return 0;
        return searchInsert(A, 0, n - 1, target);
    }
};
