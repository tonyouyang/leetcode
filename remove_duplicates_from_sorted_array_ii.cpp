class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int j = 0;
        
        for (int i = 0; i < n; ++i)
        {
            if (j < 2 || A[j - 2] != A[i]) A[j++] = A[i];
        }
        
        return j;
    }
};
