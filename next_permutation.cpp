class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i, j;
        
        for (i = num.size() - 1; i - 1 >= 0 && num[i] <= num[i - 1]; --i);
        if (i > 0)
        {
            for (j = num.size() - 1; j >= 0 && num[j] <= num[i - 1]; --j);
            swap(num[i - 1], num[j]);
        }
        reverse(num.begin() + i, num.end());
    }
};
