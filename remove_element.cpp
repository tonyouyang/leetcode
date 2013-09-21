class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) return 0;
        int i = 0, j = n - 1;
        
        while (i <= j)
        {
            if (A[j] == elem)
            {
                j--;
            }
            else if (A[i] != elem)
            {
                i++;
            }
            else
            {
                A[i++] = A[j--];
            }
        }
        
        return i;
    }
};
