class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ret = 0;
        for (int curr = 0, next = 0, i = 0; i <= next && i < n; ++i)
        {
            if (i > curr)
            {
                curr = next;
                ret++;
            }
            next = max(next, i + A[i]);
        }
        return ret;
    }
};
