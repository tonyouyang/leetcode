class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int a = 0, b = 1, c = 0;
        for (int i = 0; i < n; ++i, c = a + b, a = b, b = c);
        return c;
    }
};
